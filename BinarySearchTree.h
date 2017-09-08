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


#endif // __BINARY_SEARCH_TREE__
