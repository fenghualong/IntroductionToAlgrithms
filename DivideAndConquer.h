#ifndef __DIVIDE_AND_CONQUER_H__
#define __DIVIDE_AND_CONQUER_H__

typedef struct threeNumber{
    int left;
    int right;
    int sum;
}ThreeNumber;

ThreeNumber find_max_crossing_subarray(int *A, int low, int mid, int high);

/** \brief 最大子数组问题
 *
 * \param A 查找序列A的最大子数组
 * \param low,high分别为数组A的最小坐标和最大坐标
 * \return 返回最大子数组的和，及该子数组的最小坐标和最大坐标
 *
 */
ThreeNumber find_maximum_subarray(int *A, int low, int high);


/**< 注意，以下矩阵皆为方矩阵 */
void show(int *A, int n);//n为n阶矩阵；
void square_matrix_multiply(int *A, int *B, int *C, int n);

/** \brief 将一个矩阵分解成四个n/2 * n/2的子矩阵，例A=[A11,A12;A21,A22]
 *
 * \param A 待分解的矩阵
 * \param A11,A12,A21,A22分别为分解后的小矩阵
 * \param n 为矩阵A的阶数
 * \return void
 *
 */
void matrix_divide(int *A, int *A11, int *A12, int *A21, int *A22,int n);
void matrix_merge(int *A, int *A11, int *A12, int *A21, int *A22,int n);

/** \brief 两个n阶矩阵相加
 *
 * \param C=A+B
 * \param
 * \return void
 *
 */
void matrix_add(int *A, int *B, int *C, int n);
void matrix_minus(int *A, int *B, int *C, int n);

/** \brief Strassen算法
 *
 * \param C = A * B,矩阵相乘
 * \param n为阶数
 * \return
 *
 */
void square_matrix_multiply_recursive(int *A, int *B, int *C, int n);

#endif // __DIVIDE_AND_CONQUER_H__
