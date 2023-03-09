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

bool Authenicate(map<string, string> mapObj, string username, string password){
     return (mapObj[username] == password);
}

void sign_in(map<string, string> mapObj){
    string Username;
    string Password;

    cout << "Username: ";
    getline(cin, Username);

    cout << "Password: ";
    getline(cin, Password);

    bool auth = Authenicate(mapObj, Username, Password);

    if (auth)
        cout << "Success" << endl;
    else
        cout << "Failed to sign in" << endl;
}

void create_account(map<string, string> &mapObj){
    string Username;
    string Password1;
    string Password2;

    cout << "Create Username: ";
    getline(cin, Username);

    cout << "Create Password: ";
    getline(cin, Password1);

    cout << "Retype Password: ";
    getline(cin, Password2);

    if (Password1 == Password2)
        cout << "Account Creation Succeeded";
    else
    {
        cout << "Account Creation Failed";
        return;
    }

    mapObj[Username] = Password1;
    return;

}

int main(){
    //declare map object (2 data types)
    map<string, string> mapObj;
    create_account(mapObj);
    cout << endl << endl;
    sign_in(mapObj);

    return 0;
}
