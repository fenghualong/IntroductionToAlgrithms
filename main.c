#include<stdio.h>
#include<stdlib.h>

//#include"DivideAndConquer.h"
//#include"sort.h"
//#include"BinarySearchTree.h"
//#include"dynamic_programming.h"

#define N 16

int *rightup = "¨I";
int *right = "¡ü";
int *up = "¡û";

int main()
{

//int pp[7] = {30,35,15,5,10,20,25};
    //int pp[7] = {5,10,3,12,5,50,6};
    //matrix_chain_order(pp, 7);
    //printf("\n");

    //memoized_matrix_chain(pp, 7);
    //printf("\n");

    int x[7] = {1,2,3,2,4,1,2};
    int y[6] = {2,4,3,1,2,1};

    //int *rightup = "¨I";
    //int *right = "¡ü";
    //int *up = "¡û";

    lcs_length(x, 7, y, 6);//, rightup, right, up);

    //print_lcs()

    //int *p;
    //p = "¨I¡ü¡û¨I¡ü¡ú¨J¨K¡ý¨L";
    //printf("%s\n","¨I¡ü¡û¨I¡ü¡ú¨J¨K¡ý¨L");
    //printf("%s\n",p);

    //printf("%s\n",rightup);

    //printf("%s\n",right);

    //printf("%s\n",up);
    return 0;
}
