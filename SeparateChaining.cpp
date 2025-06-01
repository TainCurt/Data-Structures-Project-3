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
    if (size == bucket)
    {
        increase_bucket();
    }

    int hash = hash_fun(k);
    Element *newElement = new Element(k, v);
    if (data[hash] == nullptr)
    {
        data[hash] = newElement;
        size++;
    }
    else
    {
        data[hash]->position++;
        if (biggest_bucket < data[hash]->position)
        {
            biggest_bucket = data[hash]->position + 1;
        }
        Element *last = data[hash];
        while (last->next != nullptr)
        {
            last = last->next;
        }
        last->next = newElement;
    }
    quantity++;
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

// void SeparateChaining::calc_size()
// {
//     for (int i = 0; i < bucket; i++)
//     {
//         if (data[i])
//         {
//             size++;
//         }
//     }

// }

// void SeparateChaining::load_factor()
// {
//     lf =
// }

void SeparateChaining::increase_bucket()
{
    int old_bucket = bucket;
    bucket *= 2;
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
        // Element *prev_origin = nullptr;
        if (data[i] == nullptr)
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

            // prev_origin = origin->next;

            // int hash = hash_fun(origin->key);

            // if(temp[hash] == nullptr)
            // {
            //     temp[hash] = origin;
            //     temp[hash]->next = nullptr;
            // }
            // else
            // {
            //     Element* next = temp[hash]->next;
            //     temp[hash]->next = origin;
            //     origin->next = next;
            // }
            // origin = prev_origin;
        }
    }

    delete[] data;
    data = temp;
    for (int i = 0; i < bucket; i++)
    {
        if (data[i])
        {
            size++;
        }
        // while (data[i] != nullptr)
        // {
        //     data[i]->position++;
        //     if (biggest_bucket < data[i]->position)
        //     {
        //         biggest_bucket = data[i]->position + 1;
        //     }
        //     data[i] = data[i]->next;
        // }
    }
}