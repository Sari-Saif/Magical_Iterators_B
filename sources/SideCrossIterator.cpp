#include "MagicalContainer.hpp"
using namespace ariel;

MagicalContainer::SideCrossIterator::SideCrossIterator(MagicalContainer &iter) : magic(iter), node_fiter(magic._Head), node_tailiter(magic._Tail)
{
    this->_range = 0;
    this->access_iter = true; // if we can iterate in the beiging true and will change over the iteration
};

MagicalContainer::SideCrossIterator::SideCrossIterator(SideCrossIterator &iter) : magic(iter.magic)
{
    *this = iter;
};

MagicalContainer::SideCrossIterator::~SideCrossIterator(){};

// the head annd the tail
MagicalContainer::SideCrossIterator MagicalContainer::SideCrossIterator::begin()
{
    return SideCrossIterator(magic);
};

MagicalContainer::SideCrossIterator MagicalContainer::SideCrossIterator::end()
{
    SideCrossIterator end_iter(magic);
    end_iter.node_fiter = nullptr;
    end_iter.node_tailiter = nullptr;
    end_iter._range = magic._size;
    return end_iter;
};

// oprator's
int MagicalContainer::SideCrossIterator::operator*()
{
    // if therer possiable iterate from head and go over it
    if (access_iter)
    {
        if (node_fiter != nullptr)
        {
            return node_fiter->node_Value();
        }
        throw std::runtime_error("error");
    }
    else
    {
        if (node_tailiter != nullptr)
        {
            return node_tailiter->node_Value();
        }
        throw std::runtime_error("error");
    }
};

MagicalContainer::SideCrossIterator &MagicalContainer::SideCrossIterator::operator++()
{
    if (_range == this->magic._size)
    {
        throw std::runtime_error("we in the end, can't iterate more ");
    }

    if (access_iter && node_fiter)
    {
        node_fiter = node_fiter->get_Next();
        access_iter = false;
        _range++;
    }
    else if ((!access_iter) && node_tailiter)
    {
        node_tailiter = node_tailiter->get_Back();
        access_iter = true;
        _range++;
    }
    // reset the defantion of accessing iteration to iterate

    return *this;
};

bool MagicalContainer::SideCrossIterator::operator==(const SideCrossIterator &seconed) const
{
    return !(*this < seconed) && !(seconed < *this);
};

bool MagicalContainer::SideCrossIterator::operator!=(const SideCrossIterator &seconed) const
{
    return !(*this == seconed);
};

bool MagicalContainer::SideCrossIterator::operator>(const SideCrossIterator &seconed) const
{
    return (seconed._range - this->_range) < 0;
};

bool MagicalContainer::SideCrossIterator::operator<(const SideCrossIterator &seconed) const
{
    return (seconed._range - this->_range) > 0;
};

/*its important */
MagicalContainer::SideCrossIterator &MagicalContainer::SideCrossIterator::operator=(const SideCrossIterator &another)
{

    if (&magic != &another.magic)
    {
        throw std::runtime_error("error : isnot same containers");
    }
    magic = another.magic;
    node_fiter = another.node_fiter;
    node_tailiter = another.node_tailiter;
    _range = another._range;

    return *this;
};