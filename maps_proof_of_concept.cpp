/*
begin() – Returns an iterator to the first element in the map.
end() – Returns an iterator to the theoretical element that follows the last element in the map.
size() – Returns the number of elements in the map.
max_size() – Returns the maximum number of elements that the map can hold.
empty() – Returns whether the map is empty.
pair insert(keyvalue, mapvalue) – Adds a new element to the map.
erase(iterator position) – Removes the element at the position pointed by the iterator.
erase(const g)– Removes the key-value ‘g’ from the map.
clear() – Removes all the elements from the map.
*/

//website sign in screen

#include <iostream>
#include <map>
using namespace std;

int main(){
    //declare map object (2 data types)
    map<string, string> mapObj;
    mapObj["Lucas Hasting"] = "1234";
    string Username;
    string Password;

    cout << "Username: ";
    getline(cin, Username);

    cout << endl << "Password: ";
    getline(cin, Password);

    if (mapObj[Username] == Password)
        cout << "Success" << endl;
    else
        cout << "Failed to sign in" << endl;

    return 0;
}
