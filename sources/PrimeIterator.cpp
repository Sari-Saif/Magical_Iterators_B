#include "MagicalContainer.hpp"
using namespace ariel;

MagicalContainer::PrimeIterator::PrimeIterator(MagicalContainer &container) : magic(container)
{
    this->start = container._primeH;
    this->_range = 0;
}

MagicalContainer::PrimeIterator::PrimeIterator(PrimeIterator &iter) : magic(iter.magic)
{
    *this = iter;
};

MagicalContainer::PrimeIterator::~PrimeIterator() {}

// the head and the tail
MagicalContainer::PrimeIterator MagicalContainer::PrimeIterator::begin()
{
    return PrimeIterator(magic);
}

MagicalContainer::PrimeIterator MagicalContainer::PrimeIterator::end()
{

    PrimeIterator en(magic);
    en._range = magic._primeS;
    en.start = nullptr;
    return en;
}

int MagicalContainer::PrimeIterator::operator*()
{
    if (!start)
    {
        throw std::runtime_error("unkown iter");
    }

    return start->node_Value();
}

MagicalContainer::PrimeIterator &MagicalContainer::PrimeIterator::operator++()
{
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

    return _range == seconed._range;
}

bool MagicalContainer::PrimeIterator::operator!=(const PrimeIterator &seconed) const
{
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
/*its important */
MagicalContainer::PrimeIterator &MagicalContainer::PrimeIterator::operator=(const PrimeIterator &another)
{

    if (&magic != &another.magic)
    {
        throw std::runtime_error("error : isnot same containers");
    }
    magic = another.magic;
    start = another.start;
    _range = another._range;
    return *this;
}