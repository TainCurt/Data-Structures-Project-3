#pragma once

#include "Element.h"

class SeparateChaining
{
private:
    Element **data;
    int bucket;

    int hash_fun(int key);

public:
    SeparateChaining();
    SeparateChaining(int s);
    //~HashTable();
    void print();
    void insert(int k, int v);
    void remove(int k, int v);
};