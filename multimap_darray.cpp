#include <iostream>
#include "multimap_darray.h"
#include "darray.h"
using namespace std;

multimap_darray::multimap_darray(){

}

void multimap_darray::set(string key, int value) {
    array.set(key, value);
}
void multimap_darray::removeAll(string key) {
     if (array.is_empty() || !array.is_in(key)) {
        cout << "Key is not contained in the array" << endl;
    }
    else {
        array.remove(key, true);
    }
}
int multimap_darray::count(string key) {
    if (array.is_empty() || !array.is_in(key)) {
        cout << "Key is not contained in the array" << endl;
        return 0;
    }
    else {
        return array.occurences(key);
    }   
}
int* multimap_darray::getAll(string key) {
    if (array.is_empty() || !array.is_in(key)) {
        cout << "Key is not contained in the array" << endl;
        return NULL;
    }
    
    else {
        return array.getList(key);
    }
    
}
