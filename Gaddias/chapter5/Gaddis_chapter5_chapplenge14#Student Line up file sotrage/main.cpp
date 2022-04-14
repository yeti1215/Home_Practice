

/* 
 * File:   main.cpp
 * Author: yeti
 * Created on April 13, 2022, 11:20 AM
 * Purpose: Student Line Up
 */

#include <iostream>
#include <fstream>
#include <string>

using namespace std;


int main(int argc, char** argv) {
    
    int number;
    string name, frontN, endN;
    
    ofstream outputFile;
    outputFile.open("Students_name.txt");
    
    cout<<"Enter the number of students: ";
    cin>>number;
    cout<<"enter the students name:";
        cin>>name;
        outputFile<<name<<endl;
        frontN=name;
        endN=name;
    
    for(int i=1; i<number; i++){
        cout<<"enter the students name:";
        cin>>name;
        outputFile<<name<<endl;
        if (name <= frontN)
            frontN=name;
        
        if( name >endN )
            
            endN=name;
    }
        cout<<"The front of the line is : "<<frontN<<endl;
        cout<<"The end of the line is : "<<endN<<endl;
     
outputFile.close();

    
   
         

    return 0;
}

