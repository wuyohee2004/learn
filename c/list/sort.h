#include<time.h>
#include<stdlib.h>
#include<stdio.h>
#define N 10
#define SWAP(a,b) do{\
	typeof((a)) tmp;\
	tmp = (a);\
	(a) = (b);\
	(b) = tmp;\
	}while(0)
typedef int data_t;

//void adjust_heap(data_t arr[],int len,int i);
//void sort_heap(data_t arr[],int len);
void merge_re(data_t arr[],int len);
void merge(data_t a1[],int len1,data_t a2[],int len2,data_t arr[]);
void merge_it(data_t arr[],int len);
