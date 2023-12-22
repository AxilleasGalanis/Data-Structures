#ifndef __TREE_H_
#define __TREE_H_

typedef struct bt_node {   
    struct bt_node* left;  
    struct bt_node* right;  
    int value;
} node;

typedef struct btree {  
    node* root;  
} btree;

/*creates binary search tree*/
extern void create_bt();

/*makes a bst from a post-order traversal*/
extern node* make_bst_from_postorder();

/*makes a bt from a level-order treaversal*/
extern node* make_bt_from_levelorder();

/*push node in a queue*/
extern void enqueue();

/*pops node from a queue*/
extern node* dequeue();

/*level-order traversal of a tree*/
extern void levelorder();

/*makes a bst from a pre-order traversal*/
extern node* make_bst_from_preorder();

/*searches for a node and saves the path to it*/
extern node* find_node();

/*prints path from one node to another*/
extern void print_path();

/*free a binary tree*/
extern void free_tree();

#endif