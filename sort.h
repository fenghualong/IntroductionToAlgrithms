#ifndef __SORT_H__
#define __SORT_H__

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define PARENT(i) (i>1)
#define LEFT(i)   (i<1)
#define RIGHT(i)  ((i<1)+1)

///nΪ����Ԫ�ظ���
void insertion_sort(int *A, int n);

void value_print(int *a, int n);

void bubble_sort(int *A, int n);
void selection_sort(int *A, int n);
//void merge(int *A, int p, int q, int r);
/**< ������A[p:r]�У�pΪ��һ��Ԫ���±꣬rΪ���һ��Ԫ���±ꡣ */
void merge_sort(int *A, int p, int r);
int *rand_array(int n);
/**< ��������nΪ����Ԫ�ظ�����left=������߽磬right=�ұ߽� */
void quick_sort(int *A, int n, int left, int right);
/**< ������ */
inline int parent_node(int number);
inline int left_child(int number);
inline int right_child(int number);
inline void exchange(int *a, int *b);

typedef struct heap_structure{
    int *data_array;//���������
    int length;     //�����ʵ�ʳ���
    int heap_size;  //�������Ч����
}HeapStructure;

///**< ����iΪ�ڼ������������±꣬����Ϊ�±��һ��ֵ�� */
void max_heapify(HeapStructure *A, int i);
void build_max_heap(HeapStructure *A);
void min_heapify(HeapStructure *A, int i);
void build_min_heap(HeapStructure *A);
void heap_sort1(HeapStructure *A);
void heap_sort2(HeapStructure *A);

/**< ���ȶ��� */
int heap_maximum(HeapStructure A);
int heap_extract_max(HeapStructure *A);
void heap_increase_key(HeapStructure *A, int i, int key);
void max_heap_insert(HeapStructure *A, int key);


#endif // __SORT_H__

