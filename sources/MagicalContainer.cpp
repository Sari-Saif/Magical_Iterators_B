#include "MagicalContainer.hpp"
#include <iostream>
#include <cmath>

using namespace ariel;

MagicalContainer::MagicalContainer() : _Head(nullptr), _Tail(nullptr), _primeH(nullptr), _size(0), _primeS(0)
{

    this->_primeValue = 0; // this use - to identfy if the inserted new value is prime or not
                           // because there specific attitude to insert and delete
}

MagicalContainer::~MagicalContainer()
{
    // clear all
    for (int i = _size; i > 0; --i)
    {
        removeElement(_Head->node_Value());
    }
}
void MagicalContainer::removeElement(int data)
{
    // identfy prime's
    identfy_primeValue(data);
    // pointer on Detached Node
    ADTNode *Detached = remove_Node(data);
    // pointer in Detached prime Node
    ADTNode *pPrimeRemoved = nullptr;

    if (this->_primeValue)
    {
        pPrimeRemoved = remove_Nodep(data);
        if (pPrimeRemoved != nullptr)
        {
            delete pPrimeRemoved;
            // prime size
            _primeS--;
        }
    }

    if (Detached != nullptr)
    {
        delete Detached;
        _size--;
    }
    else
    {
        throw std::runtime_error(" there no node  with this value !");
    }
}

/***
 * In this alternative implementation,we use two pointers iter and pPrev to traverse the list.
 * We iterate through the list until we find the correct position for insertion.
 * If the list is empty, the new node becomes both the head and tail. If the new node should be inserted at the beginning,
 * we update the necessary pointers and make it the new head. If the new node should be inserted at the end,
 * we update the necessary pointers and make it the new tail.
 * for all other cases,we update the pointers of the previous node, new node, current node,and the node following the new node.
 * finally, we increment the _size counter to reflect the addition of the new node.
 */
void MagicalContainer::addElement(int data)
{
    bool prime_defantion = identfy_primeValue(data);
    ADTNode *maybe_prime = new ADTNode(data);
    // std::cout << " the value is : " << prime_defantion << std::endl;
    // in addittion if it's prime node we need to care about it
    if (prime_defantion)
    {
        add_Elem(maybe_prime);
        _size++;
        insert_Prime(maybe_prime);
        _primeS++;
    }
    else
    {
        add_Elem(maybe_prime);
        _size++;
    }
}

int MagicalContainer::size() const
{
    return this->_size;
}

/***********************************************************************************************/

/********************************** HELP FUNCTION'S *********************************************/
/*
need to check
*/

ADTNode *MagicalContainer::remove_Node(int value)
{
    if (_size == 0)
        return nullptr;
    // pointer on detached node
    ADTNode *Detached = nullptr;

    // pointer on head and after that iterate on the list
    // mean of iterate is to go over element until reach the node with value
    ADTNode *node = _Head;
    while (node)
    {
        if (node->node_Value() == value)
        {
            Detached = node;
            break;
        }
        node = node->get_Next();
    }
    // the deletion part
    if (Detached)
    {
        if (_size == 1)
        {
            // deletion
            _Head = nullptr;
            _Tail = nullptr;
        }
        // Detached->node_value
        else if (Detached == _Head)
        {
            _Head = Detached->get_Next();
            _Head->set_Back(nullptr);
        }
        // Detached->node_value
        else if (Detached == _Tail)
        {
            _Tail = Detached->get_Back();
            if (_Tail)
                _Tail->set_Next(nullptr);
        }
        else
        {
            Detached->get_Back()->set_Next(Detached->get_Next());
            Detached->get_Next()->set_Back(Detached->get_Back());
        }

        Detached->set_Next(nullptr);
        Detached->set_Back(nullptr);
    }

    return Detached;
}
// suppose the value is prime
// the function act like reamove node just here we have more pointers
ADTNode *MagicalContainer::remove_Nodep(int value)
{

    if (_primeS == 0)
        return nullptr;

    ADTNode *Detached = nullptr;

    ADTNode *node = _primeH;
    while (node)
    {
        if (node->node_Value() == value)
        {
            Detached = node;
            break;
        }
        node = node->get_PNext();
    }

    if (Detached)
    {
        if (_primeS == 1)
        {
            _primeH = nullptr;
            _primeT = nullptr;
        }
        else if (Detached == _primeH)
        {
            _primeH = Detached->get_PNext();
            _primeH->set_PBack(nullptr);
        }
        else if (Detached == _primeT)
        {
            _primeT = Detached->get_PBack();
            _primeT->set_PNext(nullptr);
        }
        else
        {
            Detached->get_PBack()->set_PNext(Detached->get_PNext());
            Detached->get_PNext()->set_PBack(Detached->get_PBack());
        }

        Detached->set_PNext(nullptr);
        Detached->set_PBack(nullptr);
    }

    return Detached;
}
// bool
int MagicalContainer::identfy_primeValue(int data)
{
    if (data < 2)
        return 0;

    if (data == 2)
        return 1;

    if (data % 2 == 0)
        return 0;

    for (int i = 3; i <= sqrt(data); i += 2)
    {
        if (data % i == 0)
            return 0;
    }

    return 1;
}

