

/* 
 * File:   main.cpp
 * Author: Ting Yin Sha
 * Created on September 3, 2022, 10:07 PM
 * Project: Currency
 */

#include <iostream>
#include <iomanip>

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
// Declare variables here
    
   
    //Input the Celsius 
    float dollar, yen, euro;
    float rateY=140.21,
        rateE=1.00;
    cout<<"Currency exchange rate:"<<endl;
    cout<<fixed<<setprecision(2)<<showpoint;
    cout<<"1 Dollar = "<<rateY<<" Yen"<<endl;
    cout<<"1 Dollar = "<<rateE<<" Euros"<<endl;
    cout<<endl;
    //Display the input and output
    cout<<"Input the U.S amount:"<<endl;
    cin>>dollar;
    yen=dollar*rateY;
    euro=dollar*rateE;
    
    cout<<dollar<<" Dollar ="<<yen<<" Yen"<<endl;
    cout<<dollar<<" Dollar ="<<euro<<" Euros"<<endl;

    
    return 0;
}

