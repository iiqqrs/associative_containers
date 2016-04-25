#ifndef _MULTISET_HMAP_H_
#define _MULTISET_HMAP_H_
#include "hmap.h"
using namespace std;

class multiset_hmap{
    private:
        hmap hashMap;
    public:
        multiset_hmap();
        unsigned long count(string key);
        void removeOne(string key);
        void removeAll(string key);
        bool is_in(string key);
        void insert(string key);
        bool is_empty();
};

#endif