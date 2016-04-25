using namespace std;
#include "darray.h"
#ifndef _MULTISET_DARRAY_H
#define _MULTISET_DARRAY_H
#include "llist.h"

class multiset_darray{
    private:
        string key;
        darray multisetArray;
    public:
        multiset_darray();
        void insert(string key);
        bool is_in(string key);
        unsigned long count(string key);
        void removeOne(string key);
        void removeAll(string key);
        bool is_empty();
};

#endif