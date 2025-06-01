#pragma once

#include "Element.h"

class SeparateChaining
{
private:
    Element **data;
    int bucket;
    int size;
    int quantity;
    int biggest_bucket;
    int lf;
    int hash_fun(int key);
    void increase_bucket();
    void load_factor();

public:
    SeparateChaining();
    SeparateChaining(int s);
    //~HashTable();
    void print();
    void insert(int k, int v);
    void remove(int k, int v);
    int getsize() const { return size; }
    int getqua() const { return quantity; }
    int get_biggest() const { return biggest_bucket; }
    int get_posiotion(int index)
    {
        return data[index]->position;
    };
};