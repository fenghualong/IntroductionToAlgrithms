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
*     ���������������κνڵ�x�����������еĹؼ���key��󲻳���x.key��
* ���������еĹؼ�����С������x.key.
*/
void inorder_tree_walk(BST *x);//�������

//void insert_tree(BST **x, int key);//������

BST *tree_search(BST *x, int key);//ʹ�õݹ鷽������ѯ

BST *iterative_tree_search(BST *x, int key);//ʹ�õ���������ѯ

BST *tree_minimum(BST *x);//��������Сֵ

BST *tree_maximum(BST *x);//���������ֵ

BST *tree_successor(BST *x);//��̣�

BST *tree_predecessor(BST *x);//ǰ����

void tree_insert(TREE *T, BST *z);

//����һ������v�滻һ������u������Ϊ��˫�׵ĺ��ӽڵ�
void tree_delete(TREE *T, BST *z);

//�Ӷ���������T��ɾ���ڵ�z.
void transplant(TREE *T, BST *u, BST *v);

BST *bst_node_init(int key);

/**< ����� */

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

/**< ���� */
void rb_insert(RB_TREE *T, RB_BST *z);

void rb_insert_fixup(RB_TREE *T, RB_BST *z);

void rb_inorder_tree_walk(RB_TREE *T, RB_BST *x);//�������

/**< ��ʼ������� */
RB_TREE *rb_init_tree();

void rb_transplant(RB_TREE *T, RB_BST *u, RB_BST *v);

/**< ����X����Сֵ */
RB_BST *rb_tree_minimum(RB_TREE *T, RB_BST *x);

/**< ����X�����ֵ */
RB_BST *rb_tree_maximum(RB_TREE *T, RB_BST *x);

/**< ɾ���ڵ�z */
void rb_delete(RB_TREE *T, RB_BST *z);

void rb_delete_fixup(RB_TREE *T, RB_BST *x);

/**< ���ҹؽ�ֵkey�������ظü�ֵ���ڽṹ�ĵ�ַ */
RB_BST *iterative_rb_tree_search(RB_TREE *T, int key);



#endif // __BINARY_SEARCH_TREE__
