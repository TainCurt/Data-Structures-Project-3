#include <iostream>
#include "SeparateChaining.h"
#include "LinearProbing.h"
#include "AVL.h"
#include "DataGenerator.h"
#include <vector>
#include <algorithm>

using std::cout;
using std::cin;
using std::endl;


int main()
{
    //LinearProbing line(10);
    vector<unique_ptr<LinearProbing>> copies = create_and_fill<LinearProbing>(10, 5, 0, 10, 2);

    copies[2]->insert(1,1);
    copies[2]->print();

}