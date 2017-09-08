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

//程序能用，但是用了递归，且代码量也大。
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
//        if((*x)->key > key)//小于父节点的值放在左孩子节点
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
    //使用递归方法来查询key的位置
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
    //使用迭代方法查询key的位置
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
    //一个节点x的后继是大于x.key的最小关键字的节点。
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
    //用另一颗子树v替换一棵子树u，并成为其双亲的孩子节点
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
    //从二叉搜索树T中删除节点z.
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