void ariel::MagicalContainer::add_Elem(ADTNode *node)
{
    if (_Head == nullptr)
    {
        _Head = node;
        _Tail = node;
        return;
    }

    if (node->node_Value() < _Head->node_Value())
    {
        node->set_Next(_Head);
        _Head->set_Back(node);
        _Head = node;
        return;
    }

    ADTNode *iter = _Head;
    ADTNode *prev = nullptr;
    while (iter != nullptr && node->node_Value() > iter->node_Value())
    {
        prev = iter;
        iter = iter->get_Next();
    }

    if (prev == nullptr)
    {
        node->set_Next(_Head);
        _Head->set_Back(node);
        _Head = node;
    }

    else
    {
        node->set_Next(prev->get_Next());
        node->set_Back(prev);
        prev->set_Next(node);
        if (node->get_Next() == nullptr)
        {
            // std::cout << "im here for ever" << std::endl;

            _Tail = node;
            // std::cout << "the tail value " << _Tail->node_Value() << std::endl;
            //  prev->set_Next(_Tail);
            //  _Tail->set_Back(prev);
        }

        else
        {

            node->get_Next()->set_Back(node);
        }
    }
}

void ariel::MagicalContainer::insert_Prime(ADTNode *prime_data)
{

    if (_primeH == nullptr)
    {
        _primeH = prime_data;
        _primeT = prime_data;
        return;
    }

    ADTNode *iter = _primeH;

    if (prime_data->node_Value() < iter->node_Value())
    {
        prime_data->set_PNext(iter);
        iter->set_PBack(prime_data);
        _primeH = prime_data;
        return;
    }
    else
    {
        while ((iter->get_PNext() != nullptr) && (iter->get_PNext())->node_Value() < prime_data->node_Value())
        {
            iter = iter->get_PNext();
        }

        prime_data->set_PBack(iter);
        prime_data->set_PNext(iter->get_PNext());
        //////////////////////////////////////////////
        // iter->get_PBack()->set_PNext(prime_data); //
        // iter->get_PNext()->set_Back(prime_data);  //

        if (iter->get_PNext() == nullptr)
        {
            iter->set_PNext(prime_data);
            prime_data->set_PBack(iter); //
            _primeT = prime_data;
        }
        else
        {
            prime_data->set_PNext(iter->get_PNext()); //
            iter->set_PNext(prime_data);

            (prime_data->get_PNext())->set_PBack(prime_data);
        }
    }
}

void ariel::MagicalContainer::printNext()
{
    ADTNode *v = _Head;
    while (v != nullptr)
    {
        std::cout << "->: " << v->node_Value();
        v = v->get_Next();
        // if (_Head == nullptr)
        // {
        //     break;
        // }
    }
    std::cout << std::endl;
}
void ariel::MagicalContainer::printBack()
{
    ADTNode *b = _Tail;
    while (b)
    {
        std::cout << "<-: " << b->node_Value();

        b = b->get_Back();
    }
    std::cout << std::endl;
}

void ariel::MagicalContainer::print_PBack()
{
    ADTNode *b = _primeT;
    while (b)
    {
        std::cout << "<-: prime " << b->node_Value();

        b = b->get_PBack();
    }
    std::cout << std::endl;
}
void ariel::MagicalContainer::print_PNext()
{
    ADTNode *v = _primeH;
    while (v)
    {
        std::cout << "-> : prime : " << v->node_Value();

        v = v->get_PNext();
    }
    std::cout << std::endl;
}