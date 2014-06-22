#include<stdlib.h>
#include<stdio.h>

#define N 10

typedef int data_t;

#define SWAP(a,b) do{typeof(a) tmp;tmp=(a);(a)=(b);(b)=tmp;}while(0);


void sort_insert(data_t arr[],int len);
int search(data_t arr[], int len,data_t data);
void sort_binary(data_t arr[],int len);
void sort_shell(data_t arr[],int len);
void sort_bubble(data_t arr[],int len);
void sort_quick(data_t arr[],int len);
int quick(data_t arr[],int len);
void sort_select(data_t arr[],int len);
