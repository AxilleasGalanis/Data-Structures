#include <stdlib.h>
#include "fifo.h"

void create_queue(queue** q){
    (*q) = (queue*)malloc(sizeof(queue));

    if (q == NULL){
        exit(-1);
    }

    (*q)->start = NULL;
    (*q)->end = NULL;
    (*q)->size = 0;

}

fifo_node* push(queue* q, int data){
    fifo_node* new_node = (fifo_node*) malloc(sizeof(fifo_node));
    if(new_node == NULL){
        exit(-1);
    }
    new_node->data = data;
    new_node->next = NULL;

    if(q->size == 0){
        q->start = new_node;
        q->end = new_node;
    }
    else{
        q->end->next = new_node;
        q->end = new_node;
    }

    q->size++;
    return new_node;
}

fifo_node* first(queue* q){
    if(q->size == 0){
        return NULL;
    }
    return q->start;
}

fifo_node* pop(queue* q){
    if(!first(q)){
        return NULL;
    }

    fifo_node* rmv=q->start;
    if(rmv == q->end){
        q->start = NULL;
        q->end = NULL;
    }
    else{
        q->start=rmv->next;
    }

    q->size--;
    free(rmv);
    return rmv;
}