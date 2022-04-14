

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
    
    ofstream outputFile;
    
    string name1, name2, name3;
    
    outputFile.open("Friends.txt");
    cout<<"Enter the names of three friends.\n";
    cout<<"Friend#1: ";
    cin>>name1;
    cout<<"Friend#2: ";
    cin>>name2;
    cout<<"Friend#3: ";
    cin>>name3;
    
    //write the names to file
    outputFile<<name1<<endl;
    outputFile<<name2<<endl;
    outputFile<<name3<<endl;
    cout<<"The names were saved to a file.\n";
    
    //close the file
    outputFile.close();
    
         

    return 0;
}

