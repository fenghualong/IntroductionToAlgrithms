#include"greedy.h"
#include<stdio.h>


/**
*   sΪ��ʼʱ������
*   fΪ����ʱ������
*   kָ��Ҫ����������Sk
*   nΪ�����ģ����s,f�����鳤��
*   return��Sk��һ�������ݻ����
*/
void recursive_activity_selector(int *s, int *f, int *a, int k, int n)
{
    int m;
    m = k + 1;
    while(m < n && s[m] < f[k])
    {
        m++;
    }
    if(m < n)
    {
        a[m] = 1;
        recursive_activity_selector(s, f, a, m, n);
    }
}

void greedy_activity_selector(int *s, int *f, int *a, int n)
{
    a[1] = 1;
    int k = 1;
    int m;
    for(m = 2; m < n; m++)
    {
        if(s[m] >= f[k])
        {
            a[m] = 1;
            k = m;
        }
    }
}

void print_activity_select_result(int *am, int n)
{
    int i;
    for(i = 0; i < n; i++)
    {
        if(am[i] != 0)
        {
            printf("%-4d",i);
        }
    }
    printf("\n");
}

//huffman()
