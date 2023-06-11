#include "ADTNode.hpp"

using namespace ariel;
// ctor
ADTNode::ADTNode(int data) : Next(nullptr), Back(nullptr), prime_Next(nullptr), prime_Back(nullptr)
{

    this->_data = data;
}
// getter's
ADTNode *ADTNode::get_Next() { return this->Next; }
ADTNode *ADTNode::get_PNext() { return this->prime_Next; }
ADTNode *ADTNode::get_Back() { return this->Back; }
ADTNode *ADTNode::get_PBack() { return this->prime_Back; }
// setter's
void ADTNode::set_Next(ADTNode *update) { Next = update; }
void ADTNode::set_PNext(ADTNode *update) { prime_Next = update; }
void ADTNode::set_Back(ADTNode *update) { Back = update; }
void ADTNode::set_PBack(ADTNode *update) { prime_Back = update; }

int ADTNode::node_Value()
{
    return this->_data;
}
// printor stream function( buffer) thid purpose to print data
ostream &ariel::operator<<(ostream &input, const ADTNode &target)
{
    input << target._data << std::endl;
    return input;
}
