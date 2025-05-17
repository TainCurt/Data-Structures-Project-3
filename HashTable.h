#pragma once

#include "Element.h"

class HashTable
{
private:
    Element **data;
    int bucket;

    int hash_fun(int key);

public:
    HashTable();
    HashTable(int s);
    //~HashTable();
    void print();
    void insert(int k, int v);
    // void remowe();
};