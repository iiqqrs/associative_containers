using namespace std;
#ifndef _MULTIMAP_DARRAY_H_
#define _MULTIMAP_DARRAY_H_
#include "darray.h"

class multimap_darray {
    private:
        darray array;
    public:
        multimap_darray();
        void set(string key, int value);
        void removeAll(string key);
        int  count(string key);
        int* getAll(string key);    
};

#endif