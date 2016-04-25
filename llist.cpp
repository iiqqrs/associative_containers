#include <iostream>
#include <string>
#include "llist.h"
#include "darray.h"
using namespace std;

//Constructor
LinkedList::LinkedList(int integVal, string key) {
    intNode* newNodePtr = createNode(integVal, key);
    newNodePtr->intVal = integVal;
    newNodePtr->stringVal = key;
    
    this->is_empty = false;
    this->starterNode = newNodePtr;
    this->nodeOnDeck = newNodePtr;
}

LinkedList::LinkedList(string key){
    intNode* newNodePtr = createNode(key);
    newNodePtr->stringVal = key;
    
    this->is_empty = false;
    this->starterNode = newNodePtr;
    this->nodeOnDeck = newNodePtr;
}

//Default constructor
LinkedList::LinkedList(){
    
}

//createNode()
intNode* LinkedList::createNode(int integVal, string key) {
    intNode* nodePtr = new intNode;
    
    nodePtr->intVal = integVal;
    nodePtr->stringVal = key;
    if (contains(key)) {
        searchNode(key)->counter += 1;
    }
    else {
        nodePtr->counter +=1;
    }
    return nodePtr;
}

intNode* LinkedList::createNode(string key) {
    intNode* nodePtr = new intNode;
    
    nodePtr->stringVal = key;
    nodePtr->counter += 1;
    return nodePtr;
}

//nextNode()
intNode* LinkedList::nextNode(){
    return nodeOnDeck;
}


//addNode()
void LinkedList::addNode(int integVal, string key){
    if(is_empty){
        intNode* newNodePtr = createNode(integVal, key);
        newNodePtr->intVal = integVal;
        newNodePtr->stringVal = key;
        
        
        this->is_empty = false;
        this->starterNode = newNodePtr;
        this->nodeOnDeck = newNodePtr;
        
    }
    else{
        intNode* addedNodePtr = createNode(integVal, key);
        nodeOnDeck->nextNode = addedNodePtr;
        addedNodePtr->prevNode = nodeOnDeck;
        nodeOnDeck = addedNodePtr;
    }
    
}

void LinkedList::addNode(string key){
    if (this->is_empty) {
        intNode* newNodePtr = createNode(key);
        newNodePtr->stringVal = key;
        
        this->is_empty = false;
        this->starterNode = newNodePtr;
        this->nodeOnDeck = newNodePtr;
    }
    else {
        intNode* addedNodePtr = createNode(key);
        
        nodeOnDeck->nextNode = addedNodePtr;
        
        addedNodePtr->prevNode = nodeOnDeck;
        nodeOnDeck = addedNodePtr;
    }
}

void LinkedList::removeNode(string key){
    if(is_empty){
        return;
        // cant remove when no nodes
    }else{
        if(contains(key)){
            
            intNode* removedNodePtr = new intNode;
            removedNodePtr = searchNode(key);
            //In the case of a node between 2 nodes
            if (removedNodePtr != getStarter() & removedNodePtr->nextNode != 0) {
                removedNodePtr->prevNode->nextNode = removedNodePtr->nextNode;
                removedNodePtr->nextNode->prevNode = removedNodePtr->prevNode;
                delete removedNodePtr;
            }
            //In the case of the terminal node
            else if (removedNodePtr->nextNode == 0) {
                if(getStarter() == removedNodePtr){
                    this->is_empty = true;
                    delete removedNodePtr;
                    return;
                }else{
                    removedNodePtr->prevNode->nextNode = 0;
                    nodeOnDeck = removedNodePtr->prevNode;
                    delete removedNodePtr;
                }
            }
            //In the case of the starter node
            else{
                (removedNodePtr->nextNode)->prevNode = 0;
                starterNode = removedNodePtr->nextNode;
                delete removedNodePtr;
            }
        }
    }
}

intNode* LinkedList::searchNode(string key){
    intNode *keyNode =  NULL;
    intNode *order = getStarter();

    while (order != 0) {
        if (order->stringVal == key) {
            return order;
        }
        else {
            order = order->nextNode;
            continue;
        }
       
    }
    cout << "Entry doesn't exist." << endl;
    return keyNode;
}

//getStarter(): returns the head of the linked list
intNode* LinkedList::getStarter(){
    if(is_empty){
        return NULL;
    }
    return starterNode;
}

void LinkedList::printList() {
    intNode* order = this->getStarter();
    while (order != 0) {
      cout<< order->intVal << " " << order->stringVal << endl;
      order = order->nextNode;
    }
    return;
}

bool LinkedList::contains(string key){
    intNode* order = this->getStarter();
    while (order != 0){
        if(order->stringVal == key){
            return true;
        }
      order = order->nextNode;
    }
    return false;
}

bool LinkedList::empty(){
    if(this->is_empty){
        return true;
    }
    return false;
}

void LinkedList::increaseCount(string key) {
    intNode* desiredNode = searchNode(key);
    desiredNode->counter +=1;
}

void LinkedList::decreaseCount(string key) {
    intNode* desiredNode = searchNode(key);
    desiredNode->counter -=1;
}

unsigned long LinkedList::getCount(string key) {
    if (contains(key) == false) {
        return 0;
    }
    return searchNode(key)->counter;
}
