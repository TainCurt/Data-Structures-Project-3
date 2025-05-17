#pragma once

class Element{
    public:
    int key;
    int value;
    Element* next;
    Element(int k, int v) : key{k}, value{v} {};
};