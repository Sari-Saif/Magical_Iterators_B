#include "MagicalContainer.hpp"
#include <iostream>

using namespace ariel;

MagicalContainer::MagicalContainer() : _Head(nullptr), _Tail(nullptr), _primeT(nullptr), _primeH(nullptr)
{
}

MagicalContainer::~MagicalContainer()
{
    // for (int i = _size; i > 0; --i)
    // {
    //     removeElement(_Head->node_Value());
    // }
}
void MagicalContainer::removeElement(int data) {}
void MagicalContainer::addElement(int data) {}

int MagicalContainer::size() const
{
    return 0;
}
