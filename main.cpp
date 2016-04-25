#include <iostream>
#include <fstream>
#include <cassert>
#include "multiset_hmap.h"
#include "multiset_darray.h"
#include "multiset_llist.h"
#include "map_darray.h"
#include "map_llist.h"
#include "map_hmap.h"
using namespace std;

int main(){

  ifstream sets ("sets.txt");
  ifstream results ("results.txt");
  string buff;
  
  //Set stuff
  multiset_llist* m_llist = new multiset_llist();
  multiset_hmap* m_hmap = new multiset_hmap();
  multiset_darray* m_darray = new multiset_darray();
  
  //Results stuff
  map_llist* results_ll = new map_llist();
  map_hmap* results_hmap = new map_hmap();
  map_darray* results_darray = new map_darray();
  
  //Insert each line into each of the 3 sets (easy because no parsing this works as is)
  while(getline(sets, buff)){
    m_llist->insert(buff);
    m_hmap->insert(buff);
    m_darray->insert(buff);
  }
  
  string iterator;
  while(getline(results, iterator)){ 
    string stringVal;
    int intVal;
    results >> stringVal >> intVal;
    results_ll->set(stringVal, intVal);
    results_hmap->set(stringVal, intVal);
    results_darray->set(stringVal, intVal);
  }
  
  results.close();

  
  sets.close();
  ifstream newSets ("sets.txt");
  string newBuff;
  while (getline(newSets, newBuff)) {
    
    string setVal;
    newSets >> setVal;
    if (!newSets) {
      break;
    }
    assert(m_llist->count(setVal) == (*results_hmap)[setVal]);
    int valHMAP = m_hmap->count(setVal);
    assert(valHMAP == (*results_darray)[setVal]);
    int valDARRAY = m_darray->count(setVal);
    assert(valDARRAY == (*results_ll)[setVal]);
    
    cout << "Current word: " << setVal << endl;
    cout << "Count from multiset: " << m_llist->count(setVal) << endl;
    cout << "Count from map: " << (*results_darray)[setVal] << endl;
    cout << endl;
  }
  
  cout << "All tests pass" << endl;
  
  //Clean up
  sets.close();
  
  delete m_llist;
  delete m_hmap;
  delete m_darray;
  
  delete results_ll;
  delete results_darray;
  delete results_hmap;
}