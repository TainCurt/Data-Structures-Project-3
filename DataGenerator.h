#pragma once
#include <vector>
#include <memory>
#include <string>
#include <fstream>
#include <random>
#include <algorithm>

using std::unique_ptr;
using std::vector;

vector<int> generate_base(int size, int min, int max)
{
    vector<int> base;
    base.reserve(size);

    for (int i = 0; i < size; i++)
    {
        base.push_back(i);
    }

    std::random_device rd;
    std::mt19937 gen(rd());
    std::shuffle(base.begin(), base.end(), gen);

    return base;
}

template <class T>
unique_ptr<T> create_and_fill(int size, int min, int max)
{
    auto values = generate_base(size, min, max)
    
}
