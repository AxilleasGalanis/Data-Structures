#include <stdlib.h>
#include <stdio.h>
#include "tree.h"

void create_bt(btree** tree){
    (*tree) = (btree*) malloc(sizeof(btree));
    if(tree == NULL){
        exit(-1);
    }
    (*tree)->root = NULL;
}

node* make_bst_from_postorder(int* elements, int beg, int stop){
    int i=0;
    
    if(beg>stop){
        return NULL;
    }
    
    node* new_node = (node*) malloc(sizeof(node));
    if(new_node == NULL){
        exit(-1);
    }
    new_node->value = elements[stop];
    new_node->left = new_node->right = NULL;
    
    for(i=stop; i>=beg; i--){
        if(elements[i] < new_node->value){
            break;
        }
    }
    
    new_node->right = make_bst_from_postorder(elements, i+1, stop-1);
    new_node->left = make_bst_from_postorder(elements, beg, i);
    return new_node;
}

node* make_bt_from_levelorder(int* elements, node* root, int num1, int num2){
    
    if(num1 < num2){
        node* new_node = (node*) malloc(sizeof(node));
        if(new_node == NULL){
            exit(-1);
        }
        new_node->value = elements[num1];
        new_node->left = new_node->right = NULL;
        root = new_node;
        
        root->left = make_bt_from_levelorder(elements, root->left, 2*num1+1, num2);
        root->right = make_bt_from_levelorder(elements, root->right, 2*num1+2, num2); 
    }
    return root;
}

void enqueue(node** q, node* root, int* end){
    q[(*end)] = root;
    (*end)++;
}

node* dequeue(node** q, int* start){
    return q[++(*start)];
}

void levelorder(node** q, node* root, int* start, int* end){
    node* temp = root;
    while(temp){
        printf("%d ",temp->value);
        if(temp->left)
            enqueue(q, temp->left, end);
        if(temp->right)
           enqueue(q, temp->right, end);
        temp=dequeue(q, start);
    }
    printf("\n");
}

node* make_bst_from_preorder(int* elements, int beg, int end){
    int i;
    
    if(beg > end){
        return NULL;
    }
    
    node* new_node = (node*) malloc(sizeof(node));
    if(new_node == NULL){
        exit(-1);
    }
    new_node->value = elements[beg];
    new_node->left = new_node->right = NULL;
    for(i=beg; i<=end; i++){
        if(elements[i] > elements[beg]){
            break;
        }
    }
    new_node->left = make_bst_from_preorder(elements, beg+1, i-1);
    new_node->right = make_bst_from_preorder(elements, i, end);
    return new_node;
}

node* find_node(node* root, int data, int* path1, int* path2, int* size1, int* size2){
    if(root == NULL || root->value == data){
        if(path1 != NULL){
            path1[(*size1)-1] = data;
        }
        if(path2 != NULL){
            path2[(*size2)-1] = data;
        }
        return root;
    }
    if(root->value > data){
        if(path1 != NULL){
            path1[(*size1)-1] = root->value;
            (*size1)++;
        }
        if(path2 != NULL){
            path2[(*size2)-1] = root->value;
            (*size2)++;
        }
        return find_node(root->left, data, path1, path2, size1, size2);
    }
    else{
        if(path1 != NULL){
            path1[(*size1)-1] = root->value;
            (*size1)++;
        }
        if(path2 != NULL){
            path2[(*size2)-1] = root->value;
            (*size2)++;
        }
        return find_node(root->right, data, path1, path2, size1, size2);
    }
}

void print_path(int* path1, int* path2, int size1, int size2){
    int i=0,j=0,point=0,min=0;
    
    if(size1 >= size2){
        min = size2;
    }
    else{
        min = size1;
    }
    
    for(i=0; i<min; i++){
        if(path1[i] == path2[i]){
            point=i; //last common node of the paths
        }
    }
    
    for(j=size1-1; j>point; j--){
        printf(" %d", path1[j]);
    }
    
    for(i=point; i<size2; i++){ //the conjunction happens with point counter 
        printf(" %d", path2[i]);
    }
    printf("\n");
}

void free_tree(node *root){              
    while(1){       
        if(root == NULL){
            break;
        }
        else if(root->left != NULL){
            free_tree(root->left);
            root->left = NULL;
        }
        else if(root->right != NULL){
            free_tree(root->right);
            root->right = NULL;
        }
        else{ 
            free(root);
            return;
        }
    }
}