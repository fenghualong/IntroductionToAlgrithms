#include"sort.h"

static void merge(int *A, int p, int q, int r);

void insertion_sort(int *A, int n)
{
    int i, j;
    int key;
    for(j = 1; j < n; j++)
    {
        i = j - 1;
        key = A[j];
        while(i >= 0 && A[i] > key)
        {
            A[i+1] = A[i];
            i--;
        }
        A[i + 1]   = key;
    }
}

void value_print(int *a, int n)
{
    int i;
    for(i = 0; i < n; i++)
    {
        printf("%d ",a[i]);
    }
    printf("\n");
}

void bubble_sort(int *A, int n)
{
    int i,j;
    int temporary;
    for(i = 0; i < n - 1; i++)
    {
        for(j = 0; j < n-1-i; j++)
        {
            if(A[j] < A[j+1])
            {
                temporary = A[j];
                A[j]      = A[j + 1];
                A[j + 1]      = temporary;
            }
        }
    }
}

void selection_sort(int *A, int n)
{
    int i,j,k;
    int temporary;
    for(i = 0; i < n-1; i++)
    {
        k = i;
        for(j = i; j < n; j++)
        {
            if(A[k] > A[j])k=j;
        }
        if(i != k)
        {
            temporary = A[i];
            A[i]      = A[k];
            A[k]      = temporary;
        }
    }
}

void merge_sort(int *A, int p, int r)
{
    //在数组A[p:r]中，p为第一个元素下标，r为最后一个元素下标。
    int middle;
    if(p < r)
    {
        middle = (p + r)/ 2;
        merge_sort(A,p,middle);
        merge_sort(A,middle+1,r);
        merge(A,p,middle,r);
    }

}

static void merge(int *A, int p, int q, int r)
{
    //p<=q<r
    //合并子数组A[p:q]和A[q+1:r]
    int i,j,k;
    int length1;
    int length2;
    int *A1;
    int *A2;
    length1 = q - p + 1;
    length2 = r - q;
    A1 = (int *)malloc((length1) * sizeof(int));
    A2 = (int *)malloc((length2)* sizeof(int));
    for(i = 0; i < length1; i++)
    {
        A1[i] = A[p + i];
    }
    for(j = 0; j < length2; j++)
    {
        A2[j] = A[q + 1 + j];
    }
    i=j=0;
    k = p;
    while(i < length1 && j < length2)
    {
        if(A1[i] > A2[j])
        {
            A[k] = A1[i];
            i++;
        }else
        {
            A[k] = A2[j];
            j++;
        }
        k++;
    }
    while(i < length1)
    {
        A[k] = A1[i];
        i++;
        k++;
    }
    while(j < length2)
    {
        A[k] = A2[j];
        j++;
        k++;
    }
    free(A1);
    free(A2);
}

int *rand_array(int n)
{
    int *cp;
    int i;
    cp = (int *)malloc(n * sizeof(int));
    srand((unsigned int)time(0));//设置随机数种子；
    for(i = 0; i < n; i++)
    {
        cp[i] = rand()%100;
    }
    return cp;

}

void quick_sort_not_the_book(int *A, int n, int left, int right)
{
    //快速排序，n为数组元素个数，left=数组左边界，right=右边界
    int i,j,t;
    if(left < right)
    {
        i = left;
        j = right+1;
        while(1)
        {
            while(i+1<n && A[++i]<A[left]);//向后搜索，<升序,>降序
            while(j-1>-1 && A[--j]>A[left]);//向前搜索，<升序,>降序
            if(i>=j)break;
            t=A[i],A[i]=A[j],A[j]=t;//交换
        }
        t=A[left],A[left]=A[j],A[j]=t;//交换
        quick_sort_not_the_book(A,n,left,j-1);//关键数据左半部分递归
        quick_sort_not_the_book(A,n,j+1,right);//关键数据右半部分递归
    }
}

