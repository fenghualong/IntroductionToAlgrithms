#ifndef __SORT_H__
#define __SORT_H__

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

//#define PARENT(i) (i>1)
//#define LEFT(i)   (i<1)
//#define RIGHT(i)  ((i<1)+1)

///n为数组元素个数
void insertion_sort(int *A, int n);//插入排序

void value_print(int *a, int n);//

void bubble_sort(int *A, int n);//冒泡排序

void selection_sort(int *A, int n);
//void merge(int *A, int p, int q, int r);
/**< 在数组A[p:r]中，p为第一个元素下标，r为最后一个元素下标。 */
void merge_sort(int *A, int p, int r);

/**< 产生随机数组 */
int *rand_array(int n);

/**< 快速排序，n为数组元素个数，left=数组左边界，right=右边界 */
void quick_sort_not_the_book(int *A, int n, int left, int right);
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
void heap_sort1(HeapStructure *A);//从小到大排序
void heap_sort2(HeapStructure *A);//从大到小排序

/**< 优先队列 */
int heap_maximum(HeapStructure A);
int heap_extract_max(HeapStructure *A);
void heap_increase_key(HeapStructure *A, int i, int key);
void max_heap_insert(HeapStructure *A, int key);

/**< 快速排序 */
void quick_sort(int A[], int p, int r);
inline int partition(int A[], int p, int r);


/** \brief 计数排序
 *  \param 输入数组是A[1:n]
 *  \param 输出数组是B[1:n]
 *  \param n为数组A，B的长度
 *  \param k为大于A,B中元素最大数的数,即输入的数在[0,k]区间上。
 *  \return
 *
 */
void counting_sort(int A[], int B[], int n, int k);

/**< 最大值和最小值 */
int minimum(int *A, int n);
typedef struct min_max{
    int min;
    int max;
}Min_Max;
Min_Max find_min_and_max(int *A, int n);

#endif // __SORT_H__

