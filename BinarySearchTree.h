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


#endif // __BINARY_SEARCH_TREE__
