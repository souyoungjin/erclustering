#include <iostream>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <vector>
#include <list>
#include "Rank1Count.h"
#include <string>
#include <algorithm>
#include <iterator>
using namespace std;


// Inputs
// @1-  fname_testset
// @2-  fname_refset
// @3-  gallerySize
// @4-  F
int main(int argc, char*argv[]) { 
	FILE *fid;
	
	// Get arguments
	int numArgs=argc-1;
	const char *fname_testset="data/test.data"; 	// file name of the test set. a binary file	[NxF]
	const char *fname_refset="data/reference.data"; // file name of the reference set. a binary file [NxG] 
	int gallerySize=50; 							// How large of a gallery to simulate? (default:50)
	int F=4096; 									// feature dimension
	if (numArgs==5) {
	    fname_testset=argv[1];
	    fname_refset=argv[2]; 
	    gallerySize=atoi(argv[3]);
	    F=atoi(argv[4]);
	} else if (numArgs>0) {
	    printf("Error: input arguments should be {fname_testset} {fname_refset} {fname_output} {gallerySize} {G} {F}.\n");
	    return 0;
	}
	
	printf("-------------------------------------------------\n");
	printf(">> fname_testset: %s \n", fname_testset);
	printf(">> fname_refset: %s \n", fname_refset);
	printf(">> gallerysize: %d \n", gallerySize);
	printf(">> F: %d \n", F);
	printf("-------------------------------------------------\n");
	
	
	
    // Load test set
	if ((fid=fopen(fname_testset,"rb"))==NULL) {
        printf("Error: No file named %s\n",fname_testset);
        return 0;
    }
	fseek(fid,0,SEEK_END);
	int fsize_testset=ftell(fid);
	fclose(fid);
	
	int typeSize_testset=sizeof(float);
	int N=fsize_testset/(F*typeSize_testset);
	
	printf(">> Test set\n");
	printf("	+ file name: %s\n", fname_testset);
	printf("	+ N: %d \n", N);
	
    float **Xtest=new float *[F];
	fid=fopen(fname_testset,"rb");
    for (int i=0; i<F; i++) {
        Xtest[i]=new float[N];
        fread(Xtest[i],typeSize_testset,N,fid);
    }
	
	
	
	// Load reference set.
	if ((fid=fopen(fname_refset,"rb"))==NULL) {
        printf("Error: No file named %s\n",fname_refset);
        return 0;
    }
	fseek(fid,0,SEEK_END);
	int fsize_refset=ftell(fid);
	fclose(fid);
	
	int typeSize_refset=sizeof(float);
	int G=fsize_refset/(F*typeSize_refset);
	
	printf(">> Reference set\n");
	printf("	+ file name: %s\n", fname_refset);
	printf("	+ G: %d \n", G);
	
    float **Xallref=new float *[F]; // loading all reference images
	fid=fopen(fname_refset,"rb");
    for (int i=0; i<F; i++) {
        Xallref[i]=new float[G];
        fread(Xallref[i],typeSize_refset,G,fid);
    }
    
    float **Xref=new float *[F];
    for (int i=0; i<F; i++) {
        Xref[i]=new float[G];
        for (int j=0; j<G; j++) {
            Xref[i][j]=Xallref[i][j];
        }
    }
    delete Xallref;
	
  
  
    // Call Rank-1 Count.
    printf(">> Calling Rank-1 Count...\n");
    int K=200;
    float **joins=Rank1Count(Xtest,Xref,G,N,F,K,gallerySize);
    
    
	printf("-------------------------------------------------\n");
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            printf("%8.2lf ", (float)joins[i][j]);
        }
        printf("\n");
    }
	printf("-------------------------------------------------\n");
}
