#include <iostream>
#include "multimap_hmap.h"
#include "hmap.h"
using namespace std;

multimap_hmap::multimap_hmap(){
    hashMap = hmap();
}

void multimap_hmap::set(string key, int value) {
    hashMap.set(key, value);
}
void multimap_hmap::removeAll(string key) {
    hashMap.remove(key);
}

int multimap_hmap::count(string key) {
    int count = hashMap.getCount(key);
    return count;
}
int* multimap_hmap::getAll(string key) {
    LinkedList* list = hashMap.getList(key);
   
    if (list->empty() || (!(list->contains(key)))) {
        cout << "Key value pair not contained in the list." << endl;
        return NULL;
    }
    else {
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
}
