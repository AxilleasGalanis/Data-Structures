#ifndef __DLIST_H_
#define __DLIST_H_

typedef struct dlist_node {
    struct dlist_node* next;
    struct dlist_node* prev;
    int data;
} dnode;

typedef struct dlist {
    struct dlist_node *head, *tail;
    int size;
} dlist;

/*Creates doubly linked list*/
extern void create();

/*Inserts a node at the end of the list*/
extern void insert_node();

/*Removes a given node depending in the value*/
extern int remove_node();

/*find the data and return the node*/
extern dnode* find();
#endif