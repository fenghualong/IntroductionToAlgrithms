#include"sort.h"
void insertion_sort(int *A, int n)
{
    int i, j;
    int key;
    for(j = 1; j < n; j++)
    {
        i = j - 1;
        key = A[j];
        while(i >= 0 && A[i] > key)
        {
            A[i+1] = A[i];
            i--;
        }
        A[i + 1]   = key;
    }
}

void value_print(int *a, int n)
{
    int i;
    for(i = 0; i < n; i++)
    {
        printf("%d ",a[i]);
    }
    printf("\n");
}

void bubble_sort(int *A, int n)
{
    int i,j;
    int temporary;
    for(i = 0; i < n - 1; i++)
    {
        for(j = 0; j < n-1-i; j++)
        {
            if(A[j] < A[j+1])
            {
                temporary = A[j];
                A[j]      = A[j + 1];
                A[j + 1]      = temporary;
            }
        }
    }
}

void selection_sort(int *A, int n)
{
    int i,j,k;
    int temporary;
    for(i = 0; i < n-1; i++)
    {
        k = i;
        for(j = i; j < n; j++)
        {
            if(A[k] > A[j])k=j;
        }
        if(i != k)
        {
            temporary = A[i];
            A[i]      = A[k];
            A[k]      = temporary;
        }
    }
}

void merge_sort(int *A, int p, int r)
{
    //在数组A[p:r]中，p为第一个元素下标，r为最后一个元素下标。
    int middle;
    if(p < r)
    {
        middle = (p + r)/ 2;
        merge_sort(A,p,middle);
        merge_sort(A,middle+1,r);
        merge(A,p,middle,r);
    }

}

void merge(int *A, int p, int q, int r)
{
    //p<=q<r
    //合并子数组A[p:q]和A[q+1:r]
    int i,j,k;
    int length1;
    int length2;
    int *A1;
    int *A2;
    length1 = q - p + 1;
    length2 = r - q;
    A1 = (int *)malloc((length1) * sizeof(int));
    A2 = (int *)malloc((length2)* sizeof(int));
    for(i = 0; i < length1; i++)
    {
        A1[i] = A[p + i];
    }
    for(j = 0; j < length2; j++)
    {
        A2[j] = A[q + 1 + j];
    }
    i=j=0;
    k = p;
    while(i < length1 && j < length2)
    {
        if(A1[i] > A2[j])
        {
            A[k] = A1[i];
            i++;
        }else
        {
            A[k] = A2[j];
            j++;
        }
        k++;
    }
    while(i < length1)
    {
        A[k] = A1[i];
        i++;
        k++;
    }
    while(j < length2)
    {
        A[k] = A2[j];
        j++;
        k++;
    }
    free(A1);
    free(A2);
}

int *rand_array(int n)
{
    int *cp;
    int i;
    cp = (int *)malloc(n * sizeof(int));
    srand((unsigned int)time(0));//设置随机数种子；
    for(i = 0; i < n; i++)
    {
        cp[i] = rand()%100;
    }
    return cp;

}

void quick_sort(int *A, int n, int left, int right)
{
    //快速排序，n为数组元素个数，left=数组左边界，right=右边界
    int i,j,t;
    if(left < right)
    {
        i = left;
        j = right+1;
        while(1)
        {
            while(i+1<n && A[++i]<A[left]);//向后搜索，<升序,>降序
            while(j-1>-1 && A[--j]>A[left]);//向前搜索，<升序,>降序
            if(i>=j)break;
            t=A[i],A[i]=A[j],A[j]=t;//交换
        }
        t=A[left],A[left]=A[j],A[j]=t;//交换
        quick_sort(A,n,left,j-1);//关键数据左半部分递归
        quick_sort(A,n,j+1,right);//关键数据右半部分递归
    }
}

