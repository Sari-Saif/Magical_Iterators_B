#include "MagicalContainer.hpp"
using namespace ariel;

MagicalContainer::AscendingIterator::AscendingIterator(MagicalContainer &iter) : magic(iter)
{
    this->start = iter._Head;
    this->_range = 0;
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
    AscendingIterator prime(magic);
    return prime;
}
// oprator's
int MagicalContainer::AscendingIterator::operator*() { return 0; }
MagicalContainer::AscendingIterator &MagicalContainer::AscendingIterator::operator++() { return *this; }
bool MagicalContainer::AscendingIterator::operator==(const AscendingIterator &seconed) const { return true; }
bool MagicalContainer::AscendingIterator::operator!=(const AscendingIterator &seconed) const { return false; }
bool MagicalContainer::AscendingIterator::operator>(const AscendingIterator &seconed) const { return true; }
bool MagicalContainer::AscendingIterator::operator<(const AscendingIterator &seconed) const { return true; }
/*its important */
MagicalContainer::AscendingIterator &MagicalContainer::AscendingIterator::operator=(const AscendingIterator &another)
{
    if (&magic != &another.magic)
    {
        throw std::runtime_error("error : isnot same containers");
    }

    return *this;
}