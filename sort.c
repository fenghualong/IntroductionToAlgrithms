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
    //������A[p:r]�У�pΪ��һ��Ԫ���±꣬rΪ���һ��Ԫ���±ꡣ
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
    //�ϲ�������A[p:q]��A[q+1:r]
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
    srand((unsigned int)time(0));//������������ӣ�
    for(i = 0; i < n; i++)
    {
        cp[i] = rand()%100;
    }
    return cp;

}

void quick_sort(int *A, int n, int left, int right)
{
    //��������nΪ����Ԫ�ظ�����left=������߽磬right=�ұ߽�
    int i,j,t;
    if(left < right)
    {
        i = left;
        j = right+1;
        while(1)
        {
            while(i+1<n && A[++i]<A[left]);//���������<����,>����
            while(j-1>-1 && A[--j]>A[left]);//��ǰ������<����,>����
            if(i>=j)break;
            t=A[i],A[i]=A[j],A[j]=t;//����
        }
        t=A[left],A[left]=A[j],A[j]=t;//����
        quick_sort(A,n,left,j-1);//�ؼ�������벿�ֵݹ�
        quick_sort(A,n,j+1,right);//�ؼ������Ұ벿�ֵݹ�
    }
}

/**< ����Ϊ����������ĺ��� */
//����һ���ڵ���±�i,���Ǻ����׼�������ĸ��ڵ㡢���Ӻ��Һ��ӵ��±ꡣ
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

/**< ���ѻ� */
void max_heapify(HeapStructure *A, int i)
{
    ///**< ����iΪ�ڼ������������±꣬����ֵΪ�±��һ��ֵ�� */
    int l = left_child(i)-1;
    int r = right_child(i)-1;
    i-=1;//��i����±ꡣ
    int largest;
    //����ǰ��ֵ���Ӻ������Ƚϣ�����ǰֵС���Ӻ��ӵ�ֵ����
    //�Ӻ��ӵ����ֵ�͵�ǰֵ������
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

/**< ��С�ѻ� */
void min_heapify(HeapStructure *A, int i)
{
    ///**< ����iΪ�ڼ������������±꣬����Ϊ�±��һ��ֵ�� */
    int l = left_child(i)-1;
    int r = right_child(i)-1;
    i-=1;//��i����±ꡣ
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

/**< ���� */
//������ת�������ѡ�
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

/**< ������ */
void heap_sort1(HeapStructure *A)
{
    //��С��������
    build_max_heap(A);
    int i;
    for(i = A->length; i > 1; i--)
    {
        //�������Ѻ������е����Ԫ�����ڸ��ڵ�A[1]�У�ͨ��
        //������A[n]���н����������ø�Ԫ�طŵ���ȷ��λ�á�
        exchange(&A->data_array[0],&A->data_array[i-1]);
        A->heap_size = A->heap_size - 1;
        max_heapify(A,1);
    }
    A->heap_size = A->length;
}

void heap_sort2(HeapStructure *A)
{
    //�Ӵ�С����
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

/**< ���ȶ��� */
int heap_maximum(HeapStructure A)
{
    //����A�о��������ֵ�Ԫ�ء�
    return A.data_array[0];
}

int heap_extract_max(HeapStructure *A)
{
    //ȥ��������A�еľ��������ֵ�Ԫ��
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
    //��Ԫ��i�Ĺؼ���ֵ(����i��Ԫ�ص�ֵ)���ӵ�key��
    //�������key��ֵ��С��i��ԭ�ؼ���ֵ��
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
    //��Ԫ��key���뼯��A�С�
    if(A->heap_size >= A->length)
    {
        printf("The array is overflow");
        return ;
    }
    A->heap_size +=1;
    A->data_array[A->heap_size] = key;
    heap_increase_key(A, A->heap_size, key);
}
