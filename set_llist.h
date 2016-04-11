#include <iostream>
using namespace std;
#ifndef set_llist.h
#define set_llist.h

class set_llist{
    private:
    LinkedList list;
    public:
    set_llist(string key);
    set_llist();
    void insert(string key);
    bool is_in(string key);
    void remove(string key);
    bool is_empty();
};