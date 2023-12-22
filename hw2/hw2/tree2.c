#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

int main(){
    btree* tree=NULL;
    int size=0;
    int* elements=NULL,num=0;
    
    elements =(int*) calloc(1,sizeof(int)); //holds the elements
    create_bt(&tree);
    while(1){
        scanf(" %d", &num);
        if(num < 0){
            break;
        }
        elements[size] = num;
        size++;
        elements = realloc(elements, (size+1)*sizeof(int));
    }
    insertion_sort(elements, size);
    tree->root = make_balanced_bst(elements, 0, size-1);
    preorder(tree->root);
    printf("\n");
    
    free(elements);
    free_tree(tree->root);
    free(tree);

    return 0;
}