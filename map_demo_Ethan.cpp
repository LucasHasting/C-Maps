#include <iostream>
#include <map>
using namespace std;

int main(){
    map<string, int> mapObj;
    mapObj["one"] = 1;
    mapObj["two"] = 2;
    mapObj["three"] = 3;
    
    //upper_bound() :: returns an iterator pointing to the immediate 
	//next element just greater than k.
    auto i = mapObj.upper_bound("two");
    cout << "The upper bound of key 2 is ";
    cout << i->first << " " << i->second << endl;
    
    //equal_range() :: Returns the bounds of a range that includes all the elements in 
	//the container which have a key equivalent to k.
	pair<map<string, int>::iterator, map<string, int>::iterator> it;
 	it = mapObj.equal_range("one");
 	
 	//rend() :: Returns a reverse iterator pointing to the theoretical element 
	//right before the first key-value pair in the map
	
	//rbegin() :: Returns a reverse iterator which points to the last element of the map.
	for (auto it = mapObj.rbegin(); it != mapObj.rend(); ++it) {
  
        cout << it->first
             << " = "
             << it->second
             << endl;
    }
   
   //find() :: Returns an iterator or a constant iterator 
   // that refers to the position where the key is present in the map
	auto k = mapObj.find("one");
	
	
	//crbegin() :: returns a constant reverse iterator referring to the 
	// last element in the map container.
	
	//crend() :: eturns a constant reverse iterator pointing to the theoretical 
	// element before the first element in the map
	for (auto itr = mapObj.crbegin(); itr != mapObj.crend(); ++itr) {
        cout << itr->first
             << '\t' << itr->second;
    }
	
    
    //cbegin() ::  returns a constant iterator referring to the first element 
	// in the map container.
	
	//cend() :: returns a constant iterator pointing to the theoretical element 
	// that follows the last element in the multimap.
	for (auto j = mapObj.cbegin(); j != mapObj.cend(); ++j) {
        cout << j->first
             << '\t' << j->second << '\n';
    }
    
    
    return 0;
 
}