/**< 以下为堆排序所需的函数 */
//给定一个节点的下标i,我们很容易计算出它的父节点、左孩子和右孩子的下标。
inline int parent_node(int number)
{
    return number>>1;
}
inline int left_child(int number)
{
    return number<<1;
}
inline int right_child(int number)
{
    return (number<<1)+1;
}
inline void exchange(int *a, int *b)
{
    int tmp;
    tmp = *a;
    *a  = *b;
    *b  = tmp;
}

/**< 最大堆化 */
void max_heapify(HeapStructure *A, int i)
{
    ///**< 其中i为第几个数，不是下标，具体值为下标加一的值。 */
    int l = left_child(i)-1;
    int r = right_child(i)-1;
    i-=1;//将i变成下标。
    int largest;
    //将当前的值和子孩子作比较，若当前值小于子孩子的值，则将
    //子孩子的最大值和当前值做交换
    if(l < A->heap_size && A->data_array[l] > A->data_array[i])
    {
        largest = l;
    }
    else
    {
         largest = i;
    }
    if(r < A->heap_size && A->data_array[r] > A->data_array[largest])
    {
        largest = r;
    }
    if(largest != i)
    {
        exchange(&(A->data_array[i]),&(A->data_array[largest]));
        max_heapify(A,largest+1);
    }
}

/**< 最小堆化 */
void min_heapify(HeapStructure *A, int i)
{
    ///**< 其中i为第几个数，不是下标，具体为下标加一的值。 */
    int l = left_child(i)-1;
    int r = right_child(i)-1;
    i-=1;//将i变成下标。
    int smallest;
    if(l < A->heap_size && A->data_array[l] < A->data_array[i])
    {
        smallest = l;
    }
    else
    {
         smallest = i;
    }
    if(r < A->heap_size && A->data_array[r] < A->data_array[smallest])
    {
        smallest = r;
    }
    if(smallest != i)
    {
        exchange(&(A->data_array[i]),&(A->data_array[smallest]));
        min_heapify(A,smallest+1);
    }
}

/**< 建堆 */
//将数组转换成最大堆。
void build_max_heap(HeapStructure *A)
{
    A->heap_size = A->length;//?
    int i;
    for(i = A->length/2; i > 0; i--)
    {
        max_heapify(A,i);
    }
}

void build_min_heap(HeapStructure *A)
{
    A->heap_size = A->length;//?
    int i;
    for(i = A->length/2; i > 0; i--)
    {
        min_heapify(A,i);
    }
}

/**< 堆排序 */
void heap_sort1(HeapStructure *A)
{
    //从小到大排序
    build_max_heap(A);
    int i;
    for(i = A->length; i > 1; i--)
    {
        //建成最大堆后，数组中的最大元素总在根节点A[1]中，通过
        //把他与A[n]进行交换，可以让该元素放到正确的位置。
        exchange(&A->data_array[0],&A->data_array[i-1]);
        A->heap_size = A->heap_size - 1;
        max_heapify(A,1);
    }
    A->heap_size = A->length;
}

void heap_sort2(HeapStructure *A)
{
    //从大到小排序
    build_min_heap(A);
    int i;
    for(i = A->length; i > 1; i--)
    {
        exchange(&A->data_array[0],&A->data_array[i-1]);
        A->heap_size = A->heap_size - 1;
        min_heapify(A,1);
    }
    A->heap_size = A->length;
}

/**< 优先队列 */
int heap_maximum(HeapStructure A)
{
    //返回A中具有最大键字的元素。
    return A.data_array[0];
}

int heap_extract_max(HeapStructure *A)
{
    //去掉并返回A中的具有最大键字的元素
    if(A->heap_size < 1)
    {
        printf("heap underflow\n");
        return -1;
    }
    int max = A->data_array[0];
    A->data_array[0] = A->data_array[A->heap_size-1];
    A->heap_size -=1;
    max_heapify(A,1);
    return max;
}

