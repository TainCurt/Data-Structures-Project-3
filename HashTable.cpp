#include "HashTable.h"
#include <iostream>

HashTable::HashTable() : data(nullptr), bucket(0) {}

HashTable::HashTable(int s) : bucket(s)
{
    data = new Element *[bucket];
    for (int i = 0; i < bucket; i++)
    {
        data[i] = nullptr;
    }
}

int HashTable::hash_fun(int key)
{
    return key % bucket;
}

void HashTable::print()
{
    for (int i = 0; i < bucket; i++)
    {
        std::cout << "[Bucket " << i << "] : ";
        Element *current = data[i];
        while (current != nullptr)
        {

            std::cout << " Key: " << current->key
                      << " Value: " << current->value;
            current = current->next;
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

void HashTable::insert(int k, int v)
{
    int hash = hash_fun(k);
    Element *newElement = new Element(k, v);
    if (data[hash] == nullptr)
    {
        data[hash] = newElement;
    }
    else
    {
        Element *last = data[hash];
        while (last->next != nullptr)
        {
            last = last->next;
        }
        last->next = newElement;
    }
}
