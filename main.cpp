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
    SeparateChaining chain(10);
    chain.insert(1, 2);
    chain.insert(12, 2);
    chain.insert(15, 2);
    chain.insert(11, 2);
    chain.insert(122, 5);
    chain.insert(142, 5);
    chain.insert(112, 5);
    chain.insert(132, 5);
    chain.insert(162, 5);
    chain.insert(5, 2);
    chain.insert(2, 2);
    chain.insert(10, 2);
    chain.insert(3, 2);
    chain.insert(4, 2);
    chain.insert(6, 2);
    chain.insert(7, 2);
    chain.insert(8, 2);
    chain.insert(8, 2);
    chain.insert(9, 2);
    chain.insert(29, 2111);

    chain.print();
    cout << chain.getsize();
    cout << endl;
    cout << chain.get_posiotion(2);
    cout << endl;
    cout << chain.getqua();
    cout << endl;
    cout << chain.get_biggest();
}