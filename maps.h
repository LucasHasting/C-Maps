/*
Names: Lucas Hasting, Ethan Nix, Krutivas Pradhan
Course: CS 355
Assignment: Assignment 8
Date: 2/23/2023
Program Description: Create an account management system for some application
File Name: maps.h
*/

#ifndef MAPS_H
#define MAPS_H

#include <map>
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
void load_map(map<string, string> &mapObj);
void write_map(map<string, string> mapObj);

//constants
const int PRINT_AMOUNT = 70;

#endif
