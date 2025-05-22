#include <iostream>
#include "SeparateChaining.h"
#include "LinearProbing.h"

int main()
{
    LinearProbing table(10);
    table.insert(3, 1);
    table.insert(33, 2);
    table.insert(18, 3);
    table.insert(10, 4);
    table.insert(112, 9);
    table.insert(117, 10);
    table.print();
    table.remove(25, 5);
    table.print();
    int s = table.getsize();
    int c = table.getcap();
    std::cout << "\n " << s << " --------- " << c;
}