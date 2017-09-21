#include"DivideAndConquer.h"
#include<stdio.h>
#include<stdlib.h>

/** 最大子数组问题 */

ThreeNumber find_max_crossing_subarray(int *A, int low, int mid, int high)
{
    //求跨越中点的最大子数组
    int left_sum = A[mid];
    int max_left = mid;
    int sum = A[mid];
    int i;
    for(i = mid-1; i >= low; i--)
    {
        sum = sum + A[i];
        if(sum > left_sum)
        {
            left_sum = sum;
            max_left = i;
        }
    }
    int right_sum = A[mid+1];
    int max_right = mid+1;
    sum = A[mid + 1];
    for(i = mid+2; i <= high; i++)
    {
        sum = sum + A[i];
        if(sum > right_sum)
        {
            right_sum = sum;
            max_right = i;
        }
    }
    ThreeNumber value;
    value.left  = max_left;
    value.right = max_right;
    value.sum   = left_sum + right_sum;
    return value;
}

ThreeNumber find_maximum_subarray(int *A, int low, int high)
{
    ThreeNumber value;
    ThreeNumber left_value;
    ThreeNumber right_value;
    ThreeNumber cross_value;
    int middle;
    if(high == low)
    {
        value.left  = low;
        value.right = high;
        value.sum   = A[low];
        return value;
    }else
    {
        middle = (low + high)/2;
        left_value = find_maximum_subarray(A,low,middle);
        right_value = find_maximum_subarray(A,middle+1,high);
        cross_value = find_max_crossing_subarray(A,low,middle,high);
        if(left_value.sum >= right_value.sum && left_value.sum >= cross_value.sum)
        {
            return left_value;
        }
        else if(right_value.sum >= left_value.sum && right_value.sum >= cross_value.sum)
        {
            return right_value;
        }
        else
        {
            return cross_value;
        }
    }
}

/**<矩阵相乘  */
void show(int *A, int n)
{
    int i,j;
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
            printf("%d\t",A[i*n+j]);
        printf("\n");
    }
}

/**< 矩阵相乘的常规算法 */
void square_matrix_multiply(int *A, int *B, int *C, int n)
{
    int i,j,k;
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            C[n*i+j] = 0;
            for(k = 0; k < n; k++)
            {
                C[n*i+j] = C[n*i+j] + A[n*i+k]*B[n*k+j];
            }
        }
    }
}

void square_matrix_multiply_recursive(int *A, int *B, int *C, int n)
{
    //其中n为阶数；
    if(n == 1)
    {
        *C = *A * *B;
    }else
    {
        int *A11 = (int *)malloc(n*n/4*sizeof(int));
        int *A12 = (int *)malloc(n*n/4*sizeof(int));
        int *A21 = (int *)malloc(n*n/4*sizeof(int));
        int *A22 = (int *)malloc(n*n/4*sizeof(int));

        int *B11 = (int *)malloc(n*n/4*sizeof(int));
        int *B12 = (int *)malloc(n*n/4*sizeof(int));
        int *B21 = (int *)malloc(n*n/4*sizeof(int));
        int *B22 = (int *)malloc(n*n/4*sizeof(int));

        int *C11 = (int *)malloc(n*n/4*sizeof(int));
        int *C12 = (int *)malloc(n*n/4*sizeof(int));
        int *C21 = (int *)malloc(n*n/4*sizeof(int));
        int *C22 = (int *)malloc(n*n/4*sizeof(int));

        int *S1  = (int *)malloc(n*n/4*sizeof(int));
        int *S2  = (int *)malloc(n*n/4*sizeof(int));
        int *S3  = (int *)malloc(n*n/4*sizeof(int));
        int *S4  = (int *)malloc(n*n/4*sizeof(int));
        int *S5  = (int *)malloc(n*n/4*sizeof(int));
        int *S6  = (int *)malloc(n*n/4*sizeof(int));
        int *S7  = (int *)malloc(n*n/4*sizeof(int));
        int *S8  = (int *)malloc(n*n/4*sizeof(int));
        int *S9  = (int *)malloc(n*n/4*sizeof(int));
        int *S10 = (int *)malloc(n*n/4*sizeof(int));

        int *P1  = (int *)malloc(n*n/4*sizeof(int));
        int *P2  = (int *)malloc(n*n/4*sizeof(int));
        int *P3  = (int *)malloc(n*n/4*sizeof(int));
        int *P4  = (int *)malloc(n*n/4*sizeof(int));
        int *P5  = (int *)malloc(n*n/4*sizeof(int));
        int *P6  = (int *)malloc(n*n/4*sizeof(int));
        int *P7  = (int *)malloc(n*n/4*sizeof(int));

        matrix_divide(A,A11,A12,A21,A22,n);
        matrix_divide(B,B11,B12,B21,B22,n);

        matrix_minus(B12,B22,S1,n/2);
        matrix_add(A11,A12,S2,n/2);
        matrix_add(A21,A22,S3,n/2);
        matrix_minus(B21,B11,S4,n/2);
        matrix_add(A11,A22,S5,n/2);
        matrix_add(B11,B22,S6,n/2);
        matrix_minus(A12,A22,S7,n/2);
        matrix_add(B21,B22,S8,n/2);
        matrix_minus(A11,A21,S9,n/2);
        matrix_add(B11,B12,S10,n/2);

        square_matrix_multiply_recursive(A11,S1,P1,n/2);
        square_matrix_multiply_recursive(S2,B22,P2,n/2);
        square_matrix_multiply_recursive(S3,B11,P3,n/2);
        square_matrix_multiply_recursive(A22,S4,P4,n/2);
        square_matrix_multiply_recursive(S5,S6,P5,n/2);
        square_matrix_multiply_recursive(S7,S8,P6,n/2);
        square_matrix_multiply_recursive(S9,S10,P7,n/2);

        matrix_add(P5,P4,C11,n/2);//C11=P5+P4-P2+P6
        matrix_minus(C11,P2,C11,n/2);
        matrix_add(C11,P6,C11,n/2);
        matrix_add(P1,P2,C12,n/2);//C12=P1+P2;
        matrix_add(P3,P4,C21,n/2);//C21=P3+P4;
        matrix_add(P5,P1,C22,n/2);//C22=P5+P1-P3-P7;
        matrix_minus(C22,P3,C22,n/2);
        matrix_minus(C22,P7,C22,n/2);
        matrix_merge(C, C11, C12, C21, C22, n);

        //show(C, n);
        //printf("c:\n");

        free(A11),free(A12),free(A21),free(A22);
        free(B11),free(B12),free(B21),free(B22);
        free(C11),free(C12),free(C21),free(C22);
        free(S1),free(S2),free(S3),free(S4),free(S5),free(S6),free(S7),free(S8),free(S9),free(S10);
        free(P1),free(P2),free(P3),free(P4),free(P5),free(P6),free(P7);
    }

}

