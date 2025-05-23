#pragma once
#include "AVL_Node.h"

class AVL
{
private:
    AVL_Node **data;
    int bucket;

    int hash_fun(int key);
    AVL_Node *private_insert(AVL_Node *node, int k, int v);
    AVL_Node *private_remove(AVL_Node *node, int k, int v);
    void update_height(AVL_Node *node);
    int balance_factor(AVL_Node *node);
    int height(AVL_Node *node);
    AVL_Node *right_rotate(AVL_Node *ynode);
    AVL_Node *left_rotate(AVL_Node *xnode);
    AVL_Node *find_min(AVL_Node *node);

public:
    AVL();
    AVL(int b);
    //~AVL();
    void insert(int k, int v);
    void remove(int k, int v);
    void print_all();
    void print(AVL_Node *node, int depth);
};
