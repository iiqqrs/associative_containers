#include <iostream>
#include "map_darray.h"
#include "darray.h"
using namespace std;

map_darray::map_darray() {
    
}

void map_darray::set(string key, int value) {
    if (array.is_in(key)) {
        cout << "Key value pair already in map" << endl;
    }
    else {
        array.set(key, value);
    }
}

int map_darray::get(string key) {
    int value = 0;
    if (array.is_in(key) == false) {
        cout << "Key value pair not contained in the map" << endl;
    }
    else {
        value = array.getSingle(key);
    }
    return value;
}


void map_darray::remove(string key) {   
    if(array.is_in(key)) {
        array.remove(key, false);
    }
    else {
        cout << "Value key pair is not contained in the map" << endl;
    }
}

int& map_darray::operator[](string key){
   
    return (array.getSingle(key));
}