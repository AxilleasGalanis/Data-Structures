#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct bt_node {   
    struct bt_node* left;  
    struct bt_node* right;  
    int value;
    int height;
} node;

typedef struct btree {  
    node* root;  
} btree;

int max(int a, int b){
    return (a>b)?a:b;
}

int min(int a, int b){
    return (a>b)?b:a;
}

int height(node* root){
    if(root == NULL){
        return 0;
    }
    return root->height;
}

void create_bt(btree** tree){
    (*tree) = (btree*) malloc(sizeof(btree));
    if(tree == NULL){
        exit(-1);
    }
    (*tree)->root = NULL;
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
    new_node->height = 1;
    for(i=beg; i<=end; i++){
        if(elements[i] > elements[beg]){
            break;
        }
    }
    
    new_node->left = make_bst_from_preorder(elements, beg+1, i-1);
    new_node->right = make_bst_from_preorder(elements, i, end);
    new_node->height=max(height(new_node->left), height(new_node->right))+1;
    return new_node;
}

int balanced_rb(node* root, int *maxroot){
    if(root == NULL){
        return 1;
    }
    
    int lmax=0,rmax=0;
    if(balanced_rb(root->left, &lmax) && balanced_rb(root->right, &rmax)){
        int minroot=min(lmax, rmax)+1;
        (*maxroot)=max(lmax, rmax)+1;
        return ((*maxroot)<=2*minroot);
    }
    
    return 0;
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

node* find_parent(node* root, int value){
    if(root == NULL || root->value == value){
        return NULL;
    }
    if((root->left != NULL && root->left->value == value) || (root->right != NULL && root->right->value == value)){
        return root;
    }
    node* l=find_parent(root->left, value);
    if(l != NULL){
        return l;
    }
    l=find_parent(root->right, value);
    return l;
}

void preorder(node* root, int flag, int counter, int black_counter, node* help, int maxh) { 
    node* par=NULL;
    if(root != NULL) { 
        printf("%d", root->value); 
        par=find_parent(help, root->value);
        if(root->height == 1 && counter<black_counter){
            flag=1;
            printf("#B ");
        }
        else if(root->height-counter == 0 && par->height-root->height == 1){
            flag=1;
            counter++;
            printf("#B ");
        }
        else if(flag == 0){
            flag=1;
            counter++;
            printf("#B ");
        }
        else if(flag == 1){
            flag=0;
            printf("#R ");
        }
        
        preorder(root->left, flag, counter, black_counter, help, maxh-1); 
        preorder(root->right, flag, counter, black_counter, help, maxh-1); 
        if(flag == 1){
            counter--;
        }
    } 
} 

int main(int argc, char* argv[]){
    btree* tree=NULL;
    int num=0,size=0,val=0,maxroot=0,black_counter=0;
    int* elements=NULL;
    
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
    
    tree->root = make_bst_from_preorder(elements, 0, size-1);
    val=balanced_rb(tree->root, &maxroot);
    if(val == 0){
        printf("RB NOK\n\n");
        free_tree(tree->root);
        free(tree);
        return 0;
    }
    else{
        printf("RB OK\n\n");
    }
    black_counter=tree->root->height/2;
    preorder(tree->root, 0, 0, black_counter, tree->root, tree->root->height);
    printf("\n");
    free_tree(tree->root);
    free(tree);
    free(elements);
    return 0;
}