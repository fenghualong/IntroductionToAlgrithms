#include"dynamic_programming.h"

/** \brief 钢条切割
 *
 * \param p[],长度为i英寸的钢条的价格为p[i-1]
 *              eg.int p[10] = {1,5,8,9,10,17,17,20,24,30};
 * \param n,需切割钢条的长度
 * \return 最优解的值
 *
 */

/**< 朴素递归算法 */
int cut_rod(int *p, int n)
{
    int i;
    if(n == 0)
    {
        return 0;
    }
    int q = 0;
    for(i = 0; i < n; i++)
    {
        q = max(q, p[i] + cut_rod(p, n-1-i));
    }
    return q;
}

int inline max(int a, int b)
{
    return a > b ? a : b;
}

/**< 带备忘的自底向下法 */
int memoized_cut_rod(int *p, int n)
{
    int *r;
    int q;
    //int i;
    r = (int *)calloc(2*(n+1),sizeof(int));//使用r[]记录长度为i的最优解的收益值
    q = memoized_cut_rod_aux(p,n,r);
    printf("最优解的收益值：%d\n",q);
    printf("最优解： ");
    while(n > 0)
    {
        printf("%d ",r[n+1+n]);
        n -= r[n+1+n];
    }
    printf("\n");
    return q;
}

int memoized_cut_rod_aux(int *p, int n, int *r)
{
    if(r[n])
    {
        return r[n];
    }
    int q = 0;
    int tmp;
    int i;
    for(i = 0; i < n; i++)
    {
        //q = max(q, p[i] + memoized_cut_rod_aux(p, n-1-i, r));
        tmp = p[i] + memoized_cut_rod_aux(p, n-1-i, r);
        if(q < tmp)
        {
            q = tmp;
            r[(n+1)+n] = i+1;
        }
    }
    r[n] = q;
    return q;
}

/**< 自底向上法 */
int bottom_up_cut_rod(int *p, int n)
{
    int *r;
    r = (int *)malloc((n+1)*sizeof(int));
    r[0] = 0;
    int i, j;
    int q;
    for(j = 1; j <= n; j++)
    {
        q = 0;
        for(i = 0; i < j; i++)
        {
            q = max(q, p[i] + r[j-1-i]);
        }
        r[j] = q;
    }
    return r[n];
}

/**< 重构解，输出最优解的收益值时同时输出解本身 */
int extended_bottom_up_cut_rod(int *p, int n, int *s)
{
    int *r;
    int i,j;
    int q;
    r = (int *)malloc((n+1)*sizeof(int));
    r[0] = 0;
    for(j = 1; j <= n; j++)
    {
        q = 0;
        for(i = 0; i < j; i++)
        {
            if(q < p[i] + r[j-1-i])
            {
                q = p[i] + r[j-1-i];
                s[j] = i + 1;
            }
        }
        r[j] = q;
    }
    return r[n];
}

void print_cut_rod_solution(int *p, int n)
{
    int *s;
    s = (int *)malloc((n+1)*sizeof(int));
    printf("最优解的收益值：%d\n",extended_bottom_up_cut_rod(p, n, s));
    //extended_bottom_up_cut_rod(p, n, s);
    printf("最优解： ");
    while(n > 0)
    {
        printf("%d ",s[n]);
        n -=s[n];
    }
    printf("\n");
}

/** \brief 矩阵链乘法
 *      给定一个n阶矩阵的序列，计算他们的乘积
 *
 * \param
 * \param
 * \return
 *
 */

/**< C=A*B,A[m*n],B[n*l],C[m*l] */
void matrix_multiply(int *A,int *B,int *C,int m,int n,int l)
{
    int i,j,k;
    for(i = 0; i < m; i++)
    {
        for(j = 0; j < l; j++)
        {
            C[i*m+j] = 0;
            for(k = 0; k < n; k++)
            {
                C[i*m+j] += A[i*m+k]*B[k*n+j];
            }
        }
    }
}

void matrix_chain_order(int *p, int length)
{
    int n = length - 1;//n个矩阵链需要n+1个数字表示行列
    int *m;
    m = (int *)calloc(n*n,sizeof(int));
    int *s;
    s = (int *)calloc(n*n,sizeof(int));
    int i;
    for(i = 0; i < n; i++)
    {
        m[i*n+i] = 0;
    }
    int l;
    int j;
    int k;
    int value = 1;//存储p中乘积之和，充当于无穷大。
    int q;
    for(i = 0; i < length; i++)
    {
        value *= p[i];
    }
    for(l = 2; l <= n; l++)
    {
        for(i = 1; i <= n-l+1; i++)
        {
            j = i + l - 1;
            m[(i-1)*n+(j-1)] = value;
            for(k = i; k <= j - 1; k++)
            {
                //q = m[(i-1)*n+(k-1)] + m[((k+1)-1)*n+(j-1)] + p[i-1]*p[k]*p[j];
                q = m[(i-1)*n+(k-1)] + m[k*n+(j-1)] + p[i-1]*p[k]*p[j];
                if(q < m[(i-1)*n+(j-1)])
                {
                    m[(i-1)*n+(j-1)] = q;
                    s[(i-1)*n+(j-1)] = k;
                }

            }
        }
    }
    //printf("%d\n",m[0*n+n]);
    print_optimal_parens(s, n, 1, n);
    printf("\n");
    show(m, n);
    printf("\n");
    show(s, n);
    printf("\n");

}

