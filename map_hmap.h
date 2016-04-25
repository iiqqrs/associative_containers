using namespace std;
#ifndef _MAP_HMAP_H_
#define _MAP_HMAP_H_
#include "hmap.h"

class map_hmap{
    private:
        hmap hashMap;
    public:
        map_hmap();
        void set(string key, int value);
        void remove(string key);
        int get(string key);
        int& operator[](string key);    
};

#endif