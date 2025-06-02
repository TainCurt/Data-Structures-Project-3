#include "SeparateChaining.h"
#include <iostream>

SeparateChaining::SeparateChaining() : data(nullptr), bucket(0), size(0), quantity(0), biggest_bucket(0) {}

SeparateChaining::SeparateChaining(int s) : bucket(s), size(0), quantity(0), biggest_bucket(0)
{
    data = new Element *[bucket];
    for (int i = 0; i < bucket; i++)
    {
        data[i] = nullptr;
    }
}

int SeparateChaining::hash_fun(int key)
{
    return key % bucket;
}

void SeparateChaining::print()
{
    for (int i = 0; i < bucket; i++)
    {
        std::cout << "[Bucket " << i << "] : ";
        Element *current = data[i];
        while (current != nullptr)
        {

            std::cout << " Key: " << current->key
                      << " Value: " << current->value
                      << " Position: " << current->position;
            current = current->next;
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

void SeparateChaining::insert(int k, int v)
{
    int hash = hash_fun(k);
    Element* newElement = new Element(k, v);

    int chain_length = 0;

    if (data[hash] == nullptr)
    {
        data[hash] = newElement;
        newElement->position = 0;
        size++;
        chain_length = 1;
    }
    else
    {
        Element* current = data[hash];
        while (current->next != nullptr)
        {
            current = current->next;
            chain_length++;
        }
        chain_length++;
        newElement->position = chain_length - 1;
        current->next = newElement;
    }

    quantity++;

    if (chain_length > biggest_bucket)
    {
        biggest_bucket = chain_length;
    }

    if (biggest_bucket >= 15)
    {
        increase_bucket();
    }
}


void SeparateChaining::remove(int k, int v)
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

    while (current->next != nullptr)
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

void SeparateChaining::increase_bucket()
{
    std::cout << "nie wiem moze zadziala mam dosc nie chce avl";
    int old_bucket = bucket;

    bucket = (size == 0) ? 1 : bucket * 2;

    // bucket *= 2;
    biggest_bucket = 0;
    size = 0;
    Element **temp = new Element *[bucket];
    for (int i = 0; i < bucket; i++)
    {
        temp[i] = nullptr;
    }

    for (int i = 0; i < old_bucket; i++)
    {
        Element *origin = data[i];
        if (data[i] != nullptr)
        {
            size++;
        }
        while (origin != nullptr)
        {
            Element *next = origin->next;
            int hash = hash_fun(origin->key);
            origin->next = temp[hash];
            temp[hash] = origin;
            origin = next;
        }
    }

    delete[] data;
    data = temp;
    for (int i = 0; i < bucket; i++)
    {
        if (data[i])
        {
            size++;
            int chain_len = 0;
            Element* current = data[i];
            while(current != nullptr)
            {
                current->position = chain_len;
                chain_len++;
                current = current->next;
            }

            if(chain_len > biggest_bucket)
            {
                biggest_bucket = chain_len;
            }
        }

    }
}