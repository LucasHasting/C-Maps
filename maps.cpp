/*
Names: Lucas Hasting, Ethan Nix, Krutivas Pradhan
Course: CS 355
Assignment: Assignment 8
Date: 2/23/2023
Program Description: Create an account management system for some application
File Name: maps.cpp
File Contribution: Lucas Hasting, Ethan Nix, Krutivas Pradhan

refrences: https://www.vbforums.com/showthread.php?168659-Password-Mask-with-cin
https://stackoverflow.com/questions/3745861/how-to-remove-last-character-put-to-stdcout
https://stackoverflow.com/questions/2310939/remove-last-character-from-c-string
https://www.geeksforgeeks.org/map-associative-containers-the-c-standard-template-library-stl/
https://brilliant.org/wiki/caesar-cipher/#:~:text=A%20Caesar%20cipher%20is%20a,an%20A%2C%20and%20so%20on.
*/

#include <iostream>
#include <map>
#include <conio.h>
#include <fstream>
using namespace std;

string enter_password();
void subMenu(map<string, string> &mapObj, string username);

/*
Function Name: Decrypt
Function Description: Takes in an non-encrypted password from user and encrypts using a Caeser Cipher.
Incoming: password, key
Outgoing: key
Return: result
Function Contribution: Ethan Nix
*/
string encrypt(string password, string& key)
{
	string result = "";
    key = "";
	for(int i = 0; i < password.length(); i++)
	{
		int passLength = password[i] + 20;
		if (passLength >= 127){
			result += char(((password[i] + 20) % 127)+32);
			key.push_back('T');
		}
		else{
			result += char((password[i] + 20) % 127);
			key.push_back('F');
		}
	}

	return result;
}

/*
Function Name: encrypt
Function Description: Overloaded encrypt function to encrypt the key
Incoming: password
Outgoing: None
Return: result
Function Contribution: Ethan Nix
*/
string encrypt(string password)
{
	string result = "";

	for(int i = 0; i < password.length(); i++)
	{
        result += char((password[i] + 20) % 127);
	}

	return result;
}

/*
Function Name: Decrypt
Function Description: Takes in an encrypted password from user and decrypts using a Caeser Cipher.
Incoming: password, key
Outgoing: None
Return: result
Function Contribution: Ethan Nix
*/
string decrypt(string password, string key)
{
	string result = "";
	for(int i = 0; i < password.length(); i++)
	{
		if (key[i] == 'T')
			result += char((password[i] - 52) + 127);
		else{
			result += char((password[i] - 20) % 127);
			}
	}

	return result;
}

/*
Function Name: Decrypt
Function Description: Overloaded decrypt function to decrypt the key
Incoming: password
Outgoing: None
Return: result
Function Contribution: Ethan Nix
*/
string decrypt(string password)
{
	string result = "";
	for(int i = 0; i < password.length(); i++)
	{
        result += char((password[i] - 20) % 127);
	}

	return result;
}

/*
Function Name: write_map
Function Description: writes the map into an encrypted text file
Incoming: map
Outgoing: None
Return: None
Function Contribution: Krutivas Pradhan
*/
template <class T, class U>
void write_map(map<T, U> mapObj)
{
    ofstream outfile;
    outfile.open("encrypted.txt");
    string username;
    string password;
    string key1;
    string key2;

    typename map<T, U>::iterator it = mapObj.begin();

    username = it->first;
    password = it->second;

    username = encrypt(username, key1);
    password = encrypt(password, key2);

    key1 = encrypt(key1);
    key2 = encrypt(key2);

    ++it;

    while (it != mapObj.end())
    {
        username = it->first;
        password = it->second;

        username = encrypt(username, key1);
        password = encrypt(password, key2);

        key1 = encrypt(key1);
        key2 = encrypt(key2);

        ++it;
    }
    outfile.close();
}

/*
Function Name: load_map
Function Description: loads the map from an encrypted text file
Incoming: map
Outgoing: None
Return: None
Function Contribution: Krutivas Pradhan
*/
template <class T, class U>
void load_map(map<T, U> &mapObj)
{
    ifstream infile("encrypted.txt");

    if (infile.fail())
    {
        return;
    }

    //LOAD FROM FILE
    typename map<T, U>::iterator it = mapObj.begin();
    string username;
    string password;
    string key1;
    string key2;

    int i = 0;
    while (!infile.eof())
    {
        //get username and password
        getline(infile,username);
        getline(infile, key1);
        getline(infile,password);
        getline(infile, key2);

        key1 = decrypt(key1);
        key2 = decrypt(key2);

        //load the decrypted username and password
        cout << decrypt(username, key1) << " " << decrypt(password, key2) << endl;
        mapObj[decrypt(username, key1)] = decrypt(password, key2);
        ++i;
    }
    infile.close();
}

/*
Function Name: change_username
Function Description: changes a user's name in someone's application
Incoming: map, username
Outgoing: map
Return: None
Function Contribution: Lucas Hasting
*/
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

/*
Function Name: change_password
Function Description: changes a user's password in someone's application
Incoming: map, username
Outgoing: map
Return: None
Function Contribution: Lucas Hasting
*/
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

/*
Function Name: enter_password
Function Description: gets the password from the user and masks the inpuit
Incoming: None
Outgoing: password
Return: password
Function Contribution: Lucas Hasting
*/
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

/*
Function Name: authenticate
Function Description: authenticates a user trying to sign in
Incoming: authenticate
Outgoing: None
Return: mapObj[username] == password
Function Contribution: Lucas Hasting
*/
bool authenicate(map<string, string> mapObj, string username, string password){
     return (mapObj[username] == password);
}

/*
Function Name: sign_in
Function Description: decides if the user can gain access to someone's application
Incoming: map
Outgoing: map
Return: None
Function Contribution: Lucas Hasting
*/
void sign_in(map<string, string> &mapObj){
    string Username;
    string Password;

    cin.ignore();
    cout << "Username: ";
    getline(cin, Username);

    cout << "Password: ";
    Password = enter_password();

    bool auth = authenicate(mapObj, Username, Password);

    if (auth)
    {
        cout << "Success" << endl;
        subMenu(mapObj, Username);
    }
    else
        cout << "Failed to sign in" << endl;
}

/*
Function Name: create_account
Function Description: create's an account for a user
Incoming: map
Outgoing: map
Return: None
Function Contribution: Lucas Hasting
*/
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

/*
Function Name: remove_account
Function Description: removes a user's account
Incoming: map
Outgoing: None
Return: None
Function Contribution: Lucas Hasting
*/
void remove_account(map<string, string> mapObj){
    string Username;
    string Password;

    cin.ignore();

    cout << "Username: ";
    getline(cin, Username);

    cout << "Password: ";
    Password = enter_password();

    bool auth = authenicate(mapObj, Username, Password);

    if (!auth)
    {
        cout << "Failed to authenticate" << endl;
        return;
    }

    cout << "Successfully removed account" << endl;
    mapObj.erase(Username);
}

/*
Function Name: mainMenu
Function Description: displays the main menu and chooses according options
Incoming: map
Outgoing: map
Return: None
Function Contribution: Lucas Hasting
*/
void mainMenu(map<string, string> &mapObj){
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

/*
Function Name: subMenu
Function Description: displays the sub menu and chooses according options
Incoming: map, username
Outgoing: map
Return: None
Function Contribution: Lucas Hasting
*/
void subMenu(map<string, string> &mapObj, string username){
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

//Drive function
int main(){
    //declare map object (2 data types)
    map<string, string> mapObj;
    load_map(mapObj);
    mainMenu(mapObj);
    write_map(mapObj);


    return 0;
}
