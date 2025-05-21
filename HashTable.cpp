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

void HashTable::remove(int k, int v)
{
    int hash = hash_fun(k);
    Element *current = data[hash];
    if (current == nullptr)
    {
        std::cout << "No bucket there! \n";
        return;
    }

    if (current->key == k && current->value == v)
    {
        data[hash] = current->next;
        delete current;
        return;
    }


    while(current->next != nullptr)
    {
        if (current->next->key == k && current->next->value == v)
        {
            Element *rem = current->next;
            current->next = rem->next;
            delete rem;
            return;
        }

        current = current->next;
    }
    std::cout << "No element there! \n";
}
