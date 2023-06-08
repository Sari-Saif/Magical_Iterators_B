#include "ADTNode.hpp"

using namespace ariel;

ADTNode::ADTNode(int data) : Next(nullptr), Back(nullptr), prime_Next(nullptr), prime_Back(nullptr)
{

    this->_data = data;
}

ADTNode *ADTNode::getNext() { return this->Next; }
ADTNode *ADTNode::get_PrimeNext() { return this->prime_Next; }
ADTNode *ADTNode::getBack() { return this->Back; }
ADTNode *ADTNode::get_PrimeBack() { return this->prime_Back; }

void ADTNode::setNext(ADTNode *update) { Next = update; }
void ADTNode::set_PrimeNext(ADTNode *update) { prime_Next = update; }
void ADTNode::setBack(ADTNode *update) { prime_Back = update; }
void ADTNode::set_PrimeBack(ADTNode *update) { Back = update; }

int ADTNode::node_Value()
{
    return this->_data;
}

ostream &ariel::operator<<(ostream &input, const ADTNode &target)
{
    input << target._data << std::endl;
    return input;
}
