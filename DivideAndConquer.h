#ifndef __DIVIDE_AND_CONQUER_H__
#define __DIVIDE_AND_CONQUER_H__

typedef struct threeNumber{
    int left;
    int right;
    int sum;
}ThreeNumber;

ThreeNumber find_max_crossing_subarray(int *A, int low, int mid, int high);
ThreeNumber find_maximum_subarray(int *A, int low, int high);


#endif // __DIVIDE_AND_CONQUER_H__
