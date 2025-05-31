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
    vector<int> keys = generate_keys_unique(100, 0, 100);
    vector<int> values = generate_random(100, 0, 100);
    for (int i = 0; i < 100; i++)
    {
        cout << keys[i] << "\n";
    }
    cout << endl;
    vector<unique_ptr<LinearProbing>> copies = create_and_fill<LinearProbing>(keys, values);
    // copies[1]->insert(13, -11);
    copies[1]->insert(120, 1);
    copies[1]->insert(1114, 1);
    copies[1]->insert(128, 1);
    // copies[1]->insert(128, 1);
    copies[1]->insert(278, 1);
    copies[1]->print();
    cout << endl;
    cout << copies[1]->getcap();
    cout << endl;
    cout << copies[1]->getsize();
    cout << endl;
    cout << copies[1]->getscale();
}