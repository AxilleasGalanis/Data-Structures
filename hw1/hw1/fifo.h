#ifndef __FIFO_H_
#define __FIFO_H_

typedef struct node {  
    struct node* next;
    int data;
} fifo_node;

typedef struct queue {  
    fifo_node* start; 
    fifo_node* end;
    int size; 
} queue;

/*Creates FIFO queue*/
extern void create_queue();

/*Inserts a node at the end*/
extern fifo_node* push();

/*Returns element to be removed*/
extern fifo_node* first();

/*Removes head node*/
extern fifo_node* pop();

#endif