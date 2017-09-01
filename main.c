#include<stdio.h>
#include<stdlib.h>
#include"sort.h"

#define N 10000

int main()
{
    int *A;
    long timer;
    long timer1;
    long clock1;
    long clock2;
    long difference_timer;
    struct tm *tm_struct;
    char *str;
    A = rand_array(N);
    merge_sort(A,0,N-1);
    //quick_sort(A,N,0,N-1);
    //value_print(A, N);
    printf("A: \n");

    timer = time(NULL);
    clock1 = clock();
    printf("clock: %ld\n",clock1);
    printf("time: %ld\n",timer);
    tm_struct = localtime(&timer);
    printf("%d:%d:%d\n",tm_struct->tm_hour,tm_struct->tm_min,tm_struct->tm_sec);
    str = asctime(tm_struct);
    printf("asctime: %s", str);
    str = ctime(&timer);
    printf("ctime: %s\n", str);
    timer1 = timer;
    clock2 = clock1;


    insertion_sort(A, N);
    //value_print(A, N);
    printf("insertion_sort: \n");
    timer = time(NULL);
    printf("time: %ld\n",timer);
    clock1 = clock();
    printf("clock: %ld\n",clock1);
    printf("difference clock: %ld\n",clock1-clock2);
    clock2 = clock1;
    difference_timer = difftime(timer , timer1);//timer - timer1;
    printf("difference_timer: %ld\n",difference_timer);
    tm_struct = localtime(&difference_timer);
    printf("%d:%d\n",tm_struct->tm_min,tm_struct->tm_sec);
    timer1 = timer;


    bubble_sort(A, N);
    //value_print(A, N);
    printf("bubble_sort: \n");
    printf("insertion_sort: \n");
    timer = time(NULL);
    printf("time: %ld\n",timer);
    clock1 = clock();
    printf("clock: %ld\n",clock1);
    printf("difference clock: %ld\n",clock1-clock2);
    clock2 = clock1;
    difference_timer = difftime(timer , timer1);//timer - timer1;
    printf("difference_timer: %ld\n",difference_timer);
    tm_struct = localtime(&difference_timer);
    printf("%d:%d\n",tm_struct->tm_min,tm_struct->tm_sec);
    timer1 = timer;

    selection_sort(A, N);
    //value_print(A, N);
    printf("selection_sort: \n");
    printf("insertion_sort: \n");
    timer = time(NULL);
    printf("time: %ld\n",timer);
    clock1 = clock();
    printf("clock: %ld\n",clock1);
    printf("difference clock: %ld\n",clock1-clock2);
    clock2 = clock1;
    difference_timer = timer - timer1;;//timer - timer1;
    printf("difference_timer: %ld\n",difference_timer);
    tm_struct = localtime(&difference_timer);
    printf("%d:%d\n",tm_struct->tm_min,tm_struct->tm_sec);
    timer1 = timer;

    merge_sort(A,0,N-1);
    //value_print(A, N);
    printf("merge_sort: \n");
    timer = time(NULL);
    printf("time: %ld\n",timer);
    clock1 = clock();
    printf("clock: %ld\n",clock1);
    printf("difference clock: %ld\n",clock1-clock2);
    difference_timer = timer - timer1;;//timer - timer1;
    printf("difference_timer: %ld\n",difference_timer);
    tm_struct = localtime(&difference_timer);
    printf("%d:%d\n",tm_struct->tm_min,tm_struct->tm_sec);
    timer1 = timer;
    clock2 = clock1;

    quick_sort(A,N,0,N-1);
    //value_print(A, N);
    printf("quick_sort: \n");
    printf("insertion_sort: \n");
    timer = time(NULL);
    printf("time: %ld\n",timer);
    clock1 = clock();
    printf("clock: %ld\n",clock1);
    printf("difference clock: %ld\n",clock1-clock2);
    clock2 = clock1;
    difference_timer = timer - timer1;;//timer - timer1;
    printf("difference_timer: %ld\n",difference_timer);
    tm_struct = localtime(&difference_timer);
    printf("%d:%d\n",tm_struct->tm_min,tm_struct->tm_sec);
    timer1 = timer;
    clock2 = clock1;

    free(A);
    return 0;
}
