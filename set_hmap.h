using namespace std;
#include "hmap.h"
#ifndef set_hmap.h
#define set_hmap.h
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