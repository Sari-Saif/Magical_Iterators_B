#include "MagicalContainer.hpp"
using namespace ariel;

MagicalContainer::SideCrossIterator::SideCrossIterator(MagicalContainer &iter) : magic(iter)
{
    this->start = iter._Head;
    this->_range = iter.size();
}

MagicalContainer::SideCrossIterator::SideCrossIterator(SideCrossIterator &iter) : magic(iter.magic)
{
    *this = iter;
}

MagicalContainer::SideCrossIterator::~SideCrossIterator() {}

// the head annd the tail
MagicalContainer::SideCrossIterator MagicalContainer::SideCrossIterator::begin()
{
    SideCrossIterator prime(magic);
    return prime;
}

MagicalContainer::SideCrossIterator MagicalContainer::SideCrossIterator::end()
{
    SideCrossIterator prime(magic);
    return prime;
}

// oprator's
int MagicalContainer::SideCrossIterator::operator*()
{
    if (!start)
    {
        throw std::runtime_error("unkown iter");
    }

    return (*start).node_Value();
}

MagicalContainer::SideCrossIterator &MagicalContainer::SideCrossIterator::operator++() { return *this; }

bool MagicalContainer::SideCrossIterator::operator==(const SideCrossIterator &seconed) const
{
    return !(*this < seconed) && !(seconed < *this);
}

bool MagicalContainer::SideCrossIterator::operator!=(const SideCrossIterator &seconed) const
{
    return !(*this == seconed);
}

bool MagicalContainer::SideCrossIterator::operator>(const SideCrossIterator &seconed) const
{
    return true;
}

bool MagicalContainer::SideCrossIterator::operator<(const SideCrossIterator &seconed) const { return true; }

/*its important */
MagicalContainer::SideCrossIterator &MagicalContainer::SideCrossIterator::operator=(const SideCrossIterator &another)
{

    if (&magic != &another.magic)
    {
        throw std::runtime_error("error : isnot same containers");
    }
    return *this;
}