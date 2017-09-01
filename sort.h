#ifndef __SORT_H__
#define __SORT_H__

#include<stdio.h>
#include<stdlib.h>
#include<time.h>


void insertion_sort(int *A, int n);
void value_print(int *a, int n);
void bubble_sort(int *A, int n);
void selection_sort(int *A, int n);
void merge(int *A, int p, int q, int r);
void merge_sort(int *A, int p, int r);
int *rand_array(int n);
void quick_sort(int *A, int n, int left, int right);

#endif // __SORT_H__

