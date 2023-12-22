#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

void check(node* root, int* elements, int* i){
    if(root){
        check(root->left, elements, i);
        elements[(*i)++] = root->value;
        check(root->right, elements, i);
    }
}

int main(){
    btree* tree=NULL;
    int i=0;
    int* elements,num,size=0;
    
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

    tree->root = make_bt_from_levelorder(elements,tree->root, 0, size);
    check(tree->root, elements, &i);
    for(int i=0; i<size-1; i++){
        if(elements[i] > elements[i+1]){
            printf("Binary Tree\n");
            free(elements);
            free_tree(tree->root);
            free(tree);
            return 0;
        }
    }
    printf("Binary Search Tree\n");
    free(elements);
    free_tree(tree->root);
    free(tree);

    return 0;
}