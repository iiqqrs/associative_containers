using namespace std;
#ifndef _MAP_DARRAY_H_
#define _MAP_DARRAY_H_
#include "darray.h"

class map_darray {
    private:
        darray array;
    public:
        map_darray();
        void set(string key, int value);
        void remove(string key);
        int  get(string key);
        int& operator[](string key);
};

#endif