using namespace std;
#ifndef set_darray
#define set_darray
#include "llist.h"

class set_darray {
    private:
    darray setArray;
    string temp;
    public:
    bool is_in(string key);
    void insert(string key);
    void remove(string key);
    bool is_empty();
};

#endif