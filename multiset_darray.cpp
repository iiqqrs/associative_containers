#include <iostream>
#include "multiset_darray.h"
using namespace std;


multiset_darray::multiset_darray(){
    darray newArray;
    multisetArray = newArray;
}

void multiset_darray::insert(string key){
    multisetArray.insert(key);
}

bool multiset_darray::is_in(string key){
    return multisetArray.is_in(key);
}

bool multiset_darray::is_empty(){
    return multisetArray.is_empty();
}

unsigned long multiset_darray::count(string key){
    return multisetArray.occurences(key);
}

void multiset_darray::removeOne(string key){
    return multisetArray.remove(key, false);
}

void multiset_darray::removeAll(string key){
    return multisetArray.remove(key, true);
}