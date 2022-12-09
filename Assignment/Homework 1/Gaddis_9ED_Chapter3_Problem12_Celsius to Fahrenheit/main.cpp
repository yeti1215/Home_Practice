

/* 
 * File:   main.cpp
 * Author: Ting Yin Sha
 * Created on September 3, 2022, 10:07 PM
 * Project: Celsius to Fahrenheit
 */

#include <iostream>

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
// Declare variables here
    
    int F,// F= Fahrenheit
        C;// C= Celsius
    
    //Input the Celsius 
    cout<<"Please enter Celsius temperature:"<<endl;
    cin>>C;
    
    F=9*C/5 +32;
    
    //Display the input and output
    
    cout<<"Celsius temperature "<<C<<" is Fahrenheit temperature "<<F<<endl;
    
    
    return 0;
}

