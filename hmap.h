#include <string>
using namespace std;
#ifndef _HMAP_H
#define _HMAP_H
#include "llist.h"

class hmap{
    private:
        LinkedList* arrayOfPointers;
        unsigned int hashMachine(const void * key, int len, unsigned int seed);
        int entries;
    public:
        hmap();
        bool is_in(string key);
        void set(string key, int value);
        void set(string key);
        void remove(string key);
        int get(string key);
        bool is_empty();
        LinkedList* getList(string key);
        unsigned long getCount(string key);
};

#endif