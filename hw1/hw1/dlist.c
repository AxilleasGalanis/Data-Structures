#include <stdlib.h>
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