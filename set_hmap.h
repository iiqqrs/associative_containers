using namespace std;
#include "hmap.h"
#ifndef _SET_HMAP_H
#define _SET_HMAP_H
class set_hmap {
    private:
    hmap hashMap;
    public:
    set_hmap();
    bool is_in(string key);
    void insert(string key);
    void remove(string key);
    bool is_empty();
};

#endif