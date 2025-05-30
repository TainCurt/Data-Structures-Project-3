#include <iostream>
#include "SeparateChaining.h"
#include "LinearProbing.h"
#include "AVL.h"
//#include "DataGenerator.h"
#include <vector>
#include <algorithm>

using std::cout;
using std::cin;
using std::endl;


int main()
{
    LinearProbing line(10);
    line.insert(1,1);
    line.insert(5,2);
    line.insert(16,3);
    line.insert(12,4);
    line.insert(11,5);
    line.insert(11,100);
    // line.insert(51,6);
    // line.insert(63,7);
    // line.insert(18,8);
    // line.insert(22,9);
    // line.insert(29,10);
    // line.insert(18,16);
    // line.insert(28,9);
    // line.insert(15,10);
    // line.insert(38,11);
    // line.insert(31,12);
    // line.insert(20,11);
    // line.insert(40,12);
    // line.insert(60,13);
    // line.insert(46,14);
    // line.insert(7,15);
    // line.print();
    // line.remove(60, 13);
    line.print();

// AVL tree(10);
// tree.insert(1,2);
// tree.insert(112,2);
// tree.insert(6,2);
// tree.insert(26,2);
// tree.insert(16,2);
// tree.insert(66,2);
// tree.insert(76,2);
// tree.insert(176,2);
// tree.insert(2,2);
// tree.print_all();
}