#include"BinarySearchTree.h"
//int allocation(BST **x, int key, BST *parent);

void inorder_tree_walk(BST *x)
{
    if(x != NULL)
    {
        inorder_tree_walk(x->left);
        printf("%d ",x->key);
        inorder_tree_walk(x->right);
    }
}

//�������ã��������˵ݹ飬�Ҵ�����Ҳ��
//int allocation(BST **x, int key, BST *parent)
//{
//    *x = (BST *)malloc(sizeof(BST));
//        if(*x == NULL)
//        {
//            printf("memory error");
//            return -1;
//        }
//
//        (*x)->key    = key;
//        (*x)->left   = NULL;
//        (*x)->right  = NULL;
//        (*x)->parent = parent;
//        return 0;
//}
//
//void insert_tree(BST **x, int key)
//{
//    if(*x == NULL)
//    {
//        allocation(x, key, NULL);
//    }else
//    {
//        if((*x)->key > key)//С�ڸ��ڵ��ֵ�������ӽڵ�
//        {
//            if((*x)->left == NULL)
//            {
//                allocation(&(*x)->left,key,*x);
//            }else
//            {
//                insert_tree(&(*x)->left,key);
//            }
//        }else
//        {
//            if((*x)->right == NULL)
//            {
//                allocation(&(*x)->right,key,*x);
//            }else
//            {
//                insert_tree(&(*x)->right,key);
//            }
//        }
//    }
//}

BST *tree_search(BST *x, int key)
{
    //ʹ�õݹ鷽������ѯkey��λ��
    if(x == NULL || key == x->key)
    {
        return x;
    }else if(key < x->key)
    {
        return tree_search(x->left,key);
    }else
    {
        return tree_search(x->right,key);
    }
}

BST *iterative_tree_search(BST *x, int key)
{
    //ʹ�õ���������ѯkey��λ��
    while(x != NULL && key != x->key)
    {
        if(key < x->key)
        {
            x = x->left;
        }else
        {
            x = x->right;
        }
    }
    return x;
}

BST *tree_minimum(BST *x)
{
    if(x == NULL)return NULL;
    while(x->left != NULL)
    {
        x = x->left;
    }
    return x;
}

BST *tree_maximum(BST *x)
{
    if(x == NULL)return NULL;
    while(x->right != NULL)
    {
        x = x->right;
    }
    return x;
}

BST *tree_successor(BST *x)
{
    //һ���ڵ�x�ĺ���Ǵ���x.key����С�ؼ��ֵĽڵ㡣
    if(x == NULL)return NULL;
    if(x->right != NULL)
    {
        return tree_minimum(x->right);
    }
    BST *y = x->parent;
    while(y != NULL && x == y->right)
    {
        x = y;
        y = y->parent;
    }
    return y;
}

BST *tree_predecessor(BST *x)
{
    if(x == NULL)return NULL;
    if(x->left != NULL)
    {
        return tree_maximum(x->left);
    }
    BST *y = x->parent;
    while(y != NULL && x == y->left)
    {
        x = y;
        y = y->parent;
    }
    return y;
}

void tree_insert(TREE *T, BST *z)
{
    //printf("z2 = %d\n",z);
    BST *y = NULL;
    BST *x = T->root;
    while(x != NULL)
    {
        y = x;
        if(z->key < x->key)
        {
            x = x->left;
        }else
        {
            x = x->right;
        }
    }
    z->parent = y;
    if(y == NULL)
    {
        T->root = z;
    }else if(z->key < y->key)
    {
        y->left = z;
    }else
    {
        y->right = z;
    }
}

void transplant(TREE *T, BST *u, BST *v)
{
    //����һ������v�滻һ������u������Ϊ��˫�׵ĺ��ӽڵ�
    if(u->parent == NULL)
    {
        T->root = v;
    }else if(u == u->parent->left)
    {
        u->parent->left = v;
    }else
    {
        u->parent->right = v;
    }
    if(v != NULL)
    {
        v->parent = u->parent;
    }
}

void tree_delete(TREE *T, BST *z)
{
    //�Ӷ���������T��ɾ���ڵ�z.
    BST *y;
    if(z->left == NULL)
    {
        transplant(T,z,z->right);
    }else if(z->right == NULL)
    {
        transplant(T,z,z->left);
    }else
    {
        y = tree_minimum(z->right);
        if(y->parent != z)
        {
            transplant(T,y,y->right);
            y->right         = z->right;
            y->right->parent = y;
        }
        transplant(T,z,y);
                y->left = z->left;
        y->left->parent = y;
    }
    free(z);
}
