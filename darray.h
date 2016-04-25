#ifndef _DARRAY_H
#define _DARRAY_H
#include "llist.h"
#include <string>
using namespace std;
/*
Info: 
Helpful multi use functions that can be used for all data strutures
Notes:
might need to make more variables to handle different different data tructures*/

struct arr_Node {
    int intVal;
    string stringVal;
    bool isIn;
    int counter;
    int intCounter;
    LinkedList intList; //for multimap
    arr_Node(){
        isIn = false;
        intVal=0;
        stringVal;
        counter = 0;
        intCounter = 0;
    }
};

class darray {
    private:
        arr_Node* dynamicArray = NULL;
        int size = 0;
        int getIndex(string key);
    public:
        darray();
        void makeBigger();
        void insert(string key);
        bool is_in(string key);
        void remove(string key, bool all);
        bool is_empty();
        void set(string key, int value);
        int&  getSingle(string key);
        int* getList(string key);
        arr_Node* getArray();
        int getSize();
        int occurences(string key);
};
#endif