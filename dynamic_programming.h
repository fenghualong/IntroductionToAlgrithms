#ifndef __DYNAMIC_PROGRAMMING_H__
#define __DYNAMIC_PROGRAMMING_H__

#include<stdio.h>
#include<stdlib.h>

#include"DivideAndConquer.h"
#include"sort.h"
#include"BinarySearchTree.h"
#include"dynamic_programming.h"

int cut_rod(int *p, int n);
int inline max(int a, int b);
int memoized_cut_rod_aux(int *p, int n, int *r);
int memoized_cut_rod(int *p, int n);
int bottom_up_cut_rod(int *p, int n);
int extended_bottom_up_cut_rod(int *p, int n, int *s);
void print_cut_rod_solution(int *p, int n);

extern int *rightup;
extern int *right;
extern int *up;
void matrix_multiply(int *A,int *B,int *C,int m,int n,int l);
void matrix_chain_order(int *p, int length);
void print_optimal_parens(int *s, int n, int i, int j);
void memoized_matrix_chain(int *p, int length);
int lookup_chain(int *m, int *s, int *p, int i, int j, int value, int n);
void lcs_length(int *x, int m, int *y, int n);//, int *rightup, int *right, int *up);

#endif // __DYNAMIC_PROGRAMMING_H__
