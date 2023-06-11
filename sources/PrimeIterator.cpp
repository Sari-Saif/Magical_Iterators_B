#include "MagicalContainer.hpp"
using namespace ariel;

// ctor
MagicalContainer::PrimeIterator::PrimeIterator(MagicalContainer &container) : magic(container)
{
    this->start = container._primeH;
    this->_range = 0;
}

MagicalContainer::PrimeIterator::PrimeIterator(PrimeIterator &iter) : magic(iter.magic)
{
    *this = iter;
};
// desctor
MagicalContainer::PrimeIterator::~PrimeIterator() {}

// the head and the tail
MagicalContainer::PrimeIterator MagicalContainer::PrimeIterator::begin()
{
    return PrimeIterator(magic);
}

MagicalContainer::PrimeIterator MagicalContainer::PrimeIterator::end()
{
    // we in the end of iterator
    PrimeIterator en(magic);
    // in the end we reach to size index(last element index )
    en._range = magic._primeS;
    // null because we in the end and the end is null
    en.start = nullptr;
    return en;
}

int MagicalContainer::PrimeIterator::operator*()
{
    // if the head is null need to throw
    if (!start)
    {
        throw std::runtime_error("unkown iter");
    }

    return start->node_Value();
}

MagicalContainer::PrimeIterator &MagicalContainer::PrimeIterator::operator++()
{
    // if the head isnot null
    // iterate over the container by one stand
    if (start)
    {

        start = start->get_PNext();
        _range++;
    }
    else
    {
        throw std::runtime_error("we in the end with no possibilty to iterate more ");
    }

    return *this;
}

bool MagicalContainer::PrimeIterator::operator==(const PrimeIterator &seconed) const
{
    // if range is the same in two iterator's
    return _range == seconed._range;
}

bool MagicalContainer::PrimeIterator::operator!=(const PrimeIterator &seconed) const
{
    // not equal - not operation on "==" operator
    return !(*this == seconed);
}

bool MagicalContainer::PrimeIterator::operator>(const PrimeIterator &seconed) const
{
    return seconed._range < this->_range;
}

bool MagicalContainer::PrimeIterator::operator<(const PrimeIterator &seconed) const
{
    return seconed._range > this->_range;
}

MagicalContainer::PrimeIterator &MagicalContainer::PrimeIterator::operator=(const PrimeIterator &another)
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