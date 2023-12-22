#include <stdio.h>
#include "sort.h"
#include "dlist.h"

void insertion_sort(dlist* list){
    dnode *marker=NULL, *curr=NULL, *print=NULL;
    int cnt=1;

    for(marker=list->head->next;marker!=NULL;marker=marker->next){
        int temp=marker->data;                                 
        curr=marker;   
        
        while(curr->prev!=NULL && curr->prev->data >= temp){
            curr->data=curr->prev->data;            
            curr=curr->prev;                       
        }
        curr->data=temp;
        print=list->head;
        printf(" [%d]: ",cnt);
        print_list(print);
        printf("\n");
        cnt++;
    }
}

void selection_sort(dlist* list){
    dnode* temp=list->head;
    dnode* print=NULL;
    int cnt=1;
    
    while(temp){
        dnode* min=temp;
        dnode* next=temp->next;
        
        while(next){
            if(min->data>next->data){
                min=next;
            }
            next=next->next;
        }
        int swap=temp->data;
        temp->data=min->data;
        min->data=swap;
        temp=temp->next;
        if(temp!=NULL){
            print=list->head;
            printf(" [%d]: ",cnt);
            print_list(print);
            printf("\n");
            cnt++;
        }
    }
}

dnode* partition(dnode* l, dnode* h){
    int num=h->data,temp=-1;
    dnode* i=l;
    dnode* j=h->prev;
    
    
    while(i != NULL && j != NULL && l->next != h){
        while(1){
            if(i->data>num || i->data == j->data){
                break;
            }
            i=i->next;
        }
        while(1){
            if(j->data<num || i->data == j->data){
                break;
            }
            j=j->prev;
        }
        if(i->data == j->data){
            break;
        }
        temp=i->data;
        i->data=j->data;
        j->data=temp;
    }
    
    if(temp>-1 || (i->data>num && j->data==i->data)){
        temp=i->data;
        i->data=h->data;
        h->data=temp;
        return i;
    }
    return i->next;
}

void quick_sort(dnode* l, dnode* h,int num){
    dnode* temp=NULL;
    
    if(h!=l && l!=h->next){
        for(int i=0; i<num; i++){
            printf("== ");
        }
        printf("[%d >] ",num);
        print_list_qs(l, h);
        printf("\n");
    }
    
    if(h!=NULL && l!=h && l!=h->next){
        temp=partition(l, h);
        
        if(l->next->data == h->data){
             for(int i=0; i<num; i++){
                printf("== ");
            }
            printf("[%d <] ",num);
            print_list_qs(l, h);
            printf("\n");
            return ;
        }
        else{
            for(int i=0; i<num; i++){
                printf("== ");
            }
            printf("[%d -] ",num);
            print_list_qs(l, h);
            printf("\n");
        }
        if(l->data!=temp->data){
            quick_sort(l, temp->prev, num+1);
        }
        else{
            quick_sort(l, temp, num+1);
        }
        
        quick_sort(temp->next, h, num+1);
        
        for(int i=0; i<num; i++){
            printf("== ");
        }
        printf("[%d <] ",num);
        print_list_qs(l, h);
        printf("\n");
        num--;
        
    }
    
}