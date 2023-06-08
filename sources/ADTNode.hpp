#ifndef ADT_NODE_HPP
#define ADT_NODE_HPP

#include <iostream>
using std::ostream;

namespace ariel
{

    class ADTNode
    {
    private:
        int _data;
        ADTNode *Next;
        ADTNode *Back;
        ADTNode *prime_Next;
        ADTNode *prime_Back;

    public:
        // ctor
        ADTNode(int);
        // getters and setters
        ADTNode *getNext();
        ADTNode *get_PNext();
        ADTNode *getBack();
        ADTNode *get_PBack();
        void setNext(ADTNode *);
        void set_PNext(ADTNode *);
        void setBack(ADTNode *);
        void set_PBack(ADTNode *);
        int node_Value();
        // used for tracking(debuging) and print elements
        friend ostream &operator<<(ostream &input, const ADTNode &);
    };

};

#endif // !ADT_NODE_HPP