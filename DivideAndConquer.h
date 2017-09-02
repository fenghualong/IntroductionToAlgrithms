#ifndef __DIVIDE_AND_CONQUER_H__
#define __DIVIDE_AND_CONQUER_H__

typedef struct threeNumber{
    int left;
    int right;
    int sum;
}ThreeNumber;

ThreeNumber find_max_crossing_subarray(int *A, int low, int mid, int high);

/** \brief �������������
 *
 * \param A ��������A�����������
 * \param low,high�ֱ�Ϊ����A����С������������
 * \return �������������ĺͣ��������������С������������
 *
 */
ThreeNumber find_maximum_subarray(int *A, int low, int high);


/**< ע�⣬���¾����Ϊ������ */
void show(int *A, int n);//nΪn�׾���
void square_matrix_multiply(int *A, int *B, int *C, int n);

/** \brief ��һ������ֽ���ĸ�n/2 * n/2���Ӿ�����A=[A11,A12;A21,A22]
 *
 * \param A ���ֽ�ľ���
 * \param A11,A12,A21,A22�ֱ�Ϊ�ֽ���С����
 * \param n Ϊ����A�Ľ���
 * \return void
 *
 */
void matrix_divide(int *A, int *A11, int *A12, int *A21, int *A22,int n);
void matrix_merge(int *A, int *A11, int *A12, int *A21, int *A22,int n);

/** \brief ����n�׾������
 *
 * \param C=A+B
 * \param
 * \return void
 *
 */
void matrix_add(int *A, int *B, int *C, int n);
void matrix_minus(int *A, int *B, int *C, int n);

/** \brief Strassen�㷨
 *
 * \param C = A * B,�������
 * \param nΪ����
 * \return
 *
 */
void square_matrix_multiply_recursive(int *A, int *B, int *C, int n);

#endif // __DIVIDE_AND_CONQUER_H__
