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

refrences: https://www.vbforums.com/showthread.php?168659-Password-Mask-with-cin
https://stackoverflow.com/questions/3745861/how-to-remove-last-character-put-to-stdcout
https://stackoverflow.com/questions/2310939/remove-last-character-from-c-string
https://www.geeksforgeeks.org/map-associative-containers-the-c-standard-template-library-stl/
https://brilliant.org/wiki/caesar-cipher/#:~:text=A%20Caesar%20cipher%20is%20a,an%20A%2C%20and%20so%20on.
*/


#include <iostream>
#include <map>
#include <conio.h>
using namespace std;

string enter_password();
void menu2(map<string, string> &mapObj, string username);

void change_username(map<string,string> &mapObj, string username)
{
    cin.ignore();

    string password = mapObj[username];
    mapObj.erase(username);

    cout << "New Username: ";
    getline(cin, username);
    cout << endl;

    mapObj[username] = password;
}

void change_password(map<string,string> &mapObj, string username)
{
    string Password1;
    string Password2;

    cout << "Change Password: ";
    Password1 = enter_password();

    cout << "Retype New Password: ";
    Password2 = enter_password();

    if (Password1 == Password2)
        cout << "Password Successfully changed";
    else
    {
        cout << "Password Change Failed";
        return;
    }

    mapObj[username] = Password1;
    return;
}

string enter_password(){
    int key;
    string password = "";
    while(key!=13)
    {
        key = getch();
        if (password == "" && key == 8)
            continue;

        if (key == 8)
        {
            cout << '\b';
            cout << " ";
            cout << '\b';
            password.pop_back();
            continue;
        }

        if (key != 13)
        {
            password += char(key);
            cout<<"*";
        }
    }
    cout << endl;
    return password;
}

bool Authenicate(map<string, string> mapObj, string username, string password){
     return (mapObj[username] == password);
}

void sign_in(map<string, string> &mapObj){
    string Username;
    string Password;

    cin.ignore();
    cout << "Username: ";
    getline(cin, Username);

    cout << "Password: ";
    Password = enter_password();

    bool auth = Authenicate(mapObj, Username, Password);

    if (auth)
    {
        cout << "Success" << endl;
        menu2(mapObj, Username);
    }
    else
        cout << "Failed to sign in" << endl;
}

void create_account(map<string, string> &mapObj){
    string Username;
    string Password1;
    string Password2;

    cin.ignore();
    cout << "Create Username: ";
    getline(cin, Username);

    cout << "Create Password: ";
    Password1 = enter_password();

    cout << "Retype Password: ";
    Password2 = enter_password();

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

void remove_account(map<string, string> mapObj){
    string Username;
    string Password;

    cin.ignore();

    cout << "Username: ";
    getline(cin, Username);

    cout << "Password: ";
    getline(cin, Password);

    bool auth = Authenicate(mapObj, Username, Password);

    if (!auth)
    {
        cout << "Failed to authenticate" << endl;
        return;
    }

    cout << "Successfully removed account" << endl;
    mapObj.erase(Username);
}

void menu(map<string, string> &mapObj){
    int choice;

    do {
        cout << "Sign in:        1" << endl;
        cout << "Create Account: 2" << endl;
        cout << "Quit:           0" << endl;
        cout << "Enter: ";
        cin >> choice;
        cout << endl;

        switch(choice)
        {
            case 1:
                sign_in(mapObj);
                break;
            case 2:
                create_account(mapObj);
                break;
            case 0:
                return;
            default:
                cout << "try a different option" << endl;
        }

        cout << endl << endl;
    } while (choice >= 0 || choice <= 2);
}

void menu2(map<string, string> &mapObj, string username){
    int choice;
    cout << endl;
    cout << "You have successfully logged into someone's application" << endl;
    cout << "Here you can alter your account" << endl << endl;

    do{
        cout << "Change Username: 1" << endl;
        cout << "Change Password: 2" << endl;
        cout << "Delete Account:  3" << endl;
        cout << "Sign out:        0" << endl;
        cout << "Enter: ";
        cin >> choice;
        cout << endl;

        switch(choice)
        {
            case 1:
                change_username(mapObj, username);
                break;
            case 2:
                change_password(mapObj, username);
                break;
            case 3:
                remove_account(mapObj);
                break;
            case 0:
                return;
            default:
                cout << "try a different option" << endl;
        }
        cout << endl;

    } while (choice >= 0 || choice <= 3);

}

int main(){
    //declare map object (2 data types)
    map<string, string> mapObj;
    menu(mapObj);

    return 0;
}
