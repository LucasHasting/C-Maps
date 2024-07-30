/*
Names: Lucas Hasting, Ethan Nix, Krutivas Pradhan
Course: CS 355
Assignment: Assignment 8
Date: 2/23/2023
Program Description: Create an account management system for some application
File Name: driver.cpp
*/

#include "maps.h"

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