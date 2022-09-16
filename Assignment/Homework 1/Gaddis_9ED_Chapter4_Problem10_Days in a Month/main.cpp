

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
    int days, month, year;

    //Input the Celsius 
    cout << "Enter a month(1-12):";
    cin>>month;
    cout << "Enter a year:";
    cin>>year;
    switch (month) {
        
        case 2: if (year % 100 == 0 && year % 400 == 0) days = 29;
            if (year % 100 != 0 && year % 4 == 0) cout<<"29 days"<<endl;
            else cout<<"28 days"<<endl;
            break;
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12: cout<<"31 days"<<endl;
            break;
        case 4:
        case 6:
        case 9:
        case 11: cout<<"30 days"<<endl;
            break;
        default:cout << "Enter a month 1-12" << endl;
    }




    //Display the input and output


    return 0;
}

