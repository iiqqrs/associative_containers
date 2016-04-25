#include <iostream>
#include <string>
#include <cstdlib>
#include "darray.h"
#ifndef _LLIST_H
#define _LLIST_H
using namespace std;

struct intNode {
    int intVal;
    string stringVal;
    intNode* prevNode;
    intNode* nextNode;
    //int* multVal;
    //int valCount;
    bool isIn;
    unsigned long counter;
    intNode(){
        isIn = true;
        intVal = 0;
        stringVal;
        prevNode = 0;
        nextNode = 0;
        counter = 0;
        //multVal = 0;
        //valCount = 0;
    }
};

//The linked list class; contains the algorithm for creating, maintaing , adding, removing, and searching a linked list.
class LinkedList{
    public:
    LinkedList();
    LinkedList(int integVal, string key);
    LinkedList(string key);
    void addNode(int integVal, string key);
    void addNode(string key);
    void removeNode(int integVal);
    void removeNode(string key);
    void printList();
    intNode* searchNode(int value);
    intNode* searchNode(string key);
    intNode* nextNode();
    intNode* getStarter();
    intNode* createNode(int integVal, string key);
    intNode* createNode(string key);
    bool contains(string key);
    bool empty();
    void increaseCount(string key);
    void decreaseCount(string key);
    unsigned long getCount(string key);
    private:
    bool is_empty = true;
    intNode* starterNode;
    intNode* nodeOnDeck;
    
};

#endif