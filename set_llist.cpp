#include <iostream>
#include "set_llist.h"
using namespace std;

set_llist::set_llist(string key) {
    LinkedList* newLinkedList = new LinkedList(key);
    list = newLinkedList;
}

set_llist::set_llist() {
    LinkedList* newLinkedList = new LinkedList();
    list = newLinkedList;
}
    
void set_llist::insert(string key){
    if (is_in(key)) {
        cout << "Key already in set" << endl;
    }else{
        list->addNode(key);
        cout << "Key added" << endl;
    }
}

bool set_llist::is_in(string key){
    return list->contains(key);
}

void set_llist::remove(string key){
    if(is_in(key)){
        list->removeNode(key);
        cout << "Key removed" << endl;
    }else{
        cout << "Key Doesnt Exist" << endl;
    }
}

bool set_llist::is_empty(){
    return list->empty();
}
