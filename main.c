#include<stdio.h>
#include<stdlib.h>

#include"DivideAndConquer.h"
#include"sort.h"

#define N 11

int main()
{
    //int A[10] = {16,4,10,14,7,9,3,2,8,1};
    //int A[10] = {4,1,3,2,16,9,10,14,8,7};
    //int A[10] = {16,14,10,8,7,9,3,2,8,1};
    //int A[8] = {2,8,7,1,3,5,6,4};
    //int A[8] = {2,5,3,0,2,3,0,3};
    int *A;
    A = rand_array(N);
    //printf("A=%d\n",A);
    //int B[N]={0};
    //printf("B=%d\n",B);
    //printf("B+N-1=%d\n",B+N-1);
    //HeapStructure data={A,N,N};
    //value_print(data.data_array, N);
    value_print(A, N);
    //printf("\n");
    //printf("%d\n",data.heap_size);
    //max_heapify(&data,1);
    //build_max_heap(&data);
    //build_min_heap(&data);
    //heap_sort1(&data);
    //heap_sort2(&data);
    //quick_sort(A, 0, N-1);
    //quick_sort_not_the_book(A, N, 0, N-1);
    //merge_sort(A, 0, N-1);
    //heap_increase_key(&data, 9, 15);
    //build_max_heap(&data);
    //int number = heap_extract_max(&data);
    //counting_sort(A, B, N, 100);
    printf("minimum=%d\n",minimum(A,N));
    Min_Max minmax = find_min_and_max(A,N);
    printf("min=%d,max=%d\n",minmax.min,minmax.max);
    //printf("counting_sort=%d\n",counting_sort);
    //value_print(B, N);
    //printf("A=%d\n",A);
    quick_sort_not_the_book(A, N, 0, N-1);
    //printf("\n");
    value_print(A, N);
    return 0;
}


