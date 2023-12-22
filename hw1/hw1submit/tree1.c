#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

int main(){
    btree* tree=NULL;
    node** q;
    int num=0,size=0,*elements;
    int start=-1;
    int end=0;
    
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
    
    q = (node**) calloc(size,sizeof(node*));
    tree->root = make_bst_from_postorder(elements, 0, size-1);
    levelorder(q, tree->root, &start, &end);
    free(elements);
    free_tree(tree->root);
    free(tree);
    free(q);
    
    return 0;   
}