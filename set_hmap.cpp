#include <iostream>

#include "set_hmap.h"
using namespace std;

set_hmap::set_hmap() {
    hashMap = hmap();
}

bool set_hmap::is_in(string key) {
    bool isIn = hashMap.is_in(key);
    return isIn;
}

void set_hmap::insert(string key) {
    if (is_in(key) == true) {
        return;
    }
    else {
        hashMap.set(key, true);
    }
}

void set_hmap::remove(string key) {
    if (is_in(key) == true) {
        hashMap.remove(key);
    }
   else {
       return;
   }
}

bool set_hmap::is_empty() {
    bool isTrue = true;
    
    //LinkedList* *arrayOfPointers = hashMap.getList();
    
    for (int i = 0; i < 95; i++) {
        if (hashMap.getList()[i] == NULL) {
            continue;
        }
        else {
            isTrue = false;
            break;
        }
    }
    
    return isTrue;
}