#include"DivideAndConquer.h"

/** 最大子数组问题 */

ThreeNumber find_max_crossing_subarray(int *A, int low, int mid, int high)
{
    //求跨越中点的最大子数组
    int left_sum = A[mid];
    int max_left = mid;
    int sum = A[mid];
    int i;
    for(i = mid-1; i >= low; i--)
    {
        sum = sum + A[i];
        if(sum > left_sum)
        {
            left_sum = sum;
            max_left = i;
        }
    }
    int right_sum = A[mid+1];
    int max_right = mid+1;
    sum = A[mid + 1];
    for(i = mid+2; i <= high; i++)
    {
        sum = sum + A[i];
        if(sum > right_sum)
        {
            right_sum = sum;
            max_right = i;
        }
    }
    ThreeNumber value;
    value.left  = max_left;
    value.right = max_right;
    value.sum   = left_sum + right_sum;
    return value;
}

ThreeNumber find_maximum_subarray(int *A, int low, int high)
{
    ThreeNumber value;
    ThreeNumber left_value;
    ThreeNumber right_value;
    ThreeNumber cross_value;
    int middle;
    if(high == low)
    {
        value.left  = low;
        value.right = high;
        value.sum   = A[low];
        return value;
    }else
    {
        middle = (low + high)/2;
        left_value = find_maximum_subarray(A,low,middle);
        right_value = find_maximum_subarray(A,middle+1,high);
        cross_value = find_max_crossing_subarray(A,low,middle,high);
        if(left_value.sum >= right_value.sum && left_value.sum >= cross_value.sum)
        {
            return left_value;
        }
        else if(right_value.sum >= left_value.sum && right_value.sum >= cross_value.sum)
        {
            return right_value;
        }
        else
        {
            return cross_value;
        }
    }
}
