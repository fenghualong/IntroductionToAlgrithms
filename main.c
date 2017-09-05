#include<stdio.h>
#include<stdlib.h>

#include"DivideAndConquer.h"
#include"sort.h"

#define N 10

int main()
{
    //int A[10] = {16,4,10,14,7,9,3,2,8,1};
    int A[10] = {4,1,3,2,16,9,10,14,8,7};
    //int *A;
    //A = rand_array(N);
    HeapStructure data={A,N,N};
    value_print(data.data_array, N);
    //value_print(A, N);
    printf("\n");
    //printf("%d\n",data.heap_size);
    //max_heapify(&data,1);
    //build_max_heap(&data);
    //build_min_heap(&data);
    //heap_sort1(&data);
    //heap_sort2(&data);
    quick_sort(A, N, 0, N-1);
    //merge_sort(A, 0, N-1);

    value_print(A, N);
    return 0;
}


