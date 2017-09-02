#include<stdio.h>
#include<stdlib.h>

#include"DivideAndConquer.h"

#define N 4

int main()
{
    int A[16] = {1,2,3,4,5,6,7,8,9,0,1,2,3,4,5,6};
    int B[16] = {1,2,3,4,5,6,7,8,9,0,1,2,3,4,5,6};
    int C[16];

    square_matrix_multiply(A, B, C, N);

    show(A, N);
    printf("\n");
    show(B, N);
    printf("\n");
    show(C, N);
    printf("\n");

    int D[16]={0};
    square_matrix_multiply_recursive(A, B, D, N);

    show(A, N);
    printf("\n");
    show(B, N);
    printf("\n");
    show(D, N);
    printf("\n");

    return 0;
}


