#ifndef _MULTIMAP_HMAP_H_
#define _MULTIMAP_HMAP_H_
#include "hmap.h"

using namespace std;

class multimap_hmap {
    private:
        hmap hashMap;
        
    public:
        multimap_hmap();
        void set(string key, int value);
        void removeAll(string key);
        int  count(string key);
        int* getAll(string key); 
};

#endif