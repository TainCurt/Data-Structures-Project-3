#include "LinearProbing.h"
#include <iostream>
LinearProbing::LinearProbing() : size(7), capacity(0), scale(0), lf(0), array(nullptr) {}

LinearProbing::LinearProbing(int s) : size(0), scale(0), lf(0), capacity(s)
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
    if (10 * size >= 8 * capacity)
    {
        increase_capacity();
    }

    // for (int i = 1; i < 10; i++)
    // {
    //     if (capacity % i != 0)
    //     {
    //         scale = i;
    //         break;
    //     }
    // }

    // std::cout << "*" << scale << "*\n";
    int hash = hash_fun(k);
    for (int i = 0; i < capacity; i++)
    {
        int h = (hash + scale * i) % capacity;
        // std::cout << "&" << k << "--" << h << "&\n";

        if (array[h].key == k)
        {
            array[h].value = v;
            // size--;
            return;
        }

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
        else if (temp == capacity - hash - 1)
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
    for (int j = 0; j < capacity / 2; j++)
    {
        if (array[j].key != 0)
        {

            hash = hash_fun(array[j].key);
            for (int i = 0; i < capacity / 2; i++)
            {
                int h = (hash + scale * i) % capacity;
                if (!temp[h].is_occupied)
                {
                    temp[h].key = array[j].key;
                    temp[h].value = array[j].value;
                    temp[h].is_occupied = true;
                    break;
                }
            }
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