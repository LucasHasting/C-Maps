/*
Names: Lucas Hasting, Ethan Nix, Krutivas Pradhan
Course: CS 355
Assignment: Assignment 8
Date: 2/23/2023
Program Description: Demonstrate the different map methods
File Name: maps_demo.cpp
File Contribution: Lucas Hasting, Ethan Nix, Krutivas Pradhan

refrence: https://www.geeksforgeeks.org/map-associative-containers-the-c-standard-template-library-stl/
*/

#include <iostream>
#include <map>
using namespace std;

/*
Function Name: print_map
Function Description: prints all the values in a map
Incoming: map
Outgoing: None
Return: None
Function Contribution: Copied and edited from Geek for Geeks by Lucas Hasting
*/
template <class T, class U>
void print_map(map<T, U> mapObj){
    //iterator object for looping through the object (starting at the beginning)
    typename map<T, U>::iterator it = mapObj.begin();

    //loops until the map reaches its end
    while (it != mapObj.end())
    {
        cout << "Key: " << it->first << ", Value: " << it->second << endl;
        ++it;
    }
    cout << "Size of map: " << mapObj.size() << endl;
    cout << "Max size of the map: " << mapObj.max_size() << endl;
    cout << "The map is empty: " << boolalpha << mapObj.empty() << endl;

    return;
}

//driver function
int main(){

    //Under this line was done by Lucas------------------------------------------------------------s

    map<string, int> mapObj;

    //insert data
    mapObj["one"] = 1;
    mapObj["two"] = 2;
    mapObj["three"] = 3;

    //use of assignment operator to copy mapObj to mapObj2
    map<string, int> mapObj2 = mapObj;
    print_map<string, int>(mapObj);
    cout << endl;

    //clear the map object
    mapObj.clear();
    print_map<string, int>(mapObj);

    //check if key "one" is present
    cout << "The key \"one\" present: " << mapObj.count("one") << endl;

    //another way to insert
    mapObj.insert({"one", 1});
    mapObj.insert(pair<string, int>("two", 2));

    cout << endl;
    print_map<string, int>(mapObj);

    //Under this line was done by Ethan-----------------------------------------------------------------

    //upper_bound() :: returns an iterator pointing to the immediate
    //next element just greater than k.
    //auto i = mapObj.upper_bound("two");
    //cout << "The upper bound of key 2 is ";
    //cout << i->first << " " << i->second << endl;

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

    //Under this line was done by Krutivas------------------------------------------------------------------------

    std::map<int, std::string> myMap = {
        {1, "apple"},
        {2, "banana"},
        {3, "cherry"},
        {4, "date"},
        {5, "elderberry"}};

    // Erase the element with key 3
    myMap.erase(3);

    // Access the value associated with key 3 using the at() member function
    string value = myMap.at(1);
    cout << "The value associated with key 3 is: " << value << std::endl;

    // Swap the contents of the maps using the swap() member function

    //myMap1.swap(myMap2); // Swap was just for demonstration, it needs two maps but we have only one

    // Use the key comparator to compare keys
    map<int, string>::key_compare myKeyComp = myMap.key_comp();
    int key1 = 2;
    int key2 = 4;
    bool result = myKeyComp(key1, key2);

    // Use the value comparator to compare values
    map<int, string>::value_compare myValueComp = myMap.value_comp();
    auto it1 = myMap.find(2);
    auto it2 = myMap.find(4);
    result = myValueComp(*it1, *it2);

    // Use the lower_bound() member function to find the lower bound of a key
    auto it3 = myMap.lower_bound(2);
    cout << "The lower bound of key 2 is: " << it3->second;

    // Use the emplace_hint() member function to add a new key-value pair at a specific position
    auto it4 = myMap.emplace_hint(myMap.find(3), make_pair(6, "fig"));
    cout << "The value associated with key 6 is: " << it4->second;

    // Use the emplace() member function to add a new key-value pair
    auto it5 = myMap.emplace(6, "fig");
    cout << "The value associated with key 6 is: " << it5.first->second;
    return 0;
}
