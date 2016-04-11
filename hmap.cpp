//Hash Map
#include "hmap.h"
#include "llist.h"
using namespace std;

hmap::hmap() {
    
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

bool hmap::is_in(string key) {
    //int index = hashMachine(key);
    unsigned int index = hashMachine(&*key.begin(), key.size(), 1337);
    cout << "Index value is: " << index << endl;
    cout << "Problem?" << endl;
    if ((arrayOfPointers[index]->getStarter()->stringVal) == key) {
        cout << "Dis guy?" << endl;
        return true;
    }
    else {
        cout << "Problem??" << endl;
        intNode* node = arrayOfPointers[index]->getStarter();
        while (node != NULL) {
            cout << "Or dis guy?" << endl;
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

void hmap::set(string key, int value) { //the int value could also be a bool for Set (true==1, false==0)
    //int index = hashMachine(key);
    unsigned int index = hashMachine(&*key.begin(), key.size(), 1337);
    
    if (arrayOfPointers[index] == NULL) {
        
        LinkedList newList;
        arrayOfPointers[index] = &newList;
    }
    //
    //problem child
    cout << "index is " << index << endl;
    //cout << (&(*(arrayOfPointers[index]))) << endl; Good test to see where the pointer's pointing
    (*(arrayOfPointers[index])).addNode(value, key);
    cout << "end" << endl;
}

void hmap::remove(string key){
    if (!(is_in(key))) {
        return;
    }else{
        //int index = hashMachine(key);
        unsigned int index = hashMachine(&*key.begin(), key.size(), 1337);
        arrayOfPointers[index]->removeNode(key);
        return;
    }
    return;
}

int hmap::get(string key) {
    int index = 1;
    if (is_in(key)) {
        cout << "Jesse loves this" <<endl;
        //int index = hashMachine(key);
        unsigned int index = hashMachine(&*key.begin(), key.size(), 1337);

        if ((arrayOfPointers[index]->getStarter()->stringVal) == key) {
            return arrayOfPointers[index]->getStarter()->intVal;
        }
        else {
            intNode* node = arrayOfPointers[index]->getStarter();
            while (node != NULL) {
                if (node->stringVal == key) {
                    return node->intVal;
                }
                else {
                    node = node->nextNode;
                }
            }
        }
    }
    else {
        cout << "The value does not exist" << endl;
        return 0;
    }
}

LinkedList* hmap::getList() {
    return *(arrayOfPointers);
}

