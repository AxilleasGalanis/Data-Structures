#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct bt_node {   
    struct bt_node* left;  
    struct bt_node* right;  
    int value;
    int height;
    double weight;
} node;

typedef struct btree {  
    node* root;  
} btree;

int count_nodes(node* root){
    if(root == NULL) {
        return 0;
    }
    else {
        return 1 +  count_nodes(root->left) + count_nodes(root->right);
    }
}

void create_bt(btree** tree){
    (*tree) = (btree*) malloc(sizeof(btree));
    if(tree == NULL){
        exit(-1);
    }
    (*tree)->root = NULL;
}

int max(int a, int b);

int height(node* root){
    if(root == NULL){
        return 0;
    }
    return root->height;
}

int max(int a, int b){
    return (a>b)?a:b;
}

node* new_node(int value){
    node* new_node=(node*) malloc(sizeof(node));
    
    new_node->value=value; 
    new_node->left=NULL; 
    new_node->right=NULL; 
    new_node->height=1;
    new_node->weight=0;
    return new_node;
}

node* right_rotate(node* temp){
    node* a=temp->left;
    node* b=a->right;
    
    a->right=temp;
    temp->left=b;
    
    temp->height=max(height(temp->left), height(temp->right))+1;
    a->height=max(height(a->left), height(a->right))+1;
    
    temp->weight=count_nodes(temp);
    a->weight=count_nodes(a);
    
    return a;
}

node* left_rotate(node* temp){
    node* a=temp->right;
    node* b=a->left;
    
    a->left=temp;
    temp->right=b;
    
    temp->height=max(height(temp->left), height(temp->right))+1;
    a->height=max(height(a->left), height(a->right))+1;
    
    temp->weight=count_nodes(temp);
    a->weight=count_nodes(a);
    
    return a;
}

int get_balance(node* root){
    if(root == NULL){
        return 0;
    }
    return height(root->left)-height(root->right);
}

node* insert(node* node, int value){
    if(node==NULL){
        return (new_node(value));
    }
    
    if(value<node->value){
        node->left=insert(node->left, value);
    }
    else if(value>node->value){
        node->right=insert(node->right, value);
    }
    else{
        return node;
    }
    
    node->height=1+max(height(node->left), height(node->right));
    node->weight=count_nodes(node);
    int bal=get_balance(node);
    int num=max(1,floor(log2(node->weight)));
    
    if(bal>num && value<node->left->value){
        return right_rotate(node);
    }
    
    if(bal<-num && value>node->right->value){
        return left_rotate(node);
    }
    
    if(bal>num && value>node->left->value){
        node->left=left_rotate(node->left);
        return right_rotate(node);
    }
    
    if(bal<-num && value<node->right->value){
        node->right=right_rotate(node->right);
        return left_rotate(node);
    }
    
    return node;
}

void preorder(node* root) { 
    if(root != NULL) { 
        printf("%d ", root->value); 
        preorder(root->left); 
        preorder(root->right); 
    } 
} 

node* find(node* root, int value){
    if(root == NULL || root->value == value){
        return root;
    }
    
    if(root->value<value){
        return find(root->right, value);
    }
    return find(root->left, value);
}

node* min_val(node* temp){
    node* curr=temp;
    
    while(curr->left != NULL){
        curr=curr->left;
    }
    
    return curr;
}

node* check(node* root){
    if(root == NULL){
        return root;
    }
    root->weight=count_nodes(root);
    int bal=get_balance(root);
    int num=max(1,floor(log2(root->weight)));
    
    if(bal>num && get_balance(root->left)>=0){
        return right_rotate(root);
    }
    
    if(bal>num && get_balance(root->left)<0){
        root->left=left_rotate(root->left);
        return right_rotate(root);
    }
    
    if(bal<-num && get_balance(root->right)<=0){
        return left_rotate(root);
    }
    
    if(bal<-num && get_balance(root->right)>0){
        root->right=right_rotate(root->right);
        return left_rotate(root);
    }
    
    root->left=check(root->left);
    root->right=check(root->right);
    return root;
    
}

node* delete(node* root, int value){
    if(root == NULL){
        return root;
    }
    
    if(value<root->value){
        root->left=delete(root->left, value);
    }
    else if(value>root->value){
        root->right=delete(root->right, value);
    }
    else{
        if(root->left == NULL || root->right == NULL){
            node* temp=root->left?root->left:root->right;
            
            if(temp == NULL){
                temp=root;
                root=NULL;
            }
            else{
                *root=*temp;
            }
            free(temp);
        }
        else{
            node* temp=min_val(root->right);
            root->value=temp->value;
            root->right=delete(root->right, temp->value);
        }
    }
    
    if(root == NULL){
        return root;
    }
    
    root->height=1+max(height(root->left), height(root->right)); 
    root->weight=count_nodes(root);
    int bal=get_balance(root);
    int num=max(1,floor(log2(root->weight)));
    
    if(bal>num && get_balance(root->left)>=0){
        return right_rotate(root);
    }
    
    if(bal>num && get_balance(root->left)<0){
        root->left=left_rotate(root->left);
        return right_rotate(root);
    }
    
    if(bal<-num && get_balance(root->right)<=0){
        return left_rotate(root);
    }
    
    if(bal<-num && get_balance(root->right)>0){
        root->right=right_rotate(root->right);
        return left_rotate(root);
    }

    return root;
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

int main(int argc, char* argv[]){
    btree* tree;
    char choice[3]={0},help='\0';
    int num=0;
    
    create_bt(&tree);
    scanf("%s",choice);
    while(1){
        if(strcmp(choice,"-i") == 0 || help == 'i'){
            help='i';
            while(1){
                scanf("%s",choice);
                if(strcmp(choice,"-d") == 0 || strcmp(choice,"-f") == 0 || strcmp(choice,"-p") == 0 || strcmp(choice,"-q") == 0){
                    break;
                }
                num=atoi(choice);
                if(find(tree->root, num) == NULL){
                    tree->root=insert(tree->root, num);
                    printf("\nINSERTED %d\n",num);
                }
                else{
                    printf("\nNOT INSERTED %d\n",num);
                }
            }
        }
        if(strcmp(choice,"-d") == 0 || help == 'd'){
            help='d';
            while(1){
                scanf("%s",choice);
                if(strcmp(choice,"-i") == 0 || strcmp(choice,"-f") == 0 || strcmp(choice,"-p") == 0 || strcmp(choice,"-q") == 0){
                    break;
                }
                num=atoi(choice);
                if(find(tree->root, num) != NULL){
                    tree->root=delete(tree->root, num);
                    tree->root=check(tree->root);
                    tree->root=check(tree->root);
                    printf("\nDELETED %d\n",num);
                }
                else{
                    printf("\nNOT DELETED %d\n",num);
                }
            }
        }
        if(strcmp(choice,"-f") == 0 || help=='f'){
            help='f';
            while(1){
                scanf("%s",choice);
                if(strcmp(choice,"-d") == 0 || strcmp(choice,"-i") == 0 || strcmp(choice,"-p") == 0 || strcmp(choice,"-q") == 0){
                    break;
                }
                num=atoi(choice);
                if(find(tree->root, num) == NULL){
                    printf("\nNOT FOUND %d\n",num);
                }
                else{
                    printf("\nFOUND %d\n",num);
                }
            }
        }
        if(strcmp(choice,"-p") == 0){
            printf("\n");
            preorder(tree->root);
            printf("\n");
        }
        if(strcmp(choice,"-q") == 0){
            free_tree(tree->root);
            free(tree);
            return 0;
        }
    }
}