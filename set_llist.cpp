#include <iostream>
#include "set_llist.h"
using namespace std;

set_llist::set_llist(string key) {
    LinkedList newLinkedList(key);
    list = newLinkedList;
}

set_llist::set_llist() {
    LinkedList newLinkedList();
    list = newLinkedList;
}
    
void set_llist::insert(string key){
    if (is_in(key)) {
        cout << "Key already in set" << endl;
    }
    else {
    list.addNode(key);
    cout << "Key added" << endl;
    }
}

bool set_llist::is_in(string key){
    return list.contains(key);
}

void set_llist::remove(string key){
    list.removeNode(key);
    cout << "Key removed" << endl;
}

bool set_llist::is_empty(){
    return list.empty();
}
