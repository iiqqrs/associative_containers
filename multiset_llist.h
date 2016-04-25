#include <iostream>
#include "llist.h"
using namespace std;
#ifndef _MULTISET_LLIST_H
#define _MULTISET_LLIST_H

class multiset_llist {
    private:
    LinkedList* list;
    public:
    multiset_llist();
    multiset_llist(string key);
    void insert(string key);
    bool is_in(string key);
    unsigned long count(string key);
    void removeOne(string key);
    void removeAll(string key);
    bool is_empty();
};

#endif