#include <iostream>
#include "HashTable.h"

int main()
{
    HashTable table(10);
    table.insert(11, 1);
    table.insert(12, 1);
    table.insert(13, 1);
    table.insert(14, 1);
    table.insert(10, 1);
    table.insert(15, 1);
    table.insert(16, 1);
    table.insert(17, 1);
    table.insert(18, 1);
    table.insert(19, 1);
    table.insert(29, 5);
    table.insert(7, 5);
    table.insert(39, 5);
    table.insert(41, 5);
    table.insert(1, 5);
    table.print();
}