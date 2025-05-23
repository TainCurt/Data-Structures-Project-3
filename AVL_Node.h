#pragma once

class AVL_Node
{
    public:
    AVL_Node *up, *left, *right;
    int key;
    int value;
    int height;

    AVL_Node(int k, int v) : key(k), value(v), height(0), up(nullptr), left(nullptr), right(nullptr) {};
    

};


