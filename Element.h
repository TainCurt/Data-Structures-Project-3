#pragma once

class Element
{
public:
    int key;
    int value;
    int position;

    Element *next;
    Element(int k, int v) : key{k}, value{v}, position(1), next(nullptr) {};
};