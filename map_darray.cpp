#include <iostream>
#include "llist.cpp"
#include "set_darray.h"
#include "darray.cpp"
using namespace std;

map_darray::map_array(){
    intNode map[size];
    count = 0;
    size = 10000;
}

void map_darray::doubleArray() { //Tried finishing it but not sure if it's right so someone check lol
    size *= 2;
    Node *array2 = new Node*[size];
    for (int = 0; i < count; i++) {
        array2[i] = map[i];
    }
}

bool isFound = true;

void map_darray::set(string key, int value){
    if (size = count) {
        doubleArray();
    }
    for (int i = 0; i < count; i++) {
        if (map[i].key = key) {
            map[i].value = value;
            isFound = true;
        }
        return;
    }
}

void map_darray::get(string key) {
    for (int i = 0; i < count; i++) {
        if (map[i].key = key) {
            return map[i].value = value;
        }
    }
}

void map_darray::remove(string key) {
    for (int i = 0; i < count; i++) {
        if (map[i].key = key) {
            return map[i].key = "DELETED";
        }
    }
}

int& map_darray::operator[](string key){
    int blahblah = get(key);
    int *blahblah = new int(blahblah)
    return blahblah;
}

/*
main(){
    cout << "Please enter key" << endl;
    cin >> key;
}
*/