/**< 将一个2n*2n的矩阵分解成四个n*n的矩阵 */
void matrix_divide(int *A, int *A11, int *A12, int *A21, int *A22,int n)
{
    int i,j,k,l;
    if(n == 2)
    {
        *A11 = *A++;
        *A12 = *A++;
        *A21 = *A++;
        *A22 = *A;
    }else
    {
        for(j = 0; j < n/2; j++)//A11
        {
            for(i = 0; i < n/2; i++)
            {
                A11[i+j*(n/2)] = A[j*4+i];
            }
        }

        for(j = 0; j < n/2; j++)//A12
        {
            for(i = n/2,k = 0; i < n; i++,k++)
            {
                A12[k+j*(n/2)] = A[j*4+i];
            }
        }

        for(j = n/2,k = 0; j < n; j++, k++)//A21
        {
            for(i = 0; i < n/2; i++)
            {
                A21[i+k*(n/2)] = A[j*4+i];
            }
        }

        for(j = n/2, k = 0; j < n; j++, k++)//A22
        {
            for(i = n/2,l = 0; i < n; i++,l++)
            {
                A22[l+k*(n/2)] = A[j*4+i];
            }
        }
    }

}

/**< 将四个n*n的矩阵合并成一个2n*2n的矩阵 */
void matrix_merge(int *A, int *A11, int *A12, int *A21, int *A22,int n)
{
    int i,j,k,l;
    if(n == 2)
    {
        *A++ = *A11;
        *A++ = *A12;
        *A++ = *A21;
        *A   = *A22;
    }else
    {
        for(j = 0; j < n/2; j++)//A11
        {
            for(i = 0; i < n/2; i++)
            {
                A[j*4+i] = A11[i+j*(n/2)];
            }
        }

        for(j = 0; j < n/2; j++)//A12
        {
            for(i = n/2,k = 0; i < n; i++,k++)
            {
                A[j*4+i] = A12[k+j*(n/2)];
            }
        }

        for(j = n/2,k = 0; j < n; j++, k++)//A21
        {
            for(i = 0; i < n/2; i++)
            {
                A[j*4+i] = A21[i+k*(n/2)];
            }
        }

        for(j = n/2, k = 0; j < n; j++, k++)//A22
        {
            for(i = n/2,l = 0; i < n; i++,l++)
            {
                A[j*4+i] = A22[l+k*(n/2)];
            }
        }
    }

}

/**< n阶矩阵相加 C=A+B */
void matrix_add(int *A, int *B, int *C, int n)
{
    int sum = n*n;;
    while(sum--)
    {
        *C++ = *A++ + *B++;
    }
}

/**< n阶矩阵相减 C=A-B */
void matrix_minus(int *A, int *B, int *C, int n)
{
    int sum = n*n;;
    while(sum--)
    {
        *C++ = *A++ - *B++;
    }
}

/********************************************//**
 * \brief 用于该int型的二进制表现形式
 *
 * \param int number 需要显示的int型数
 * \param int sum_bit 需要显示的位数
 * \return
 *
 ***********************************************/
void show_bit(int number, int sum_bit)
{
    int num;
    if(sum_bit-- != 1)
    {
        num = number >> 1;
        show_bit(num,sum_bit);
    }
    printf("%d",number&0x1);
}
