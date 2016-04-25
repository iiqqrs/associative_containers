//Hash Map
#include "hmap.h"
#include "llist.h"
#include "darray.h"
using namespace std;

hmap::hmap(){
    arrayOfPointers = new LinkedList[2000000];
    entries = 0;
}

unsigned int hmap::hashMachine( const void * key, int len, unsigned int seed ){
	// 'm' and 'r' are mixing constants generated offline.
	// They're not really 'magic', they just happen to work well.

	const unsigned int m = 0x5bd1e995;
	const int r = 24;

	// Initialize the hash to a 'random' value

	unsigned int h = seed ^ len;

	// Mix 4 bytes at a time into the hash

	const unsigned char * data = (const unsigned char *)key;

	while(len >= 4)
	{
		unsigned int k = *(unsigned int *)data;

		k *= m; 
		k ^= k >> r; 
		k *= m; 
		
		h *= m; 
		h ^= k;

		data += 4;
		len -= 4;
	}
	
	// Handle the last few bytes of the input array

	switch(len)
	{
	case 3: h ^= data[2] << 16;
	case 2: h ^= data[1] << 8;
	case 1: h ^= data[0];
	        h *= m;
	};

	// Do a few final mixes of the hash to ensure the last few
	// bytes are well-incorporated.

	h ^= h >> 13;
	h *= m;
	h ^= h >> 15;

	return h%2000000;
} 

bool hmap::is_in(string key){
    unsigned int index = hashMachine(&*key.begin(), key.size(), 1337);
    //cout << "Index value is: " << index << endl;
    if((*(arrayOfPointers + index)).empty()){
        return false;
    }else{
        intNode* node = (*(arrayOfPointers+index)).getStarter();
        while (node != NULL){
            if (node->stringVal == key) {
                return true;
            }
            else {
                node = node->nextNode;
            }
        }
    }
    
    return false;
}


void hmap::set(string key) {
    unsigned int index = hashMachine(&*key.begin(), key.size(), 1337);
    if ((*(arrayOfPointers+index)).empty()){
        LinkedList newList;
        newList.addNode(key); 
        *(arrayOfPointers+index) = newList;
        entries +=1; // What is this for
    }else{
        (*(arrayOfPointers+index)).searchNode(key)->counter += 1;
        entries +=1;
    }
}

void hmap::set(string key, int value){
    unsigned int index = hashMachine(&*key.begin(), key.size(), 1337);
    if ((*(arrayOfPointers+index)).empty()){
        LinkedList newList;
        newList.addNode(value, key); 
        *(arrayOfPointers+index) = newList;
        entries +=1;
    }else{
        (*(arrayOfPointers+index)).addNode(value,key);
        entries +=1;
    }
}

void hmap::remove(string key){
    unsigned int index = hashMachine(&*key.begin(), key.size(), 1337);
    if(is_in(key)){
        while((arrayOfPointers+index)->contains(key)){
            (arrayOfPointers+index)->removeNode(key);
            entries -= 1;
        }
    }
    else {
        cout << "Key value pair is not contained within the table" << endl;
    }
}


bool hmap::is_empty(){
    if (entries == 0) {
        return true;
    }
    
    return false;
}

//For map only
int hmap::get(string key){
    unsigned int index = hashMachine(&*key.begin(), key.size(), 1337);
    if(is_in(key)){
        return (*(arrayOfPointers+index)).searchNode(key)->intVal;
    }
    return 0;
}
// also for map only
/*void hmap::set_map(string key, int value){
    unsigned int index = hashMachine(&*key.begin(), key.size(), 1337);
    if ((*(arrayOfPointers+index)).empty()){
        LinkedList newList;
        newList.addNode(value, key); 
        *(arrayOfPointers+index) = newList;
        entries +=1;
    }else{
        (*(arrayOfPointers+index)).getStarter()->stringVal = value;
    }
}*/


//For multimap
LinkedList* hmap::getList(string key){
    unsigned int index = hashMachine(&*key.begin(), key.size(), 1337);
    if((*(arrayOfPointers+index)).contains(key)){
        return ((arrayOfPointers+index));
    }
    return NULL;
}

unsigned long hmap::getCount(string key) {
    unsigned int index = hashMachine(&*key.begin(), key.size(), 1337);
    
    if((*(arrayOfPointers+index)).contains(key)){
        return (*(arrayOfPointers+index)).getCount(key);
    }
    else {
        return 0;
    }
}