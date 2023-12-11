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

//function declarations
void create_account(map<string, string> &mapObj);
void remove_account(map<string, string> &mapObj, string current_user);
void change_username(map<string,string> &mapObj, string username);
void change_password(map<string,string> &mapObj, string username);
bool authenicate(map<string, string> mapObj, string username, string password);
void sign_in(map<string, string> &mapObj);
void mainMenu(map<string, string> &mapObj);
void subMenu(map<string, string> &mapObj, string username);
string enter_password();
string encrypt(string password, string& key);
string encrypt(string password);
string decrypt(string password, string key);
string decrypt(string password);
void print_seperator();

//templated function declarations
template <class T, class U>
void write_map(map<T, U> mapObj);

template <class T, class U>
void load_map(map<T, U> &mapObj);

//constants
const int PRINT_AMOUNT = 70;

//Drive function
int main(){
    //declare map object (2 data types)
    map<string, string> mapObj;

    //load the map from a file
    load_map(mapObj);

    //display someone's application
    print_seperator();
    mainMenu(mapObj);

    //write the new map to a file
    write_map(mapObj);

    return 0;
}

/*
Function Name: create_account
Function Description: create's an account for a user
Incoming: map
Outgoing: map
Return: None
Function Contribution: Lucas Hasting
*/
void create_account(map<string, string> &mapObj)
{
    //declare variables
    string Username;
    string Password1;
    string Password2;

    //ignore cin for getline()
    cin.ignore();

    //get input for the username and password
    cout << "Create Username: ";
    getline(cin, Username);

    cout << "Create Password: ";
    Password1 = enter_password();

    cout << "Retype Password: ";
    Password2 = enter_password();

    //checks if the passwords match
    if (Password1 == Password2)
        cout << "Account Creation Succeeded";
    else
    {
        cout << "Account Creation Failed";
        return;
    }

    //create a new map element of username that maps to password
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
void remove_account(map<string, string> &mapObj, string current_user)
{
    //declare variables
    string Username;
    string Password;

    //ignore cin for getline()
    cin.ignore();

    //get input for password
    cout << "Password: ";
    Password = enter_password();

    //re-authenticates user to make sure no one else is trying to delete their account
    bool auth = authenicate(mapObj, current_user, Password);
    if (!auth)
    {
        cout << "Failed to authenticate";
        return;
    }

    //removes the account from the map
    cout << "Successfully removed account";
    mapObj.erase(current_user);
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
    //ignores cin for getline()
    cin.ignore();

    //saves the password
    string password = mapObj[username];

    //deletes the username element in the map
    mapObj.erase(username);

    //gets input for username
    cout << "New Username: ";
    getline(cin, username);

    //creates a new map element with the new username and the saved password
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
    //declare variables
    string Password1;
    string Password2;

    //get input for the password
    cout << "Change Password: ";
    Password1 = enter_password();

    cout << "Retype New Password: ";
    Password2 = enter_password();

    //makes sure the passwords match
    if (Password1 == Password2)
    {
        cout << "Password Successfully changed" << endl;
    }
    else
    {
        cout << "Password Change Failed" << endl;
        return;
    }

    //changes the password for the username element
    mapObj[username] = Password1;
    return;
}

/*
Function Name: authenticate
Function Description: authenticates a user trying to sign in
Incoming: authenticate
Outgoing: None
Return: mapObj[username] == password
Function Contribution: Lucas Hasting
*/
bool authenicate(map<string, string> mapObj, string username, string password)
{
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
void sign_in(map<string, string> &mapObj)
{
    string Username;
    string Password;

    //ignores cin for getline()
    cin.ignore();

    //gets input for username and password
    cout << "Username: ";
    getline(cin, Username);

    cout << "Password: ";
    Password = enter_password();

    //check if that map element with that password exists
    bool auth = authenicate(mapObj, Username, Password);
    if (auth)
    {
        //authentication successful
        cout << "Success" << endl;
        subMenu(mapObj, Username);
    }
    else
        cout << "Failed to sign in";
}

/*
Function Name: mainMenu
Function Description: displays the main menu and chooses according options
Incoming: map
Outgoing: map
Return: None
Function Contribution: Lucas Hasting
*/
void mainMenu(map<string, string> &mapObj)
{
    //declare choice variable
    int choice;

    //loop the menu until user chooses an appropriate option
    do {
        cout << "Sign in:        1" << endl;
        cout << "Create Account: 2" << endl;
        cout << "Quit:           0" << endl;
        cout << "Enter: ";
        cin >> choice;
        print_seperator();

        //decides what function is called based on the user's choice
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

        cout << endl;
        print_seperator();
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
void subMenu(map<string, string> &mapObj, string username)
{
    //declare choice variable
    int choice;

    //let the user know they have signed in successfully
    print_seperator();
    cout << "You have successfully logged into someone's application" << endl;
    cout << "Here you can alter your account" << endl;
    print_seperator();

    //loop the menu until user chooses an appropriate option
    do{
        cout << "Change Username: 1" << endl;
        cout << "Change Password: 2" << endl;
        cout << "Delete Account:  3" << endl;
        cout << "Sign out:        0" << endl;
        cout << "Enter: ";
        cin >> choice;
        print_seperator();

        //decides what function is called based on the user's choice
        switch(choice)
        {
            case 1:
                change_username(mapObj, username);
                break;
            case 2:
                change_password(mapObj, username);
                break;
            case 3:
                remove_account(mapObj, username);
                return;
            case 0:
                return;
            default:
                cout << "try a different option" << endl;
        }
        print_seperator();

    } while (choice >= 0 || choice <= 3);

}

/*
Function Name: enter_password
Function Description: gets the password from the user and masks the inpuit
Incoming: None
Outgoing: password
Return: password
Function Contribution: Lucas Hasting
*/
string enter_password()
{
    //declare variables
    int key;
    string password = "";

    //while the user does not press enter
    while(key!=13)
    {
        //get input
        key = getch();

        //if there is no password and the user presses backspace, continue
        if (password == "" && key == 8)
            continue;

        //if the input is backspace
        if (key == 8)
        {
            //delete the last key from cout
            cout << '\b';
            cout << " ";
            cout << '\b';

            //remove the last key from the password
            password.pop_back();
            continue;
        }

        //if the key's input was not enter
        if (key != 13)
        {
            password += char(key);

            //show the mask
            cout<<"*";
        }
    }
    cout << endl;
    return password;
}

/*
Function Name: encrypt
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
	    //shift
		int passLength = password[i] + 20;

		//check if it exceeds ascii range
		if (passLength >= 127){
			result += char(((password[i] + 20) % 127)+32);

			//Generate key T
			key.push_back('T');
		}
		else{
			result += char((password[i] + 20) % 127);

			//Generate key F
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
Function Name: decrypt
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
	    //check key
		if (key[i] == 'T')
			result += char((password[i] - 52) + 127);
		else{
			result += char((password[i] - 20) % 127);
			}
	}

	return result;
}

/*
Function Name: decrypt
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
    //declare variables
    ofstream outfile;
    string username;
    string password;
    string key1;
    string key2;

    outfile.open("encrypted.txt");

    //checks if the map is empty, if so, delete the output file
    if(mapObj.empty())
    {
        outfile.close();
        remove("encrypted.txt");
        return;
    }

    //declare iterator for map
    typename map<T, U>::iterator it = mapObj.begin();

    //first loop case
    //set the username and password
    username = it->first;
    password = it->second;

    //encrypt username and password
    username = encrypt(username, key1);
    password = encrypt(password, key2);

    //encrypt the keys
    key1 = encrypt(key1);
    key2 = encrypt(key2);

    //write the data to a file
    outfile << username << endl << key1 << endl << password << endl << key2;

    ++it;

    while (it != mapObj.end())
    {
        //every following loop
        //set the username and password
        username = it->first;
        password = it->second;

        //encrypt username and password
        username = encrypt(username, key1);
        password = encrypt(password, key2);

        //encrypt the keys
        key1 = encrypt(key1);
        key2 = encrypt(key2);

        //write the data to a file
        outfile << endl << username << endl << key1 << endl << password << endl << key2;

        ++it;
    }
    //close the file
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
    //check if input file exists
    ifstream infile("encrypted.txt");

    if (infile.fail())
        return;

    //declare variables
    typename map<T, U>::iterator it = mapObj.begin();
    string username;
    string password;
    string key1;
    string key2;

    //loops until it reaches end of file
    while (!infile.eof())
    {
        //get the encrypted username, password, and key
        getline(infile,username);
        getline(infile, key1);
        getline(infile,password);
        getline(infile, key2);

        //decrypt the key
        key1 = decrypt(key1);
        key2 = decrypt(key2);

        //load the decrypted username and password
        mapObj[decrypt(username, key1)] = decrypt(password, key2);
    }
    infile.close();
}

void print_seperator(){
    for (int i = 0; i < PRINT_AMOUNT; i++)
        cout << "-";
    cout << endl;
}
