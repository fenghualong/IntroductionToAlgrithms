#include<stdio.h>
#include<stdlib.h>

#include"DivideAndConquer.h"
#include"sort.h"
#include"BinarySearchTree.h"
#include"dynamic_programming.h"
#include"greedy.h"

#define N 12

int *rightup = "¨I";
int *right = "¡ü";
int *up = "¡û";

int main()
{

    int s[N] = {0,1,3,0,5,3,5,6,8,8,2,12};
    int f[N] = {0,4,5,6,7,9,9,10,11,12,14,16};

    int am[N] = {0};
    recursive_activity_selector(s,f,am,0,N);
    print_activity_select_result(am,N);
    greedy_activity_selector(s, f, am, N);
    print_activity_select_result(am,N);

    value_print(s, 12);
    quick_sort_not_the_book(s, 12, 0, 11);
    value_print(s, 12);
    return 0;
}
