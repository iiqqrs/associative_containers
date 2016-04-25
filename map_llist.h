#ifndef _MAP_LLIST_H_
#define _MAP_LLIST_H_
#include "llist.h"

using namespace std;

class map_llist {
    private:
        LinkedList* list;
        
    public:
        map_llist();
        void set(string key, int value);
        void remove(string key);
        int  get(string key);
        int& operator[](string key);
};

#endif