#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct bt_node {   
    struct bt_node* left;  
    struct bt_node* right;  
    int value;
} node;

typedef struct btree {  
    node* root;  
} btree;

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
    for(i=beg; i<=end; i++){
        if(elements[i] > elements[beg]){
            break;
        }
    }
    new_node->left = make_bst_from_preorder(elements, beg+1, i-1);
    new_node->right = make_bst_from_preorder(elements, i, end);
    return new_node;
}

void printleaf(node* root){
    if(root == NULL){
        return ;
    }
    
    if(root->left == NULL && root->right == NULL){
        printf("%d ",root->value);
    }
    
    if(root->left != NULL){
        printleaf(root->left);
    }
    if(root->right != NULL){
        printleaf(root->right);
    }
}

int find_height(node* root){
    if(root == NULL){
        return -1;
    }
    
    int l=find_height(root->left);
    int r=find_height(root->right);
    
    if(r > l){
        return r+1;
    }
    else{
        return l+1;
    }
}

void preorder(node* root){
    if(root == NULL){
        return;
    }
    
    int height=find_height(root)+1;
    printf("%d#%d ",root->value,height);
    
    preorder(root->left);
    preorder(root->right);
}

int check_avl(node* root, int* temp){
    int l=0,r=0;
    if(root == NULL){
        return -1;
    }
    
    l=find_height(root->left);
    r=find_height(root->right);
    int diff=l>r ? l-r : r-l;
    
    if(check_avl(root->left,temp) != 0 && check_avl(root->right,temp) != 0 && diff <= 1){ //AVL sinthiki 
        return 1;
    }
    else if((*temp) == 0){
        (*temp)=root->value;
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

int main(int argc ,char* argv[]){
    btree* tree=NULL;
    int temp=0;
    int* elements=NULL,num=0,size=0;
    char choice[2]={0};
    
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
    scanf("%s",choice);
    
    if(strcmp(choice,"-f") == 0){
        printf("\n");
        printleaf(tree->root);
        printf("\n\n");
    }
    else if(strcmp(choice,"-h") == 0){
        preorder(tree->root);
        printf("\n");
    }
    else if(strcmp(choice,"-a") == 0){
        num=check_avl(tree->root, &temp);
        if(num){
            printf("AVL OK");
        }
        else{
            printf("AVL NOT OK IN NODE %d",temp);
        }
        printf("\n");
    }
    
    free_tree(tree->root);
    free(tree);
    return 0;
    
}