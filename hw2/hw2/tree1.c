#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

int main(){
    btree* tree=NULL;
    int size=0,level=-1;
    int* elements=NULL,num=0;
    
    elements =(int*) calloc(1,sizeof(int)); //holds the elements
    create_bt(&tree);
    while(1){
        scanf(" %d", &num);
        if(num <= 0){
            break;
        }
        elements[size] = num;
        size++;
        elements = realloc(elements, (size+1)*sizeof(int));
    }
    
    tree->root = make_bst_from_preorder(elements, 0, size-1);
    
    printf("Enter integer: ");
    scanf("%d",&num);
    level=get_level(tree->root, num, 0);
    if(level==-1){
        printf("%d not found!\n",num);
        return 0;
    }
    
    printf("\n");
    printf("Integers in level %d are: ",level);
    print_level(tree->root, level);
    printf("\n");
    
    free(elements);
    free_tree(tree->root);
    free(tree);
    
    return 0;
}