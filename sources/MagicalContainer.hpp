/**
 *@author Sari Safe
 *@since 4.06.23
 * URL TUTORIAL:
 * https://en.cppreference.com/w/
 * https://hackingcpp.com/cpp/cheat_sheets.html
 * Credit to & owner of the idea to ADTNODE DESIGNER :
 * Simcha Teich - https://drive.google.com/file/d/15o9KRTFxoOuS7r0CEkHNmYOPaDulfMAo/view?usp=sharing
 */

#ifndef MAGICALCONTAINER_HPP
#define MAGICALCONTAINER_HPP
#include "ADTNode.hpp"
#include <iostream>
#include <cmath>

namespace ariel
{
    class MagicalContainer // NOLINT
    {
    private:
        // data members
        int _size;
        int _primeS; // prime size
        // nodes for linked list
        ADTNode *_Head;   // NOLINT
        ADTNode *_Tail;   // NOLINT
        ADTNode *_primeH; // NOLINT
        ADTNode *_primeT; // NOLINT

        bool _primeValue; // NOLINT
        // helpe function's;
        ADTNode *MagicalContainer::remove_Node(int);
        ADTNode *MagicalContainer::remove_Nodep(int);

    public:
        // Constructor
        MagicalContainer();
        // Destructor
        ~MagicalContainer();
        // Add an element to the container
        void addElement(int);
        // Remove an element from the container
        void removeElement(int);
        // Get the size of the container
        int size() const;
        // to identfy primevalue
        void identfy_primeValue(int);

        class SideCrossIterator // NOLINT
        {
        private:
            MagicalContainer &magic;
            ADTNode *start;
            int _range;

        public:
            // ctor's
            SideCrossIterator(MagicalContainer &);
            SideCrossIterator(SideCrossIterator &);
            ~SideCrossIterator();
            SideCrossIterator &operator=(const SideCrossIterator &);
            // the head annd the tail
            SideCrossIterator begin();
            SideCrossIterator end();
            // oprator's
            int operator*();
            SideCrossIterator &operator++();
            bool operator==(const SideCrossIterator &seconed) const;
            bool operator!=(const SideCrossIterator &seconed) const;
            bool operator>(const SideCrossIterator &seconed) const;
            bool operator<(const SideCrossIterator &seconed) const;
        };
        class AscendingIterator // NOLINT
        {
        private:
            MagicalContainer &magic;
            ADTNode *start;
            int _range;

        public:
            // ctor's
            AscendingIterator(MagicalContainer &);
            AscendingIterator(AscendingIterator &);
            ~AscendingIterator();
            AscendingIterator &operator=(const AscendingIterator &);
            // the head annd the tail
            AscendingIterator begin();
            AscendingIterator end();
            // oprator's
            int operator*();
            AscendingIterator &operator++();
            bool operator==(const AscendingIterator &seconed) const;
            bool operator!=(const AscendingIterator &seconed) const;
            bool operator>(const AscendingIterator &seconed) const;
            bool operator<(const AscendingIterator &seconed) const;
        };
        class PrimeIterator // NOLINT
        {
        private:
            MagicalContainer &magic;
            ADTNode *start;
            int _range;

        public:
            // ctor's
            PrimeIterator(MagicalContainer &);
            PrimeIterator(PrimeIterator &);
            ~PrimeIterator();
            PrimeIterator &operator=(const PrimeIterator &);
            // the head annd the tail
            PrimeIterator begin();
            PrimeIterator end();
            // oprator's
            int operator*();
            PrimeIterator &operator++();
            bool operator==(const PrimeIterator &seconed) const;
            bool operator!=(const PrimeIterator &seconed) const;
            bool operator>(const PrimeIterator &seconed) const;
            bool operator<(const PrimeIterator &seconed) const;
        };
    };
};
#endif // MAGICALCONTAINER_HPP
