#include <iostream>
#include "llist.h"
#include "map_llist.h"
using namespace std;

map_llist::map_llist() {
    list = new LinkedList();
}

void map_llist::set(string key, int value) {
    if (list->contains(key)) {
        cout << "Entry already in the map." << endl;
    }
    else {
        list->addNode(value, key);
    }
}

int map_llist::get(string key) {
    int value = 0;
    if (list->contains(key) == false) {
        cout << "Entry is not contained in the list" << endl;
    }
    else {
        value = (*(list->searchNode(key))).intVal;
    }
    return value;
}

void map_llist::remove(string key) {
   if (list->contains(key) == false) {
       cout << "Entry is not contained in the list" << endl;
   }
   else {
       list->removeNode(key);
   }
}


int& map_llist::operator[](string key){
    int nullVal = 0;
    //This doesn't work...But I don't think we need a check. The build in [] operator throws an error when
    //an invalid index is trying to be acccessed...
    /*if (list->contains(key) == false) {
        cout << "Entry is not contained in the list" << endl;
        return nullVal;
    }*/
    return list->searchNode(key)->intVal;
}