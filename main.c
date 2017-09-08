#include<stdio.h>
#include<stdlib.h>

#include"DivideAndConquer.h"
#include"sort.h"
#include"BinarySearchTree.h"

#define N 11

int main()
{
    //int *A;
    int i;
    //A = rand_array(N);
    TREE *T;
    T = (TREE *)malloc(sizeof(TREE));
    T->root = NULL;

    BST *root = NULL;

    BST *z = NULL;
    //int A[N] = {6,5,7,2,5,8};
    int A[11] = {15,6,18,3,7,17,20,2,4,13,9};

    //for(i = 0; i < N; i++)
    //{
        //insert_tree(&root, A[i]);
    //}

    for(i = 0; i < N; i++)
    {
        z = (BST *)malloc(sizeof(BST));
        //printf("z1 = %d\n",z);
        z->key    = A[i];
        z->left   = NULL;
        z->right  = NULL;
        z->parent = NULL;
        tree_insert(T,z);
    }
    root = T->root;
    inorder_tree_walk(root);

    BST *find;
    find = tree_search(root,7);
    printf("\nfind = %d\n",find->key);
    find = iterative_tree_search(root,15);
    printf("iterative_find = %d\n",find->key);
    tree_delete(T, find);
    root = T->root;
    inorder_tree_walk(root);
    find = tree_successor(find);
    printf("\nsuccessor = %d\n",find->key);
    find = tree_minimum(root);
    printf("min = %d\n",find->key);
    find = tree_maximum(root);
    printf("max = %d\n",find->key);
    return 0;
}