void print_optimal_parens(int *s, int n, int i, int j)
{
    if(i == j)
    {
        printf("A[%d]",i);
    }else
    {
        printf("(");
        print_optimal_parens(s,n,i,s[(i-1)*n+(j-1)]);
        print_optimal_parens(s,n,s[(i-1)*n+(j-1)]+1,j);
        printf(")");
    }
}

void memoized_matrix_chain(int *p, int length)
{
    int n = length - 1;
    int *m;
    m = (int *)calloc(n*n,sizeof(int));
    int *s;
    s = (int *)calloc(n*n,sizeof(int));
    int i;
    int value = 1;//存储p中乘积之和，充当于无穷大。
    for(i = 0; i < length; i++)
    {
        value *= p[i];
    }
    int j;
    for(i = 0; i < n; i++)
    {
        for(j = i; j < n; j++)
        {
            m[i*n+j] = value;
        }
    }
    lookup_chain(m , s, p, 1, n, value, n);
    print_optimal_parens(s, n, 1, n);
    printf("\n");
    show(m, n);
    printf("\n");
    show(s, n);
    printf("\n");
}

int lookup_chain(int *m, int *s, int *p, int i, int j, int value, int n)
{
    if(m[(i-1)*n+(j-1)]<value)
    {
        return m[(i-1)*n+(j-1)];
    }
    int k;
    int q;
    if(i == j)
    {
        m[(i-1)*n+(j-1)] = 0;
    }else
    {
        for(k = i; k <= j-1; k++)
        {
            q = lookup_chain(m,s,p,i,k,value,n)
                + lookup_chain(m,s,p,k+1,j,value,n)
                + p[i-1] * p[k] * p[j];
            if(q < m[(i-1)*n+(j-1)])
            {
                m[(i-1)*n+(j-1)] = q;
                s[(i-1)*n+(j-1)] = k;
            }
        }
    }
    return m[(i-1)*n+(j-1)];
}

/**< 最长公共子序列 */
void lcs_length(int *x, int m, int *y, int n)//, int *rightup, int *right, int *up)
{
    int **b;
    b = (int **)calloc(m*n,sizeof(int *));
    int *c;
    c = (int *)calloc((m+1)*(n+1),sizeof(int));
    int i,j;

    //printf("%s\n",rightup);

    //printf("%s\n",right);

    //printf("%s\n",up);

    for(i = 1; i <= m; i++)
    {
        //c[i*m+0] = 0;
        c[i*n] = 0;
    }
    for(j = 0; j <= n; j++)
    {
        //c[0*m+j] = 0;
        c[j] = 0;
    }
    for(i = 1; i <= m; i++)
    {
        for(j = 1; j <= n; j++)
        {
            if(x[i-1] == y[j-1])
            {
                c[i*(n+1)+j] = c[(i-1)*(n+1)+(j-1)] + 1;
                b[(i-1)*n+(j-1)]= rightup ;
            }else if(c[(i-1)*(n+1)+j] >= c[i*(n+1)+(j-1)])
            {
                c[i*(n+1)+j] = c[(i-1)*(n+1)+j];
                b[(i-1)*n+(j-1)]= right ;
            }else
            {
                c[i*(n+1)+j] = c[i*(n+1)+(j-1)];
                b[(i-1)*n+(j-1)]= up ;
            }
        }
    }
    for(i = 0; i <= m; i++)
    {
        for(j = 0; j <= n; j++)
        {
            if(i == 0 || j == 0)
            {
                printf("   ");
            }else
            {
                printf(" %s",b[(i-1)*n+(j-1)]);
            }
        }
        printf("\n");

        for(j = 0; j <= n; j++)
        {
            printf("%3d",c[i*(n+1)+j]);
        }
        printf("\n");
    }
    printf("\n\n\n");
    print_lcs(b,x,m,n,n);
}

void print_lcs(int **b, int *x, int i, int j, int n)
{
    if(i == 0 || j == 0)
    {
        return;
    }
    if(b[(i-1)*n+(j-1)] == rightup)
    {
        print_lcs(b,x,i-1,j-1,n);
        printf("%d\n",x[i-1]);
    }else if(b[(i-1)*n+(j-1)] == up)
    {
        print_lcs(b,x,i-1,j,n);
    }else
    {
        print_lcs(b,x,i,j-1,n);
    }
}
