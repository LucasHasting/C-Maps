#include <iostream>
using namespace std;

//Function Name: Encrypt
//Function Description: Takes in a password from user and enrypts using 
//						a Caeser Cipher.
//Incoming Parameters: string password, string con
//Outgoing Parameters: string con
//Return Value: result
string encrypt(string password, string& con)
{
	string result = "";
	con = "";

	for(int i = 0; i < password.length(); i++)
	{
		int passLength = password[i] + 20;
		if (passLength >= 127){
			result += char(((password[i] + 20) % 127)+32);
			con.push_back('t');
		}
		else{
			result += char((password[i] + 20) % 127);
			con.push_back('f');
			
		}
	}
	
	return result;
}

//Function Name: Decrypt
//Function Description: Takes in an encrypted password from user and decrypts using 
//						a Caeser Cipher.
//Incoming Parameters: string password, string con
//Outgoing Parameters: None
//Return Value: result
string decrypt(string password, string con) 
{
	string result = "";
	for(int i = 0; i < password.length(); i++)
	{
		if (con[i] == 't')
			result += char((password[i] - 52) + 127);
		else{
			result += char((password[i] - 20) % 127);
			}
	}
	
	return result;
}

