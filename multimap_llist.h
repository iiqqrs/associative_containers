#ifndef _MULTIMAP_LLIST_H_
#define _MULTIMAP_LLIST_H_
#include "llist.h"
using namespace std;

class multimap_llist {
    private:
        LinkedList* list;
        
    public:
        multimap_llist();
        void set(string key, int value);
        void removeAll(string key);
        int  count(string key);
        int* getAll(string key); 
};

#endif