#include <iostream>
using namespace std;

set_darray::set_array(){
    darray newArray;
    setArray = newArray;
}

void set_darray::insert(string key){
    if(setArray.is_in(key)){
        cout << "Duplicate keys not allowed" << endl;
        return;
    }
    setArray.insert(key);
}

void set_darray::remove(string key){
    setArray.remove(key);
}

bool set_darray::is_in(string key){
    return setArray.is_in(key);
}

bool set_darray::is_empty(){
    return setArray.is_empty()
}
