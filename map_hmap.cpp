#include "map_hmap.h"
#include <iostream>
using namespace std;

map_hmap::map_hmap() {
    hashMap = hmap();
}

void map_hmap::set(string key, int value){
    if (!hashMap.is_in(key)){
        hashMap.set(key, value);
    }else{
        //we know that key exists
        (hashMap.getList(key))->searchNode(key)->intVal = value; //Like this?
    }
}

void map_hmap::remove(string key){
    hashMap.remove(key);
}

int map_hmap::get(string key){
    return hashMap.get(key);
}

int& map_hmap::operator[](string key){ // no idea why we're returning a obj
    return (hashMap.getList(key))->searchNode(key)->intVal;
}