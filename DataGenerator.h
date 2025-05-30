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

vector<int> generate_keys_unique(int size, int min, int max)
{
    vector<int> base;
    for (int i = 0; i <= size; ++i)
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
    std::uniform_int_distribution<int> dist(min, max);

    for (int i = 0; i < size; i++)
    {
        base.push_back(dist(gen));
    }

    return base;
}

template <class T>
vector<unique_ptr<T>> create_and_fill(int quantity, int size, int min, int max, int choice)
{
    vector<int> keys;
    switch (choice)
    {
    case 1:
        keys = generate_random(size, min, max);
        break;
    case 2:
        keys = generate_keys_unique(size, min, max);
        break;
    default:
        std::cerr << "Invalid key generation choice. Must be 1 (random) or 2 (unique).\n";
        return {};
    }

    vector<int> values = generate_random(size, min, max);

    vector<unique_ptr<T>> data;
    data.reserve(quantity);
    for (int i = 0; i < quantity; i++)
    {
        data.push_back(make_unique<T>());
    }

    for (auto& instance : data)
    {
        for (int i = 0; i < size; i++)
        {
            instance->insert(keys[i], values[i]);
        }
    }

    return data;
}
