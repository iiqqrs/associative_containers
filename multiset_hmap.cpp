#include <iostream>
#include "multiset_hmap.h"
#include "hmap.h"
using namespace std;

//Should be complete; just need to test it.
multiset_hmap::multiset_hmap(){
    hmap newArray;
    hashMap = newArray;
}

void multiset_hmap::insert(string key){
    hashMap.set(key);
}

bool multiset_hmap::is_in(string key){
    return hashMap.is_in(key);
}

bool multiset_hmap::is_empty(){
    return hashMap.is_empty();
}

unsigned long multiset_hmap::count(string key){
    return hashMap.getCount(key);
}

void multiset_hmap::removeOne(string key){
    if (hashMap.getCount(key) == 1) {
        hashMap.remove(key);
    }
    else if (hashMap.is_in(key)) {
        hashMap.getList(key)->decreaseCount(key);
    }
    else {
        cout << "Key is not stored" << endl;
    }
}

void multiset_hmap::removeAll(string key){
    if (hashMap.is_in(key)) {
        hashMap.remove(key);
    }
    else {
        cout << "Key is not stored" << endl;
    }
}