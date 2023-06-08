#include "MagicalContainer.hpp"
#include <iostream>
#include <cmath>

using namespace ariel;

MagicalContainer::MagicalContainer() : _Head(nullptr), _Tail(nullptr), _primeT(nullptr), _primeH(nullptr), _size(0), _primeS(0)
{

    this->_primeValue = false; // this use - to identfy if the inserted new value is prime or not
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
    // pointer on Detached Node
    ADTNode *Detached = remove_Node(data);
    // pointer in Detached prime Node
    ADTNode *pPrimeRemoved = nullptr;
    // identfy prime's
    identfy_primeValue(data);
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
        throw std::runtime_error("Can't remove value that doesn't exist!");
    }
}
void MagicalContainer::addElement(int data)
{
}

int MagicalContainer::size() const
{
    return this->_size;
}

/***********************************************************************************************/

/********************************** HELP FUNCTION'S *********************************************/

/****
 *
 *
 * need to check for segmention fault , ->O(n)
 */

ADTNode *MagicalContainer::remove_Node(int value)
{
    if (_size == 0)
        return nullptr;
    // pointer on detached node
    ADTNode *Detached = nullptr;

    // pointer on head and after that iterate on the list
    // mean of iterate is to go over element until reach the node with value
    ADTNode *pNode = _Head;
    while (pNode)
    {
        if (pNode->node_Value() == value)
        {
            Detached = pNode;
            break;
        }
        pNode = pNode->getNext();
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
            _Head = Detached->getNext();
            _Head->setBack(nullptr);
        }
        // Detached->node_value
        else if (Detached == _Tail)
        {
            _Tail = Detached->getBack();
            if (_Tail)
                _Tail->setNext(nullptr);
        }
        else
        {
            Detached->getBack()->setNext(Detached->getNext());
            Detached->getNext()->setBack(Detached->getBack());
        }

        Detached->setNext(nullptr);
        Detached->setBack(nullptr);
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

    ADTNode *pNode = _primeH;
    while (pNode)
    {
        if (pNode->node_Value() == value)
        {
            Detached = pNode;
            break;
        }
        pNode = pNode->get_PNext();
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
void MagicalContainer::identfy_primeValue(int data)
{

    if (data <= 1)
    {
        this->_primeValue = false;
    }

    for (int i = 2; i <= sqrt(data); i++)
    {
        if (data % i == 0)
        {
            // return false;
            this->_primeValue = false;
            // there no need to continue
            break;
        }
    }
    this->_primeValue = true;
    // return true;
}
