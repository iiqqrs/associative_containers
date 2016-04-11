//Dynamic Array
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
    dynamicArray = (arr_Node*) malloc(sizeof(arr_Node)*size);
    
    if(size-1 == 0){
        delete temp;
        //delete[] temp;
        //free (temp);
        return;
    }
    
    
    for(int i=0; i < size-1; i++){
        (*(dynamicArray+i)) = (*(temp + i));
    }
    delete temp;
    //delete[] temp;
    //free(temp);
}

arr_Node* darray::getArray(){
    return dynamicArray;
}

int darray::getSize(){
    return size;
}

bool darray::is_in(string key){
    for(int i = 0; i < size; i++){
        if((*(dynamicArray+i)).stringVal == key){
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
                //increment
                (*(dynamicArray+i)).counter +=1;
            }
        }
    }
    else {
        makeBigger();
        arr_Node temp;
        arr_Node* pTemp = new (dynamicArray + size - 1) arr_Node();
        temp = *pTemp;
        pTemp->stringVal = key;
        
        delete pTemp;
    }
}

void darray::remove(string key, bool all){
    if(is_in(key)){
        int index_remove;
        bool skip = false;
        for(int i=0; i<size; i++){
            if((*(dynamicArray+i)).stringVal == key){
                index_remove = i;
            }
        }
        if(all || occurences(key) <= 1){
            arr_Node* temp = dynamicArray;
            size -= 1;
            dynamicArray = (arr_Node*) malloc(sizeof(arr_Node)*size);

            int i;
            while(i != index_remove & i < index_remove){
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
        //Look at node with key "key" and return count attribute
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
    }else{
        insert(key);
        (*(dynamicArray+getIndex(key))).intList.addNode(value, key);
        (*(dynamicArray+getIndex(key))).intCounter += 1;
    }
    return;
}

//I think this is complete
int darray::getSingle(string key) {
    if(is_in(key)) {
        int value = (*(dynamicArray+getIndex(key))).intList.getStarter()->intVal;
        return value;
    }
    else {
        cout << "Key is not in the list" << endl;
        return 0;
    }
   
}

//I think this is complete
int* darray::getList(string key) { 
    int* nullReturn = NULL;
    if (is_in(key)) {
        int numInts = (*(dynamicArray+getIndex(key))).intCounter; //intCounter contains the number of nodes in the intVal LinkedList
        int* intList[numInts];
        intNode* values = (*(dynamicArray+getIndex(key))).intList.getStarter();
        for(int i = 0; i < numInts; i++) {
            (*(*(intList+i))) = (values->intVal);
            values = values->nextNode;
        }
        return (*(intList));
    }
    else {
        cout << "Key is not in the list" << endl;
        return nullReturn;
    }
}
