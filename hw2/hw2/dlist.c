#include <stdlib.h>
#include <stdio.h>
#include "dlist.h"

void create(dlist** list) {
    (*list) = (dlist*) malloc(sizeof(dlist));
    if(list == NULL){
        exit(-1);
    }
    (*list)->head=NULL;
    (*list)->size=0;
}

void insert_node(dlist* list, int data) {
    dnode* node=(dnode*) malloc(sizeof(dnode));
    if(node == NULL){
        exit(-1);
    }
    node->data=data;
    node->next=NULL;

    if(list->head == NULL){
        node->next=NULL;
        node->prev=NULL;
        list->head=node;
        list->tail=node;
        list->size++;
        return ;
    }

    list->tail->next=node;
    node->prev=list->tail;
    node->next=NULL;
    list->tail=node;
    list->size++;
}

int remove_node(dlist* list, dnode* node) {
    int data = node->data;  
    
    if(node==list->head) {        
        list->head = node->next;        
        node->next->prev = node->prev;    
    }    
    else if(node==list->tail) {        
        list->tail = node->prev;        
        node->prev->next = node->next;    
    }    
    else {      
        node->prev->next = node->next;      
        node->next->prev = node->prev;    
    }     
    
    list->size--;
    free(node);
    return data;
}

dnode* find(dlist* list, int data){
    dnode* curr=list->head;
    
    while(1){
        if(curr==NULL){
            break;
        }
        if(curr->data==data){
            return curr;
        }
        curr=curr->next;
    }
    return 0;
}

void print_list(dnode* head){
    while(head!=NULL){ 
        printf("%d ",head->data);
        head=head->next; 
    }
}

void print_list_lsd(dnode* head, int num, int level){
    int h=0;
    
    while(head!=NULL){ 
        printf("%d",head->data);
        printf("(");
        for(h=1<<(num-1); h>0; h=h/2){
            (level & h)? printf("1"): printf("0");
        }
        printf(") ");
        head=head->next; 
    }
}

void print_list_qs(dnode* low, dnode* high){
    
    while(1){ 
        printf("%d ",low->data);
        if(low->next==NULL){
            break;
        }
        low=low->next; 
        if(low->data == high->data){
            printf("%d ",low->data);
            break;
        }
    }
    
}

void free_list(dlist* list){
    dnode* node=list->head;

    while(node){
        dnode* next=node->next;
        free(node);
        node=next;
    }
}

int find_size(dnode* node) { 
   int res=0; 
   while(node != NULL){ 
       res++; 
       node=node->next; 
   } 
   return res; 
}

dnode* split(dnode* head, int len){
    dnode *fast=head,*slow=head;
    int times=(len/2)-1,i=0;
    
    while(fast->next && fast->next->next && i<times){ 
        fast=fast->next->next; 
        slow=slow->next; 
        i++;
    } 
    dnode* temp=slow->next;
    slow->next=NULL;
    return temp;
}

dnode* merge(dnode* first, dnode* second){
    
    if(!first){
        return second;
    }
    
    if(!second){
        return first;
    }
    
    if(first->data < second->data){ 
        first->next=merge(first->next,second); 
        first->next->prev=first; 
        first->prev=NULL; 
        return first; 
    }
    else{ 
        second->next=merge(first,second->next); 
        second->next->prev=second; 
        second->prev=NULL; 
        return second; 
    } 
    
    
}

dnode* merge_sort(dnode* head, int num){
    int len=0, temp=0;
    
    len=find_size(head);
    for(int i=0; i<num; i++){
        printf("== ");
    }
    printf("[%d >] ",num);
    print_list(head);
    printf("\n");
    
    if(len == 1){
        for(int i=0; i<num; i++){
            printf("== ");
        }
        printf("[%d <] ",num);
        print_list(head);
        printf("\n");
        return head;
    }
    
    if(!head || !head->next){
        return head;
    }
    
    if(len == 2){
        if(head->data > head->next->data){
            temp=head->next->data;
            head->next->data=head->data;
            head->data=temp;
        }
        for(int i=0; i<num; i++){
            printf("== ");
        }
        printf("[%d <] ",num);
        print_list(head);
        printf("\n");
        return head;
    }
    
    dnode* sec=split(head, len);
    
    head=merge_sort(head, num+1); 
    sec=merge_sort(sec, num+1); 
    
    
    head=merge(head,sec); 
    for(int i=0; i<num; i++){
        printf("== ");
    }
    printf("[%d <] ",num);
    print_list(head);
    printf("\n");
    return head;
}

dnode* merge_lsd(dnode* first, dnode* second){
    
    if(!first){
        return second;
    }
    
    if(!second){
        return first;
    }
    
    first->next=merge_lsd(first->next,second); 
    first->next->prev=first; 
    first->prev=NULL; 
    return first; 
 
}