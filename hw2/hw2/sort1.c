#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "dlist.h"
#include "sort.h"

dnode* radix_sort_msd(dnode* head, int n, int num){
    int index=0,i=0,j=0,h=0;
    dnode* curr=head;
    dlist **bucket;
    
    if(head == NULL){
        return NULL;
    }
    
    
    bucket=(dlist **) malloc(pow(2,n)*sizeof(dlist*));
    for(int i=0; i<pow(2,n); i++){
        create(&bucket[i]);
    }
        
    
    while(curr!=NULL){
        index=(curr->data>>(32-n*num))&((1<<n)-1);
        insert_node(bucket[index],curr->data);
        curr=curr->next;
    }
    
    
    for(i=0; i<pow(2,n); i++){
        if(bucket[i]->head!=NULL){
            for(j=0; j<num; j++){
                printf("== ");
            }
            printf("[%d, %d] ",num,i);
            printf("(");
            for (h=1<<(n-1); h>0; h=h/2){
                (i & h)? printf("1"): printf("0");
            }
            printf(") ");
            print_list(bucket[i]->head);
            printf("\n");
        }
        if(bucket[i]->head!=NULL && bucket[i]->head->next!=NULL){
            bucket[i]->head=radix_sort_msd(bucket[i]->head,n,num+1);
        }
    }
    
    for(i=0; i<pow(2,n)-1; i++){
        bucket[i+1]->head=merge(bucket[i]->head, bucket[i+1]->head);
    }
    
    return bucket[i]->head;
}

dnode* radix_sort_lsd(dlist** bucket, dnode* head, int num, int size){
    int index=0,i=0,j=0,k=0;
    int array[size];
    
    for(k=0; k<size; k++){
        array[k]=0;
    }
    
    if(head == NULL){
        return NULL;
    }
    
    while(head != NULL){
        index=(head->data>>(num*i))&((1<<num)-1);
        insert_node(bucket[index], head->data);
        head=head->next;
    }
    
    while((i+1)*num<=32){
        printf(" [%d] ",i);
        for(j=0; j<pow(2,num); j++){
            if(bucket[j] != NULL){
                print_list_lsd(bucket[j]->head, num, j);
            }
        }
        printf("\n");
        i++;
        
        for(j=0; j<pow(2,num)-1; j++){
            bucket[j+1]->head=merge_lsd(bucket[j]->head, bucket[j+1]->head);
        }
        
        if((i+1)*num > 32){
            break;
        }
        
        for(k=0; k<size; k++){
            array[k]=bucket[j]->head->data;
            bucket[j]->head=bucket[j]->head->next;
        }
        
        for(k=0; k<pow(2,num); k++){
            if(bucket[k] != NULL){
                bucket[k]=NULL;
                create(&bucket[k]);
            }
            else{
                create(&bucket[k]);
            }
        }
        k=0;
        
        while(k<size){
            index=(array[k]>>(num*i))&((1<<num)-1);
            insert_node(bucket[index], array[k]);
            k++;
        }
    }
    
    return bucket[j]->head;
}

int main(int argc , char* argv[]){
    dlist* list,**bucket;
    int num=0,size=0;

    if(argc!=2 && argc!=3){
        return 0;
    }

    if(atoi(argv[1])<1 || atoi(argv[1])>6){
        printf("Invalid argument\n");
        return 0;
    }

    if(atoi(argv[1])==5 || atoi(argv[1])==6){
        if(argv[2]==NULL || (atoi(argv[2])!=1 && atoi(argv[2])!=2 && atoi(argv[2])!=4 && atoi(argv[2])!=8 && atoi(argv[2])!=16)){
            printf("Invalid argument\n");
            return 0;
        }
    }

    create(&list);
    while(1){
        scanf(" %d",&num);
        if(num<0){
            break;
        }
        size++;
        insert_node(list, num);
    }

    print_list(list->head);
    printf("\n\n");
    
    switch(atoi(argv[1])){
        case 1:
            insertion_sort(list);
            break;
        case 2:
            selection_sort(list);
            break;
        case 3:
            quick_sort(list->head, list->tail, 0);
            break;
        case 4:
            list->head=merge_sort(list->head, 0);
            break;
        case 5:
            list->head=radix_sort_msd(list->head, atoi(argv[2]), 1);
            break;
       case 6:
            bucket=(dlist **) malloc(pow(2,atoi(argv[2]))*sizeof(dlist*));
            for(int i=0; i<pow(2,atoi(argv[2])); i++){
                create(&bucket[i]);
            }
            list->head=radix_sort_lsd(bucket, list->head, atoi(argv[2]),size);
            break;
    }

    printf("\n");
    print_list(list->head);
    printf("\n");
    free_list(list);
    free(list);
    if(atoi(argv[1]) == 6){
        free_list(bucket[0]);
        free(bucket);
    }
    return 0;
}