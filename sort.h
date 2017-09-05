#ifndef __SORT_H__
#define __SORT_H__

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define PARENT(i) (i>1)
#define LEFT(i)   (i<1)
#define RIGHT(i)  ((i<1)+1)

///n为数组元素个数
void insertion_sort(int *A, int n);

void value_print(int *a, int n);

void bubble_sort(int *A, int n);
void selection_sort(int *A, int n);
//void merge(int *A, int p, int q, int r);
/**< 在数组A[p:r]中，p为第一个元素下标，r为最后一个元素下标。 */
void merge_sort(int *A, int p, int r);
int *rand_array(int n);
/**< 快速排序，n为数组元素个数，left=数组左边界，right=右边界 */
void quick_sort(int *A, int n, int left, int right);
/**< 堆排序 */
inline int parent_node(int number);
inline int left_child(int number);
inline int right_child(int number);
inline void exchange(int *a, int *b);

typedef struct heap_structure{
    int *data_array;//排序的数组
    int length;     //数组的实际长度
    int heap_size;  //数组的有效长度
}HeapStructure;

///**< 其中i为第几个数，不是下标，具体为下标加一的值。 */
void max_heapify(HeapStructure *A, int i);
void build_max_heap(HeapStructure *A);
void min_heapify(HeapStructure *A, int i);
void build_min_heap(HeapStructure *A);
void heap_sort1(HeapStructure *A);
void heap_sort2(HeapStructure *A);

/**< 优先队列 */
int heap_maximum(HeapStructure A);
int heap_extract_max(HeapStructure *A);
void heap_increase_key(HeapStructure *A, int i, int key);
void max_heap_insert(HeapStructure *A, int key);


#endif // __SORT_H__

