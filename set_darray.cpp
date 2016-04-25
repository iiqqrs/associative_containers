#include <iostream>
#include "set_darray.h"
using namespace std;

set_darray::set_darray(){
    darray newArray;
    setDarray = newArray;
}

void set_darray::insert(string key){
    if(setDarray.is_in(key)){
        cout << "Duplicate keys not allowed" << endl;
        return;
    }
    setDarray.insert(key);
}

void set_darray::remove(string key, bool all){
    setDarray.remove(key, all);
}

bool set_darray::is_in(string key){
    return setDarray.is_in(key);
}

bool set_darray::is_empty(){
    return setDarray.is_empty();
}
