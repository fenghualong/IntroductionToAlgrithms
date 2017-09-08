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

BST *bst_node_init(int key)
{
    BST *z;
    z = (BST *)malloc(sizeof(BST));
    z->key    = key;
    z->left   = NULL;
    z->right  = NULL;
    z->parent = NULL;
    return z;
}


/**< 红黑树 */

RB_BST *rb_bst_node_init(RB_TREE *T,int key)
{
    RB_BST *z;
    z = (RB_BST *)malloc(sizeof(RB_BST));
    z->key    = key;
    z->left   = T->nil;
    z->right  = T->nil;
    z->parent = T->nil;
    return z;
}

void left_rotate(RB_TREE *T, RB_BST *x)
{
    //if(x == NULL)return;
    RB_BST *y = x->right;    //set y
    x->right = y->left;     //turn y's left subtree into x's right subtree
    if(y->left != T->nil)
    {
        y->left->parent = x;
    }
    y->parent = x->parent;  //link x's parent to y
    if(x->parent == T->nil)
    {
        T->root = y;
    }else if(x == x->parent->left)
    {
        x->parent->left = y;
    }else
    {
        x->parent->right = y;
    }
    y->left   = x;            //put x on y's left
    x->parent = y;
}

void right_rotate(RB_TREE *T, RB_BST *y)
{
    RB_BST *x = y->left;
    y->left  = x->right;
    if(x->right != T->nil)
    {
        x->right->parent = y;
    }
    x->parent = y->parent;
    if(y->parent == T->nil)
    {
        T->root = x;
    }else if(y == y->parent->left)
    {
        y->parent->left = x;
    }else
    {
        y->parent->right = x;
    }
    x->right  = y;
    y->parent = x;
}

void rb_insert(RB_TREE *T, RB_BST *z)
{
    RB_BST *y = T->nil;
    RB_BST *x = T->root;
    while(x != T->nil)
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
    if(y == T->nil)
    {
        T->root = z;
    }else if(z->key < y->key)
    {
        y->left = z;
    }else
    {
        y->right = z;
    }
    z->left  = T->nil;
    z->right = T->nil;
    z->color = RED;
    rb_insert_fixup(T,z);
}

void rb_insert_fixup(RB_TREE *T, RB_BST *z)
{
    RB_BST *y;
    //if(z->parent == NULL)return;
    //if(z->parent->parent == NULL)return;
    while(z->parent->color == RED)
    {
        if(z->parent == z->parent->parent->left)
        {
            y = z->parent->parent->right;
            if(y->color == RED)
            {
                z->parent->color         = BLACK;               //case 1
                y->color                 = BLACK;               //case 1
                z->parent->parent->color = RED;                 //case 1
                z                        = z->parent->parent;   //case 1
            }else if(z == z->parent->right)
            {
                z = z->parent;                                  //case 2
                left_rotate(T, z);                              //case 2
            }else
            {
                z->parent->color         = BLACK;                //case 3
                z->parent->parent->color = RED;                  //case 3
                right_rotate(T,z->parent->parent);               //case 3
            }
        }else
        {
            y = z->parent->parent->left;
            if(y->color == RED)
            {
                z->parent->color         = BLACK;               //case 1
                y->color                 = BLACK;               //case 1
                z->parent->parent->color = RED;                 //case 1
                z                        = z->parent->parent;   //case 1
            }else if(z == z->parent->left)
            {
                z = z->parent;                                  //case 2
                right_rotate(T, z);                             //case 2
            }else
            {
                z->parent->color         = BLACK;               //case 3
                z->parent->parent->color = RED;                 //case 3
                left_rotate(T,z->parent->parent);               //case 3
            }
        }
        T->root->color = BLACK;
    }
}

void rb_inorder_tree_walk(RB_TREE *T, RB_BST *x)
{
    if(x != T->nil)
    {
        rb_inorder_tree_walk(T, x->left);
        printf("%d ",x->key);
        rb_inorder_tree_walk(T, x->right);
    }
}

