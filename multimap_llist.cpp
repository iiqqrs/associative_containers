#include <iostream>
#include "multimap_llist.h"
#include "llist.h"
using namespace std;

multimap_llist::multimap_llist(){
    list = new LinkedList();
}

void multimap_llist::set(string key, int value) {
   list->addNode(value, key);
}
void multimap_llist::removeAll(string key) {
     while (list->contains(key)) {
         list->removeNode(key);
     }
     return;
}
int multimap_llist::count(string key) {
    if (!(list->contains(key) || list->empty())) {
        cout << "Key value pair is not contained in the list." << endl;
        return 0;
    }
    
    return list->getCount(key);
}

int* multimap_llist::getAll(string key) {
    if (list->contains(key)) {
        int* valSet = new int[list->getCount(key)];
        intNode* head = list->searchNode(key);
        
        int i = 0;
        while (head != NULL) {
            if(head->stringVal == key) {
                valSet[i] = head->intVal;
                i++;
            }
            head = head->nextNode;
        }
        return valSet;
    }
    else {
        cout << "Key value pair not contained in the list." << endl;
        return NULL;
    }
}
