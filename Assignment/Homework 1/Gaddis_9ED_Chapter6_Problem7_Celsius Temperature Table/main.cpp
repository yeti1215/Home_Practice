

/* 
 * File:   main.cpp
 * Author: Ting Yin Sha
 * Created on September 3, 2022, 10:07 PM
 * Project: Celsius Temperature Table
 */

#include <iostream>
#include <iomanip>

using namespace std;

float CtoF(int F);
int main(int argc, char** argv) {
    // Declare variables here
    int F=0;
    float C;
    
    while(F<20){
        
       C=CtoF(F);
       cout<<C<<endl;
        F++;
    }
    
    
    //Input the Celsius 
   


    //Display the input and output


    return 0;
}
float CtoF(int F){
    int C;
    C=5*float(F)/9-32;
    
    return C;
}