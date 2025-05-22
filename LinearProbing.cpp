#include "LinearProbing.h"
#include <iostream>
LinearProbing::LinearProbing() : size(0), capacity(0), array(nullptr) {}

LinearProbing::LinearProbing(int s) : size(0), capacity(s)
{
    array = new Linear_Element[capacity];
    // for (int i = 0; i < capacity; i++)
    // {
    //     array[i].key = 0;
    //     array[i].value = 0;
    // }
}

int LinearProbing::hash_fun(int key)
{
    return key % capacity;
}

void LinearProbing::insert(int k, int v)
{
    if (size == capacity)
    {
        increase_capacity();
    }

    int hash = hash_fun(k);
    for (int i = 0; i < capacity; i++)
    {
        int h = (hash + i) % capacity;
        if (!array[h].is_occupied)
        {
            array[h].key = k;
            array[h].value = v;
            array[h].is_occupied = true;
            size++;
            return;
        }
    }
}

void LinearProbing::remove(int k, int v)
{
    int hash = hash_fun(k);
    if (!array[hash].is_occupied)
    {
        std::cout << "No element there! \n";
        return;
    }

    int temp = 0;
    for (int i = hash; i < capacity; i++)
    {
        if (array[i].key == k && array[i].value == v)
        {
            array[i].key = 0;
            array[i].value = 0;
            array[i].is_occupied = false;
            size--;
            return;
        }
        else if (temp == capacity - hash -1)
        {
            std::cout << "No element there! \n";
            return;
        }
        temp++;
    }
}

void LinearProbing::increase_capacity()
{
    capacity = (size == 0) ? 1 : capacity * 2;
    Linear_Element *temp = new Linear_Element[capacity];
    int hash;
    for (int i = 0; i < capacity / 2; i++)
    {
        hash = hash_fun(array[i].key);
        if (!temp[hash].is_occupied)
        {
            temp[hash].key = array[i].key;
            temp[hash].value = array[i].value;
            temp[hash].is_occupied = true;
        }
    }
    delete[] array;
    array = temp;
}

void LinearProbing::print()
{
    for (int i = 0; i < capacity; i++)
    {
        std::cout << "Index: " << i
                  << " Key: " << array[i].key
                  << " Value: " << array[i].value
                  << " Flag: " << array[i].is_occupied << "\n";
    }
    std::cout << std::endl;
}