#include "MagicalContainer.hpp"
using namespace ariel;

// ctor
MagicalContainer::AscendingIterator::AscendingIterator(MagicalContainer &iter) : magic(iter)
{
    start = iter._Head;
    _range = 0;
}

// ctor that need to return the end of container
MagicalContainer::AscendingIterator::AscendingIterator(MagicalContainer &iter, int size_iter, ADTNode *node) : magic(iter), start(node), _range(size_iter)
{
}

MagicalContainer::AscendingIterator::AscendingIterator(AscendingIterator &iter) : magic(iter.magic)
{
    *this = iter;
}

MagicalContainer::AscendingIterator::~AscendingIterator() {}

// the head annd the tail
MagicalContainer::AscendingIterator MagicalContainer::AscendingIterator::begin()
{
    AscendingIterator prime(magic);
    return prime;
}

MagicalContainer::AscendingIterator MagicalContainer::AscendingIterator::end()
{
    AscendingIterator end(magic, magic._size, nullptr);
    return end;
}

int MagicalContainer::AscendingIterator::operator*()
{
    // if nullptr is unkown itreratore like this
    if (!start)
    {
        throw std::runtime_error("unkown iter");
    }

    return start->node_Value();
}

MagicalContainer::AscendingIterator &MagicalContainer::AscendingIterator::operator++()
{
    // if the head isnot null
    // iterate over the container by one stand
    if (start)
    {
        start = start->get_Next();
        _range++;
    }
    else
    {
        throw std::runtime_error("we in the end with no possibilty to iterate more ");
    }

    return *this;
}

bool MagicalContainer::AscendingIterator::operator==(const AscendingIterator &seconed) const
{
    // another version to sahy "equal"
    return !(*this < seconed) && !(seconed < *this);
}

bool MagicalContainer::AscendingIterator::operator!=(const AscendingIterator &seconed) const
{
    // not equal - not operation on "==" operator
    return !(*this == seconed);
}

bool MagicalContainer::AscendingIterator::operator>(const AscendingIterator &seconed) const
{
    return seconed._range < this->_range;
}

bool MagicalContainer::AscendingIterator::operator<(const AscendingIterator &seconed) const
{
    return seconed._range > this->_range;
}

MagicalContainer::AscendingIterator &MagicalContainer::AscendingIterator::operator=(const AscendingIterator &another)
{
    // copy elements of iterator
    if (&magic != &another.magic)
    {
        throw std::runtime_error("error : isnot same containers");
    }
    magic = another.magic;
    start = another.start;
    _range = another._range;

    return *this;
}