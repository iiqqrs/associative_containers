#include "llist.h"
#include "multiset_llist.h"
#include <iostream>

using namespace std;

multiset_llist::multiset_llist(){
 LinkedList* newLinkedList = new LinkedList();
 list = newLinkedList;
}

multiset_llist::multiset_llist(string key){
 LinkedList* newLinkedList = new LinkedList(key);
 list = newLinkedList;
}

void multiset_llist::insert(string key){
    if (list->contains(key)) {
        list->increaseCount(key);
    }
    else {
         list->addNode(key);
    }
}

bool multiset_llist::is_in(string key){
    bool isIn = true;
    if (list->contains(key) == false) {
        isIn = false;
    }
    
    return isIn;
}

bool multiset_llist::is_empty(){
    return list->empty();
}

unsigned long multiset_llist::count(string key){
    return list->getCount(key);
}

void multiset_llist::removeOne(string key){
    if (list->getCount(key) == 1) {
        list->removeNode(key);
    }
    else {
        list->decreaseCount(key);
    }
}

void multiset_llist::removeAll(string key){
    list->removeNode(key);
}