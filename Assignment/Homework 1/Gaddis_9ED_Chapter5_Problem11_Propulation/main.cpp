

/* 
 * File:   main.cpp
 * Author: Ting Yin Sha
 * Created on September 3, 2022, 10:07 PM
 * Project: Days in a Month
 */

#include <iostream>
#include <iomanip>

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    // Declare variables here
    int startN, days,size;
    float  rate;
    cout<<"Please enter a starting number of organisms:";
    cin>>startN;
    cout<<"Enter the average daily population increase :";
    cin>>rate;
    rate =rate/100;
    cout<<rate<<endl;
    cout<<"Enter the days:";
    cin>>days;
    
    if(startN>=2 && rate>=0 && days>1){
        for(int i=0; i<days; i++){
            startN +=startN*rate;
            cout<<"The population of "<<i<<" day: "<<startN<<endl;
        }
    }
    
    
    
    //Input the Celsius 
   


    //Display the input and output


    return 0;
}

