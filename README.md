# End-to-end Face Detection and Cast Grouping in Movies Using Erdős–Rényi Clustering

This code computes Rank-1 Count similarity scores between N different face images. 


### Compiling

```
g++ -o run.bin main.cpp Rank1Count.h Rank1Count.cpp
```

## Running the tests
By default, this demo code takes as input the encodings of the first 10 LFW images.
```
AJ_Cook/AJ_Cook_0001.jpg
AJ_Lamas/AJ_Lamas_0001.jpg
Aaron_Eckhart/Aaron_Eckhart_0001.jpg
Aaron_Guiel/Aaron_Guiel_0001.jpg
Aaron_Patterson/Aaron_Patterson_0001.jpg
Aaron_Peirsol/Aaron_Peirsol_0001.jpg
Aaron_Peirsol/Aaron_Peirsol_0002.jpg
Aaron_Peirsol/Aaron_Peirsol_0003.jpg
Aaron_Peirsol/Aaron_Peirsol_0004.jpg
Aaron_Pena/Aaron_Pena_0001.jpg
```

```
$ ./run.bin
-------------------------------------------------
>> fname_testset: data/test.data 
>> fname_refset: data/reference.data 
>> gallerysize: 50 
>> F: 4096 
-------------------------------------------------
>> Test set
	+ file name: data/test.data
	+ N: 10 
>> Reference set
	+ file name: data/reference.data
	+ G: 825 
>> Calling Rank-1 Count...
starting deleteions
accumrnaks
-------------------------------------------------
    0.00   105.25   115.22   147.09   112.25   120.13   135.55   129.49   112.89    69.99 
  103.50     0.00    91.30   115.45    93.21   110.39    95.50    86.18    94.45   127.94 
  112.15    92.20     0.00   133.87    91.05   169.08   130.95   123.41   139.71    93.09 
  145.04   117.64   139.16     0.00    88.69   163.94   167.05   120.04   103.60    98.24 
  113.68    91.35    90.73    90.92     0.00    80.35    92.33    83.61   119.12   101.72 
  122.05   109.23   172.17   160.23    81.34     0.00   416.84   356.11   269.50   109.07 
  136.30    93.44   132.33   167.99    93.20   412.54     0.00   310.86   246.31    85.60 
  134.69    83.49   126.94   122.69    85.54   355.14   309.36     0.00   330.30    98.09 
  112.94    96.35   144.83   102.01   117.35   258.12   246.37   315.12     0.00    93.88 
   68.71   125.34    92.67    95.05   105.43   110.02    81.13    96.28    94.80     0.00 
-------------------------------------------------
```

You can also run the code with the encodings of your own test set 
```
./run.bin {fname_testset} {fname_refset} {fname_output} {gallerySize} {G} {F}
```
where
```
const char *fname_testset="data/test.data"; 	// file name of the test set. a binary file	
const char *fname_refset="data/reference.data"; // file name of the reference set. a binary file 
int gallerySize=50; 							// How large of a gallery to simulate? (default:50)
int F=4096;                                     // feature dimension
```

A binary file can be easily generated from **X**(NxF matrix). Here is a simple code for Matlab users.
```
fid = fopen('data/test.data', 'w');
fwrite(fid, X, 'single');
fclose(fid);
```

## Authors

* [**SouYoung Jin**](https://souyoungjin.com)
* [Hang Su]()
* [Chris Stauffer]()
* [Erik Learned-Miller]() 

## Acknowledgments

This research is based in part upon work supported by the Office of the Director of National Intelligence (ODNI), Intelligence Advanced Research Projects Activity (IARPA) under contract number 2014-14071600010. The views and conclusions contained herein are those of the authors and should not be interpreted as necessarily representing the official policies or endorsements, either expressed or implied, of ODNI, IARPA, or the U.S. Government.  The U.S. Government is authorized to reproduce and distribute reprints for Governmental purpose notwithstanding any copyright annotation thereon.
