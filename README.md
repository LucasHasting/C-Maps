# C++ Maps Container
Project was created in my CS 355 (Data Structures and Algorithms) class. It was to find an applicable use of the STL map container. The project makes use of the map container as a means of authentication, as it replicates an account managaer with the ability to create and modify an account, login, and delete a logged in account. The encryption method for storing usernames and passwords was a slight modification to an ASCII cipher and should not be used in production as it is not secure. This project was done with the help of Ethan Nix and Krutivas Pradhan.  

## Table of Contents

- [Installation](#installation)
- [Compile-the-program](#compile-the-program)
- [Execute-the-program](#execute-the-program)
- [Usage](#usage)
- [Example](#example)
- [Program-Overview](#program-overview)

## Installation

The programs in this repository can be executed using the C++ language and the g++ compiler.

g++ for [Windows](https://sourceforge.net/projects/mingw/), don't forget to add the binary to the [path environment variable](https://www.architectryan.com/2018/03/17/add-to-the-path-on-windows-10/).

g++ can be installed on Linux using your favorite package manager.

### Option 1: using [git](https://git-scm.com/downloads)
1. Clone the repository:

    ```sh
    git clone https://github.com/LucasHasting/C-Maps.git
    ```

2. Navigate to the project directory:

    ```sh
    cd C-Maps
    ```
    
### Option 2: without git
1. Download the project as a zip file
2. [Extract the zip file](https://www.wikihow.com/Unzip-a-File)
3. Find the location of the files
4. Copy the path
5. go to the command line and run the following:
   ```sh
   cd /path/to/files
   ```

## Compile the program

### Option 1: using [Make](https://www.gnu.org/software/make/)
Run the following:
```sh
make all
```

### Option 2: without Make
Run the following:
```sh
g++ maps.cpp driver.cpp -o map
```

## Execute the program

### Windows
```sh
map.exe
```

### Linux/Mac
```sh
./map.out
```

## Usage
The program is a command line, menu based, user interface. By entering the number associated with an option it will perform a certain operation. The program has multiple menus, the first being the main menu where you can sign in, create an account, or exit the program. When creating an account it asks for the username and password, and the password is hidden using *. Upon successfull login you have the option to change the accounts username and password, along with deleteing the account, or you can choose to sign out.

## Example

![EXAMPLE](examples/example1.png)  
![EXAMPLE](examples/example2.png)  

## Program-Overview
[maps.cpp](): contains the account management simulation with the ASCII Cipher.  
[maps_demo.cpp](): contains a demonstration of how the map container can be used in C++.  
[encrypted.txt](): contains all encrypted accounts at all times.  