RB_TREE *rb_init_tree()
{
    RB_TREE *T;
    T              = (RB_TREE *)malloc(sizeof(RB_TREE));
    T->nil         = (RB_BST *)malloc(sizeof(RB_BST));
    T->nil->left   = T->nil;
    T->nil->right  = T->nil;
    T->nil->parent = T->nil;
    T->nil->color  = BLACK;
    T->root        = T->nil;
    return T;
}

RB_BST *rb_tree_minimum(RB_TREE *T, RB_BST *x)
{
    if(x == T->nil)return T->nil;
    while(x->left != T->nil)
    {
        x = x->left;
    }
    return x;
}

RB_BST *rb_tree_maximum(RB_TREE *T, RB_BST *x)
{
    if(x == T->nil)return T->nil;
    while(x->right != T->nil)
    {
        x = x->right;
    }
    return x;
}

void rb_transplant(RB_TREE *T, RB_BST *u, RB_BST *v)
{
    if(u->parent == T->nil)
    {
        T->root = v;
    }else if(u == u->parent->left)
    {
        u->parent->left = v;
    }else
    {
        u->parent->right = v;
    }
    v->parent = u->parent;
}



void rb_delete(RB_TREE *T, RB_BST *z)
{
    RB_BST *y = z;
    RB_BST *x;
    int y_original_color = y->color;
    if(z->left == T->nil)
    {
        x = z->right;
        rb_transplant(T,z,z->right);
    }else if(z->right == T->nil)
    {
        x = z->left;
        rb_transplant(T,z,z->left);
    }else
    {
        y                = rb_tree_minimum(T,z->right);
        y_original_color = y->color;
        x                = y->right;
        if(y->parent == z)
        {
            x->parent = y;
        }else
        {
            rb_transplant(T,y,y->right);
            y->right        = z->right;
            y->right->parent = y;
        }
        rb_transplant(T,z,y);
        y->left         = z->left;
        y->left->parent = y;
        y->color        = z->color;
    }
    if(y_original_color == BLACK)
    {
        rb_delete_fixup(T,x);
    }
    free(z);
}

void rb_delete_fixup(RB_TREE *T, RB_BST *x)
{
    RB_BST *w;
    while(x != T->root && x->color == BLACK)
    {
        if(x == x->parent->left)
        {
            w = x->parent->right;
            if(w->color == RED)
            {
                /**< x的兄弟节点w是红色的 */
                w->color = BLACK;               //case 1
                x->parent->color = RED;         //case 1
                left_rotate(T,x->parent);       //case 1
                w = x->parent->right;           //case 1
            }else if(w->left->color == BLACK && w->right->color == BLACK)
            {
                /**< x的兄弟节点w是黑色的，而且w的两个子节点都是黑色的 */
                w->color = RED;                 //case 2
                x = x->parent;                  //case 2
            }else if(w->right->color == BLACK)
            {
                /**< x的兄弟节点w是黑色的，w的左孩子是红色的，w的右孩子是黑色的 */
                w->right->color = BLACK;        //case 3
                w->color = RED;                 //case 3
                right_rotate(T,w);              //case 3
                w = x->parent->right;           //case 3
            }else
            {
                /**< x的兄弟节点w是黑色的，且w的右孩子是红色的 */
                w->color = x->parent->color;    //case 4
                x->parent->color = BLACK;       //case 4
                w->right->color = BLACK;        //case 4
                left_rotate(T,x->parent);       //case 4
                x = T->root;
            }
        }else
        {
            w = x->parent->left;
            if(w->color == RED)
            {
                w->color = BLACK;
                x->parent->color = RED;
                right_rotate(T,x->parent);
                w = x->parent->left;
            }else if(w->right->color == BLACK && w->left->color == BLACK)
            {
                w->color = RED;
                x = x->parent;
            }else if(w->left->color == BLACK)
            {
                w->left->color = BLACK;
                w->color = RED;
                left_rotate(T,w);
                w = x->parent->left;
            }else
            {
                w->color = x->parent->color;
                x->parent->color = BLACK;
                w->left->color = BLACK;
                right_rotate(T,x->parent);
                x = T->root;
            }
        }
    }
    x->color = BLACK;
}

RB_BST *iterative_rb_tree_search(RB_TREE *T, int key)
{
    //使用迭代方法查询key的位置
    RB_BST *x = T->root;
    while(x != T->nil && key != x->key)
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
