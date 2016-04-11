#include <string>
#ifndef _HMAP_H
#define _HMAP_H
#include "llist.h"
using namespace std;


class hmap{
    private:
    LinkedList* arrayOfPointers[2000000]; //One for each ASCII character possibility
    unsigned int hashMachine(const void * key, int len, unsigned int seed);
    public:
    hmap();
    bool is_in(string key);
    void set(string key, int value);
    void remove(string key);
    int get(string key);
    LinkedList* getList();
};

#endif