#include "MagicalContainer.hpp"
using namespace ariel;

MagicalContainer::PrimeIterator::PrimeIterator(MagicalContainer &container) : magic(container)
{
    this->start = container._Head;
    this->_range = container.size();
}
MagicalContainer::PrimeIterator::PrimeIterator(PrimeIterator &iter) : magic(iter.magic){
                                                                          // this->magic = iter.magic;
                                                                          *this = iter;
                                                                      };
MagicalContainer::PrimeIterator::~PrimeIterator() {}

// the head and the tail
MagicalContainer::PrimeIterator MagicalContainer::PrimeIterator::begin()
{
    PrimeIterator prime(magic);
    return prime;
}
MagicalContainer::PrimeIterator MagicalContainer::PrimeIterator::end()
{

    PrimeIterator prime(magic);
    return prime;

} // return SideCrossIterator(nullptr); }
// oprator's
int MagicalContainer::PrimeIterator::operator*() { return 0; }
MagicalContainer::PrimeIterator &MagicalContainer::PrimeIterator::operator++() { return *this; }
bool MagicalContainer::PrimeIterator::operator==(const PrimeIterator &seconed) const { return true; }
bool MagicalContainer::PrimeIterator::operator!=(const PrimeIterator &seconed) const { return false; }
bool MagicalContainer::PrimeIterator::operator>(const PrimeIterator &seconed) const { return true; }
bool MagicalContainer::PrimeIterator::operator<(const PrimeIterator &seconed) const { return true; }
/*its important */
MagicalContainer::PrimeIterator &MagicalContainer::PrimeIterator::operator=(const PrimeIterator &another) { 
    
    if(&magic!=&another.magic)
    {
        throw std::runtime_error("error : isnot same containers");
    }
    
    return *this; }