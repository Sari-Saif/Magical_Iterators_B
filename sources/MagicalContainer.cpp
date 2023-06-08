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
void MagicalContainer::addElement(int data)
{
    identfy_primeValue(data);
    ADTNode *new_one = new ADTNode(data);
    /***
     * In this alternative implementation,we use two pointers pCurr and pPrev to traverse the list.
     * We iterate through the list until we find the correct position for insertion.
     * If the list is empty, the new node becomes both the head and tail. If the new node should be inserted at the beginning,
     * we update the necessary pointers and make it the new head. If the new node should be inserted at the end,
     * we update the necessary pointers and make it the new tail.
     * for all other cases,we update the pointers of the previous node, new node, current node,and the node following the new node.
     * finally, we increment the _size counter to reflect the addition of the new node.
     */
    if (_Head == nullptr)
    {
        _Head = new_one;
        _Tail = new_one;
    }
    else
    {
        ADTNode *Curr = _Head;
        ADTNode *Prev = nullptr;

        while (Curr && Curr->node_Value() < data)
        {
            Prev = Curr;
            Curr = Curr->get_Next();
        }

        if (Prev == nullptr)
        {
            new_one->set_Next(_Head);
            _Head->set_Back(new_one);
            _Head = new_one;
        }
        else if (Curr == nullptr)
        {
            Prev->set_Next(new_one);
            new_one->set_Back(Prev);
            _Tail = new_one;
        }
        else
        {
            Prev->set_Next(new_one);
            new_one->set_Back(Prev);
            new_one->set_Next(Curr);
            Curr->set_Back(new_one);
        }
    }

    _size++;
    // in addittion if it's prime node we need to care about it
    if (_primeValue)
    {
        if (_primeH == nullptr)
        {
            _primeH = new_one;
            _primeT = new_one;
            return;
        }

        ADTNode *pCurr = _primeH;

        if (new_one->node_Value() < pCurr->node_Value())
        {
            new_one->set_PNext(pCurr);
            pCurr->set_PBack(new_one);
            _primeH = new_one;
        }
        else
        {
            while (pCurr->get_PNext() && pCurr->get_PNext()->node_Value() < new_one->node_Value())
            {
                pCurr = pCurr->get_PNext();
            }

            new_one->set_PBack(pCurr);
            new_one->set_PNext(pCurr->get_PNext());

            if (pCurr->get_PNext() == nullptr)
            {
                pCurr->set_PNext(new_one);
                _primeT = new_one;
            }
            else
            {
                pCurr->set_PNext(new_one);
                new_one->get_PNext()->set_PBack(new_one);
            }
        }
        _primeS++;
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

// TODO:: create print function's to track container operation
ADTNode *MagicalContainer::remove_Node(int value)
{
    if (_size == 0)
        return nullptr;
    // pointer on detached node
    ADTNode *Detached = nullptr;

    // pointer on head and after that iterate on the list
    // mean of iterate is to go over element until reach the node with value
    ADTNode *new_one = _Head;
    while (new_one)
    {
        if (new_one->node_Value() == value)
        {
            Detached = new_one;
            break;
        }
        new_one = new_one->get_Next();
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

    ADTNode *new_one = _primeH;
    while (new_one)
    {
        if (new_one->node_Value() == value)
        {
            Detached = new_one;
            break;
        }
        new_one = new_one->get_PNext();
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
