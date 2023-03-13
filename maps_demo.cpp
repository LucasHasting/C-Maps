/*
METHODS TO DEMO:
erase(iterator position) – Removes the element at the position pointed by the iterator.
erase(const g)– Removes the key-value ‘g’ from the map.
at()
swap()
kep_comp()
value_comp()
lower_bound
emplace_hint()
emplace()
upperbound()
equal_range()
rend()
rbegin()
find()
crbegin()
crend()
cbegin()
cend()
*/

//www.geeksforgeeks.org/map-associative-containers-the-c-standard-template-library-stl/
//https://cplusplus.com/forum/general/136503/
#include <iostream>
#include <map>
using namespace std;

template <class T, class U>
void print_map(map<T, U> mapObj){
    typename map<T, U>::iterator it = mapObj.begin();
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

int main(){
    map<string, int> mapObj;
    mapObj["one"] = 1;
    mapObj["two"] = 2;
    mapObj["three"] = 3;
    map<string, int> mapObj2 = mapObj;
    print_map<string, int>(mapObj);
    cout << endl;

    mapObj.clear();
    print_map<string, int>(mapObj);
    cout << "The key \"one\" present: " << boolalpha << mapObj.count("one") << endl; // figure out this one
    mapObj.insert({"one", 1});
    mapObj.insert(pair<string, int>("two", 2));
    cout << endl;
    print_map<string, int>(mapObj);
    cout << "key named \"one\": " << mapObj["one"] << endl;
    mapObj = mapObj2;

    cout << endl;
    print_map<string, int>(mapObj);
}
