#include<stdio.h>
#include<stdlib.h>
#include"DivideAndConquer.h"

#define N 16
int main()
{
    ThreeNumber value;
    int A[16]={13,-3,-25,20,-3,-16,-23,18,20,-7,12,-5,-22,15,-4,7};
    value = find_maximum_subarray(A, 0, 15);
    printf("A[%d:%d]=%d\n",value.left,value.right,value.sum);

    int i,j,k;
    int tem=0;
    int total=0;

    for(i=0;i<N;i++){//从第一个数到最后一个数
        for(j=1;j<=N-i;j++){//j表示j个数相加
            for(k=0;k<j;k++){//实现从第i个数到第i+j个数的连续相加
                tem+=A[i+k];
            }
            if(tem>total)total=tem;
            tem=0;
        }
    }
    printf("%d\n",total);

    return 0;
}
