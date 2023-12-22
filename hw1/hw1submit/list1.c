#include <stdlib.h>
#include <stdio.h>
#include "dlist.h"

int* zero_sum(dlist* list, int len, int pos[]){
    dnode* temp=list->head;
    dnode* curr=temp;
    int sum=0,i=0,j=0,max_len=0;
    
    while(1){ //traverse the list one elemet at a time
        j=i; 
        if(i==len){ 
            break;
        }
        temp=curr;
        while(1){ //checks if the sum is 0 of the list data beging from the start of the list
            if(j==len){
                break;
            }
            sum=sum+temp->data;
            if(sum==0){
                if(j-i>=max_len){ //find max and save it in an array
                    max_len=j-i;
                    pos[0]=i;
                    pos[1]=j;
                }
            }
            j++;
            temp=temp->next;
        }
        sum=0;
        i++;
        curr=curr->next;
    }
    return pos;
}

int main(int argc , char* argv[]) {
    dlist* list=NULL;
    int num=0,pos[2]={0},len=0,i=0;

    create(&list);
    while(1){
        scanf(" %d",&num);
        if(num==0){
            break;
        }
        len++;
        insert_node(list, num);
    }
    
    zero_sum(list, len, pos);
    
    if((pos[0]==0 && pos[1]==0)||len==1){
        return 0;
    }
    
    printf("start: %d, stop: %d, size: %d\n", pos[0], pos[1], pos[1]-pos[0]+1);
    
    dnode* temp = NULL;
    for(i=0;i<pos[0];i++){
        temp = list->head->next;
        free(list->head);
        list->head = temp;
    }
    for(;i<pos[1]+1;i++){
        printf("%d ",list->head->data);
        temp = list->head->next;
        free(list->head);
        list->head = temp;
    }
    for(;i<list->size;i++){
        temp = list->head->next;
        free(list->head);
        list->head = temp;
    }
    printf("\n");
    free(list);
    
    return 0;
}
