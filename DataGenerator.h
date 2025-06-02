#pragma once
#include <iostream>
#include <vector>
#include <memory>
#include <string>
#include <fstream>
#include <random>
#include <algorithm>
#include "AVL.h"
#include "LinearProbing.h"
#include "SeparateChaining.h"

using std::unique_ptr;
using std::vector;
using std::make_unique;

vector<int> generate_keys_unique(int size, int min)
{
    vector<int> base;
    min = (min == 0) ? 1 : min;
    
    for (int i = min; i <= size; ++i)
    {
        base.push_back(i);
    }

    std::random_device rd;
    std::mt19937 gen(rd());
    std::shuffle(base.begin(), base.end(), gen);

    return vector<int>(base.begin(), base.begin() + size);
}

vector<int> generate_random(int size, int min, int max)
{
    vector<int> base;
    base.reserve(size);

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dist(min+1, max);

    for (int i = 0; i < size; i++)
    {
        base.push_back(dist(gen));
    }

    return base;
}

template <class T>
vector<unique_ptr<T>> create_and_fill(const vector<int> &keys, const vector<int> &values, int amount)
{
    vector<unique_ptr<T>> copies;
    int size = 100;
    copies.reserve(size);
    for (int i = 0; i < size; i++)
    {
        copies.push_back(make_unique<T>(100));
    }

    for(auto &cop : copies)
    {
        for (int i = 0; i < amount; i++)
        {
            cop->insert(keys[i], values[i]);
        }
    }
    return copies;
}
