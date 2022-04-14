

/* 
 * File:   main.cpp
 * Author: yeti
 * Created on April 13, 2022, 12:11 PM
 * purpose: read the student line up program
 */

#include <iostream>
#include <fstream>
#include <string>

using namespace std;


int main(int argc, char** argv) {
    
    string name;
    
    ifstream inputFile;
    inputFile.open("Students_name.txt");
    
    inputFile>>name;
    cout<<name<<endl;
    
     inputFile>>name;
    cout<<name<<endl;
    
    
   /*cout<<"Reading the date from the file.\n";
    if (inputFile){
        while(inputFile>>name){
            cout<<name<<endl;
        }
    }
    else{
        cout<<"Error opening the file.\n";
    }
    
    */
    
    inputFile.close();

    return 0;
}

