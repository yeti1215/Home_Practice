

/* 
 * File:   main.cpp
 * Author: yeti
 * Created on April 13, 2022, 11:20 AM
 * Purpose: practice using files for data storage
 */

#include <iostream>
#include <fstream>
#include <string>

using namespace std;


int main(int argc, char** argv) {
    
    ifstream inputFile;
    string name;
    
    inputFile.open("Friends.txt");
    cout<<"Reading data from the file.\n";
    
    inputFile>>name;
    cout<<name<<endl;
    
        inputFile>>name;
    cout<<name<<endl;
    
     inputFile>>name;
    cout<<name<<endl;
    
    inputFile.close();
    

    return 0;
}

