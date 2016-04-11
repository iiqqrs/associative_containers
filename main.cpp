#include <iostream>
#include "llist.h"
#include "darray.h"
#include "hmap.h"
using namespace std;

int main(){


    darray *newArray = new darray();
    //cout << "List is empty?: " << newArray->is_empty() << endl;
    //newArray->set("Andrew", 23);
    //cout << "Should be false: " << newArray->is_in("Andrew") <<endl;
    newArray->insert("Andrew");
    newArray->insert("Andrew");
    //cout << "Should be true: " << newArray->is_in("Andrew") <<endl;
    newArray->remove("Andrew", true);
    //cout << "Should be false: " << newArray->is_in("Andrew") <<endl;
    delete newArray;
    
    
    LinkedList *ll = new LinkedList();
    //cout << "Should be false " << ll->contains("Hello") <<endl;
    ll->addNode("Hello");
    //cout << "Should be true " << ll->contains("Hello") <<endl;
    ll->removeNode("Hello");
    //cout << "Should be false " << ll->contains("Hello") <<endl;
    //ll->addNode("Test");
    //ll->printList();
    delete ll;

    hmap *h = new hmap();
    h->set("test", 3);
    int value = h->get("test");
    cout << "The value is " << value << endl;

    delete h;
}
