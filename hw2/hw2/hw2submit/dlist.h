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

/*prints list*/
extern void print_list();

/*prints quick sorted list*/
extern void print_list_qs();

/*finds the size of the list*/
extern int find_size();

/*used by merge sort*/
extern dnode* split();

/*used by merge sort*/
extern dnode* merge();

/*merge sort*/
extern dnode* merge_sort();

/*frees list*/
extern void free_list();

/*radix sort msd*/
extern dnode* radix_sort_msd();

/*merge lsd buckets*/
extern dnode* merge_lsd();

/*radix sort lsd*/
extern dnode* radix_sort_lsd();

extern void print_list_lsd();
#endif