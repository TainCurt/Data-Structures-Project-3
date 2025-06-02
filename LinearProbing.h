#pragma once

struct Linear_Element
{
    int key = 0;
    int value = 0;
    bool is_occupied = false;
};

class LinearProbing
{
private:
    int size;
    int capacity;
    int scale;
    int lf;
    Linear_Element *array;
    int hash_fun(int key);
    void increase_capacity();

public:
    int getsize() const { return size; }
    int getcap() const { return capacity; }
    int getscale() const { return scale; }
    LinearProbing();
    LinearProbing(int s);
    //~LinearProbing();
    void insert(int k, int v);
    void remove(int k, int v);
    void print();
};