void heap_increase_key(HeapStructure *A, int i, int key)
{
    //将元素i的关键字值(即第i个元素的值)增加到key，
    //这里假设key的值不小于i的原关键字值。
    if(key < A->data_array[i-1])
    {
        printf("new key is smaller than current key");
        return;
    }
    A->data_array[i-1] = key;
    while(i > 0 && A->data_array[parent_node(i)-1] < A->data_array[i-1])
    {
        //exchange(&A->data_array[i-1],&A->data_array[parent_node(i)-1]);
        A->data_array[i-1] = A->data_array[parent_node(i)-1];
        A->data_array[parent_node(i)-1] = key;
        i = parent_node(i);
    }
}

void max_heap_insert(HeapStructure *A, int key)
{
    //把元素key插入集合A中。
    if(A->heap_size >= A->length)
    {
        printf("The array is overflow");
        return ;
    }
    A->heap_size +=1;
    A->data_array[A->heap_size] = key;
    heap_increase_key(A, A->heap_size, key);
}

/**< 以下是快速排序的函数 */
void quick_sort(int *A, int p, int r)
{
    //在数组A[p:r]中，p为第一个元素下标，r为最后一个元素下标。
    int q;
    if(p < r)
    {
        q = partition(A, p, r);
        quick_sort(A, p, q-1);
        quick_sort(A, q+1, r);
    }
}
inline int partition(int *A, int p, int r)
{
    int x = A[r];
    int i = p - 1;
    int j;
    for(j = p; j < r; j++)
    {
        if(A[j] <= x)
        {
            i++;
            exchange(A+i,A+j);
        }
    }
    exchange(A+i+1,A+r);
    return i+1;
}

/**< 计数排序 */
void counting_sort(int *A, int *B, int n, int k)
{
    //输入数组是A[1:n]
    //输出数组是B[1:n]
    //n为数组A，B的长度
    //k为大于A,B中元素最大数的数。
    int *C;
    int i,j;
    C = (int *)calloc((k+1), sizeof(int));
    if(C == NULL)return ;
    for(j = 0; j < n; j++)
    {
        //C[i] now contains the number of elements equal to i.
        C[A[j]] = C[A[j]] + 1;
    }
    for(i = 1; i <= k; i++)
    {
        //C[i] now contains the number of elements less than or equal to i.
        C[i] = C[i] + C[i-1];
    }
    for(j = n-1; j > -1; j--)
    {
        B[C[A[j]]-1] = A[j];//注意数组下标从0开始，而计数是从1开始
        C[A[j]]    = C[A[j]] - 1;
    }
    free(C);
}

/**< 最大值和最小值 */
int minimum(int *A, int n)
{
    int min = A[0];
    int i;
    for(i = 1; i < n; i++)
    {
        if(min > A[i])
        {
            min = A[i];
        }
    }
    return min;
}

Min_Max find_min_and_max(int *A, int n)
{
    int min,max;
    int i;
    int step;
    int m,l;
    if(n > 1)
    {
        if(A[0] > A[1])//先初始min和max的值
        {
            min = A[1];
            max = A[0];
        }else
        {
            min = A[0];
            max = A[1];
        }
        step = (n >> 1) - 1;
        //从剩下的数中先比较一对元素，然后将该对元素的最大值和max比较，
        //最小值和min比较
        for(i = 1; i <= step; i++)
        {
            m = i << 1;//i*2
            l = (i << 1) + 1;//i*2+1
            if(A[m] > A[l])
            {
                max = max > A[m] ? max : A[m];
                min = min < A[l] ? min : A[l];
            }else
            {
                max = max > A[l] ? max : A[l];
                min = min < A[m] ? min : A[m];
            }
        }
        //如果输入数组是奇数个元素，则将max和min和最后一个值做比较；
        if(n%2 == 1)
        {
            max = max > A[n-1] ? max : A[n-1];
            min = min < A[n-1] ? min : A[n-1];
        }
    }else
    {
        max = *A;
        min = *A;
    }
    Min_Max minmax;
    minmax.max = max;
    minmax.min = min;
    return minmax;
}
