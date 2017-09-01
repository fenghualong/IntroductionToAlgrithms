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
    //������A[p:r]�У�pΪ��һ��Ԫ���±꣬rΪ���һ��Ԫ���±ꡣ
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
    //�ϲ�������A[p:q]��A[q+1:r]
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
    srand((unsigned int)time(0));//������������ӣ�
    for(i = 0; i < n; i++)
    {
        cp[i] = rand()%100;
    }
    return cp;

}

void quick_sort(int *A, int n, int left, int right)
{
    //��������nΪ����Ԫ�ظ�����left=������߽磬right=�ұ߽�
    int i,j,t;
    if(left < right)
    {
        i = left;
        j = right+1;
        while(1)
        {
            while(i+1<n && A[++i]<A[left]);//���������<����,>����
            while(j-1>-1 && A[--j]>A[left]);//��ǰ������<����,>����
            if(i>=j)break;
            t=A[i],A[i]=A[j],A[j]=t;//����
        }
        t=A[left],A[left]=A[j],A[j]=t;//����
        quick_sort(A,n,left,j-1);//�ؼ�������벿�ֵݹ�
        quick_sort(A,n,j+1,right);//�ؼ������Ұ벿�ֵݹ�
    }
}

