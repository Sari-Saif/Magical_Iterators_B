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
        // pointer's to ADTLinked List our designing to container data structure
        ADTNode *Next;
        ADTNode *Back;
        ADTNode *prime_Next;
        ADTNode *prime_Back;

    public:
        // ctor
        ADTNode(int);
        // getters and setters
        ADTNode *get_Next();
        ADTNode *get_PNext();
        ADTNode *get_Back();
        ADTNode *get_PBack();
        void set_Next(ADTNode *);
        void set_PNext(ADTNode *);
        void set_Back(ADTNode *);
        void set_PBack(ADTNode *);
        /*
            get node value
        */
        int node_Value();
        /* using for tracking(debuging) and print elements*/
        friend ostream &operator<<(ostream &input, const ADTNode &);
    };

};

#endif // !ADT_NODE_HPP