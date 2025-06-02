#include <iostream>
#include "SeparateChaining.h"
#include "LinearProbing.h"
#include "AVL.h"
#include "DataGenerator.h"
#include <vector>
#include <algorithm>

using std::cin;
using std::cout;
using std::endl;

int main()
{
    vector<int> values = generate_random(10,0,100);
    vector<int> keys = generate_keys_unique(10,0);
    vector<unique_ptr<AVL>> copies2 = create_and_fill<AVL>(keys, values, 10);
    copies2[1]->insert(333,1);
    copies2[1]->insert(433,1);
    copies2[1]->print_all();

    // copies[1]->insert(104,1000);
    // copies[1]->insert(11,1000);
    // copies[1]->insert(111,1000);
    // copies[1]->insert(111,1000);
    // copies[1]->insert(111,1000);
    // copies[1]->insert(111,1000);
    // copies[1]->insert(111,1000);
    // copies[1]->insert(111,1000);
    // copies[1]->insert(111,1000);
    // copies[1]->insert(111,1000);
    // copies[1]->insert(111,1000);
    // copies[1]->insert(111,1000);
    // copies[1]->insert(111,1000);
    // copies[1]->insert(111,1000);
    // copies[1]->insert(111,1000);
    // copies[1]->print_all();


 }