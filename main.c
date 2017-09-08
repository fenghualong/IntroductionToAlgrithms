#include<stdio.h>
#include<stdlib.h>

#include"DivideAndConquer.h"
#include"sort.h"
#include"BinarySearchTree.h"

#define N 9

int main()
{
    int i;
    RB_TREE *T;
    RB_BST  *z;
    T = rb_init_tree();
    int A[9] = {11,2,14,1,7,15,5,8,4};
    for(i = 0; i < N; i++)
    {
        z = rb_bst_node_init(T, A[i]);
        rb_insert(T, z);
    }
    rb_inorder_tree_walk(T,T->root);
    printf("\n");
    z = iterative_rb_tree_search(T,7);
    printf("iterative_rb_tree_search: %d\n",z->key);
    rb_delete(T, z);
    rb_inorder_tree_walk(T,T->root);
    return 0;
}




