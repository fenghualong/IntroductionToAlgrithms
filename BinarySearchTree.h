#ifndef __BINARY_SEARCH_TREE__
#define __BINARY_SEARCH_TREE__

#include<stdio.h>
#include<stdlib.h>

typedef struct bst{
    int key;
    struct bst *parent;
    struct bst *left;
    struct bst *right;
}BST;

typedef struct tree{
    BST *root;
}TREE;
/**
*     二叉搜索树。对任何节点x，其左子树中的关键字key最大不超过x.key，
* 其右子树中的关键字最小不低于x.key.
*/
void inorder_tree_walk(BST *x);//中序遍历

//void insert_tree(BST **x, int key);//生成树

BST *tree_search(BST *x, int key);//使用递归方法来查询

BST *iterative_tree_search(BST *x, int key);//使用迭代方法查询

BST *tree_minimum(BST *x);//该树的最小值

BST *tree_maximum(BST *x);//该树的最大值

BST *tree_successor(BST *x);//后继？

BST *tree_predecessor(BST *x);//前驱？

void tree_insert(TREE *T, BST *z);

//用另一颗子树v替换一棵子树u，并成为其双亲的孩子节点
void tree_delete(TREE *T, BST *z);

//从二叉搜索树T中删除节点z.
void transplant(TREE *T, BST *u, BST *v);

BST *bst_node_init(int key);

/**< 红黑树 */

#define BLACK 0x000000
#define RED   0xff0000

typedef struct rb_bst{
    int color;
    int key;
    struct rb_bst *left;
    struct rb_bst *right;
    struct rb_bst *parent;
}RB_BST;

typedef struct rb_tree{
    RB_BST *root;
    RB_BST *nil;
}RB_TREE;

RB_BST *rb_bst_node_init(RB_TREE *T, int key);

void left_rotate(RB_TREE *T, RB_BST *x);

void right_rotate(RB_TREE *T, RB_BST *y);

/**< 插入 */
void rb_insert(RB_TREE *T, RB_BST *z);

void rb_insert_fixup(RB_TREE *T, RB_BST *z);

void rb_inorder_tree_walk(RB_TREE *T, RB_BST *x);//中序遍历

/**< 初始化红黑树 */
RB_TREE *rb_init_tree();

void rb_transplant(RB_TREE *T, RB_BST *u, RB_BST *v);

/**< 子树X的最小值 */
RB_BST *rb_tree_minimum(RB_TREE *T, RB_BST *x);

/**< 子树X的最大值 */
RB_BST *rb_tree_maximum(RB_TREE *T, RB_BST *x);

/**< 删除节点z */
void rb_delete(RB_TREE *T, RB_BST *z);

void rb_delete_fixup(RB_TREE *T, RB_BST *x);

/**< 查找关健值key，并返回该键值所在结构的地址 */
RB_BST *iterative_rb_tree_search(RB_TREE *T, int key);



#endif // __BINARY_SEARCH_TREE__
