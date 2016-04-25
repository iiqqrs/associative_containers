#include "darray.h"
#include "llist.h"
#include <string>
#include <iostream>
#include <cassert>
using namespace std;

darray::darray(){
    size = 0;
}


int darray::getIndex(string key){
    for(int i=0; i<size; i++){
        if((*(dynamicArray+i)).stringVal == key){
            return i;
        }
    }
    cout << " Shouldnt get here because index must exist to call getindex" << endl;
}

void darray::makeBigger(){
    size += 1;
    arr_Node* temp = dynamicArray;
    dynamicArray = new arr_Node[size];
    if(size-1 == 0){
        return;
    }
   
    for(int i=0; i < size-1; i++){
        arr_Node node;                  //To be deleted???
        (*(dynamicArray+i)) = (*(temp + i));
    }
    
}

arr_Node* darray::getArray(){
    return dynamicArray;
}

int darray::getSize(){
    return size;
}

bool darray::is_in(string key){
    for(int i = 0; i < size; i++){
        if(((*(dynamicArray+i)).stringVal).compare(key.c_str()) == 0){
            return true;
        }
    }
    return false;
}

void darray::insert(string key){
    int i =0;
    if(is_in(key)){
        for(i=0; i < size; i++){
            if((*(dynamicArray+i)).stringVal == key){
                (*(dynamicArray+i)).counter +=1;
            }
        }
    }
    else {
        makeBigger();
        arr_Node* pTemp = new (dynamicArray + size - 1) arr_Node();
        
        pTemp->stringVal.assign(key);
        pTemp->isIn = true;
        pTemp->counter += 1;
        
    }
}

void darray::remove(string key, bool all){
    if(is_in(key) == false){
        cout << "There is nothing in here to delete" << endl;
    }
    if(is_in(key)){
        int index_remove;
        bool skip = false;
        for(int i=0; i<size; i++){
            if((*(dynamicArray+i)).stringVal == key){
                index_remove = i;
                break;
            }
        }
        
        if(all || occurences(key) <= 1){
            arr_Node* temp = dynamicArray;
            size -= 1;
            dynamicArray = new arr_Node[size];
            int i = 0;
            while(i < index_remove){
                cout << (*(temp + i)).stringVal << endl;
                (*(dynamicArray+i)) = (*(temp + i));
                i++;
            }
            while(i<size){
                (*(dynamicArray+i)) = (*(temp + i+1));
                i++;
            }   
        }else{
            (*(dynamicArray+index_remove)).counter -=1;
        }
    }
}

bool darray::is_empty(){
    int i = 0;
    
    for(i = 0; i < size; i++){
        if((*(dynamicArray + i)).isIn == true){
            return false;
        }
    }
    return true;
}

int darray::occurences(string key){
    if(is_empty() || !is_in(key)){
        return 0;
    }
    else{
        for(int i=0; i<size; i++){
            if((*(dynamicArray+i)).stringVal == key){
                return (*(dynamicArray+i)).counter;
            }
        }
    }
}

//Insertion for map and multi map
void darray::set(string key, int value){
    if (is_in(key)) {
        (*(dynamicArray+getIndex(key))).intList.addNode(value, key);
        (*(dynamicArray+getIndex(key))).intCounter += 1;
        (*(dynamicArray+getIndex(key))).counter +=1;
    }else{
        insert(key);
        (*(dynamicArray+getIndex(key))).intList.addNode(value, key);
        (*(dynamicArray+getIndex(key))).intCounter += 1;
    }
    return;
}

//I think this is complete
int& darray::getSingle(string key) {
    if(is_in(key)) {
        int& value = ((dynamicArray+getIndex(key)))->intList.getStarter()->intVal;
        return value;
    }
}

//I think this is complete
int* darray::getList(string key) { 
    int* nullReturn = NULL;
    if (is_in(key)) {
        int numInts = (*(dynamicArray+getIndex(key))).intCounter; //intCounter contains the number of nodes in the intVal LinkedList
        int* intList = new int[numInts];
        intNode* values = (*(dynamicArray+getIndex(key))).intList.getStarter();
        for(int i = 0; i < numInts; i++) {
            (*(intList+i)) = (values->intVal);
            values = values->nextNode;
        }
        return ((intList));
    }
    else {
        cout << "Key is not in the list" << endl;
        return nullReturn;
    }
}

