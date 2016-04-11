#include <iostream>
#include "llist.cpp"
#include "set_llist.h"
#include "darray.cpp"
using namespace std;

map::map() {
    map = NULL;
}

void map::set(string key, int value) {
    Node* newNode = new Node;
    newNode -> key = key;
    newNode -> value = value;
    map = newNode;
}

void map::remove(string key) {
    if (map -> key = key) {
        //dude idk tbh
    }
}

int& map_darray::operator[](string key){
    int blahblah = get(key);
    int *blahblah = new int(blahblah)
    return blahblah;
}