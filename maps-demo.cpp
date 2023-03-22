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

// www.geeksforgeeks.org/map-associative-containers-the-c-standard-template-library-stl/
// https://cplusplus.com/forum/general/136503/
#include <iostream>
#include <map>
#include <fstream>
using namespace std;





template <class T, class U>
void print_map(map<T, U> mapObj)
{
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

// SAVE 
template <class T, class U>
void write_map(map<T, U> mapOb, string string_arr[])
{
    ofstream outfile;
    outfile.open("output.txt");

    typename map<T, U>::iterator it = mapObj.begin();
    while (it != mapObj.end())
    {
        it->first = encrypt(it->first, string_arr[i]);
        it->second = encrypt(it->second, string_arr[i]);
        outfile << it->first << endl << it->second << endl;
        ++it;
    }
    outfile.close();
}

// LOAD
template <class T, class U>
void load_map(map<T, U> mapObj, string* string_arr)
{
    int file_length = 0;
    ifstream infile("input.txt");
    while (infile.is_open())
        ++file_length;
    infile.close();

    string_arr = new string[file_length / 2];
    //LOAD FROM FILE
    typename map<T, U>::iterator it = mapObj.begin();
    string username;
    string password;
    ifstream infile("input.txt");
    int i = 0;
    while (infile.is_open())
    {
        //get username and password
        getline(infile,username);
        getline(infile,password);
         
        //load the decrypted username and password
        mapObj[decrypt(username, string_arr[i])] = decrypt(password, string_arr[i]);
        ++i;
    }
    infile.close();
}

//it->second = decrypt(it->second)




int main()
{
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

    
    // erase(position);
    // erase(const g);
    // at<string, int>(mapObj);
    // swap<string, int>(mapObj);
    // kep_comp<string, int>(mapObj);
    // value_comp<string, int>(mapObj);
    // lower_bound<string, int>(mapObj);
    // emplace_hint<string, int>(mapObj);
    // emplace<string, int>(mapObj);

}