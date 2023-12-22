#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tree.h"

int Log2(int n) { 
    return (n > 1) ? 1 + Log2(n / 2) : 0; 
} 

int main(){
    btree* tree=NULL;
    int size1=1,size2=1,N=0;
    int* elements=NULL,num1=0,num2=0,size=0;
    
    elements =(int*) calloc(1,sizeof(int)); //holds the elements
    create_bt(&tree);
    while(1){
        scanf(" %d", &num1);
        if(num1 < 0){
            break;
        }
        elements[size] = num1;
        size++;
        elements = realloc(elements, (size+1)*sizeof(int));
    }
    
    tree->root = make_bst_from_preorder(elements, 0, size-1);
    printf("Enter 2 integers: ");
    scanf("%d %d", &num1, &num2);
    N=Log2(size);
    int path1[N]; //because we know the size of elements inserted
    memset(path1, 0, N*sizeof(int));
    int path2[N];  //we can assume that the maximum path to a node would be log2(size) steps
    memset(path2, 0, N*sizeof(int));
    node* temp1 = find_node(tree->root, num1, path1, NULL, &size1, &size2);
    if(temp1 == NULL){
        printf("%d not found!\n",num1);
        free(elements);
        free_tree(tree->root);
        free(tree);
        return 0;
    }
    node* temp2 = find_node(tree->root, num2, NULL, path2, &size1, &size2);
    if(temp2 == NULL){
        printf("%d not found!\n",num2);
        free(elements);
        free_tree(tree->root);
        free(tree);
        return 0;
    }
    printf("\nPath is:");
    print_path(path1, path2, size1, size2);
    free(elements);
    free_tree(tree->root);
    free(tree);
    
    return 0;
}