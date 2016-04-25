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
        cout << "Key already exist" << endl;
        return;
    }
    else {
        hashMap.set(key);
    }
}

void set_hmap::remove(string key) {
    if (is_in(key) == true) {
        hashMap.remove(key);
    }
   else {
       cout << "Key doesn't exist" << endl;
       return;
   }
}

bool set_hmap::is_empty() {
    return hashMap.is_empty();
}