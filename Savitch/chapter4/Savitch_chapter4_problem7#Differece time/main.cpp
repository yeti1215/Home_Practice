

/* 
 * File:   main.cpp
 * Author: yeti
 * Created on April 15, 2022, 8:58 AM
 * Project: The difference time
 */

#include <iostream>

using namespace std;

int computeDifference(int, int,  int, int);

int main(int argc, char** argv) {
    int hoursN, minutesN, hoursF, minutesF; //START TIME, FUTRUE TIME
    bool isAMn, isAMf; // AM OR PM

    cout << "Enter start hour" << endl;
    cin>>hoursN;
    cout << "Enter start minutes " << endl;
    cin>>minutesN;
    cout << "Enter 1 for AM, 0 for PM " << endl;
    cin>>isAMn;

    cout << "Enter future hour" << endl;
    cin>>hoursF;
    cout << "Enter future minutes " << endl;
    cin>>minutesF;
    cout << "Enter Am or PM " << endl;
    cin>>isAMf;

    if (isAMn) {
        cout << "Start time is " << hoursN << ":" << minutesN << " AM" << endl;
    } else cout << "Start time is " << hoursN << ":" << minutesN << " PM" << endl;
    ;

    if (isAMf) {
        cout << "Future time is " << hoursF << ":" << minutesF << " AM" << endl;
    } else cout << "Future time is " << hoursF << ":" << minutesF << " PM" << endl;
    
   cout<<"The time Difference in minutes is " <<computeDifference( hoursN, minutesN, hoursF, minutesF);

    return 0;
}



int computeDifference( int hoursN, int minutesN, int hoursF, int minutesF ){
    int Diff;
    minutesN= hoursN*60+minutesN;
    minutesF= hoursF*60+minutesF;
    
    if(minutesF >= minutesN)Diff= minutesF-minutesN;
    if(minutesF < minutesN) Diff= 24*60-(minutesN-minutesF);
    
    return Diff;
    
    
}