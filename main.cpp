#include <iostream>
#include "SeparateChaining.h"
#include "LinearProbing.h"
#include "AVL.h"

int main()
{
    AVL tree(5);
    tree.insert(10, 100);
    tree.insert(20, 200);
    tree.insert(5, 50);
    tree.insert(15, 150);
    tree.insert(25, 250);
    tree.insert(30, 300);
    tree.insert(7, 70);

    std::cout << "Drzewa AVL w bucketach:\n";
    tree.print_all();
    tree.remove(10, 100);
    tree.print_all();
}