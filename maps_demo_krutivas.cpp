
#include <iostream>
#include <map>
using namespace std;

int main()
{
    std::map<int, std::string> myMap = {
        {1, "apple"},
        {2, "banana"},
        {3, "cherry"},
        {4, "date"},
        {5, "elderberry"}};

    // Erase the element with key 3
    myMap.erase(3);

    // Access the value associated with key 3 using the at() member function
    string value = myMap.at(3);
    cout << "The value associated with key 3 is: " << value << std::endl;

    // Swap the contents of the maps using the swap() member function
    
    //myMap1.swap(myMap2); // Swap was just for demonstration, it needs two maps but we have only one 

    // Use the key comparator to compare keys
    map<int, string>::key_compare myKeyComp = myMap.key_comp();
    int key1 = 2;
    int key2 = 4;
    result = myKeyComp(key1, key2);

    // Use the value comparator to compare values
    map<int, string>::value_compare myValueComp = myMap.value_comp();
    auto it1 = myMap.find(2);
    auto it2 = myMap.find(4);
    result = myValueComp(*it1, *it2);

    // Use the lower_bound() member function to find the lower bound of a key
    auto it1 = myMap.lower_bound(2);
    cout << "The lower bound of key 2 is: " << it1->second;

    // Use the emplace_hint() member function to add a new key-value pair at a specific position
    auto it1 = myMap.emplace_hint(myMap.find(3), make_pair(6, "fig"));
    cout << "The value associated with key 6 is: " << it1->second;

    // Use the emplace() member function to add a new key-value pair
    auto it1 = myMap.emplace(6, "fig");
    cout << "The value associated with key 6 is: " << it1.first->second;
    return 0;
}