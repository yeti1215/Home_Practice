
/* 
 * File:   main.cpp
 * Author: Ting Yin Sha
 * Created on November 3, 2022, 3:02 PM
 * Project: Gaddis Chapter13 problem1#Date
 */

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>

using namespace std;
//Declare class here

#include "classdate.h"


int main(int argc, char** argv) {
    srand(static_cast<unsigned int>(time(0)));
    //declare local variable here
    int m;
    int d;
    int y;
    Date date;
    //get the month day year from the user
    m=rand()%12+1;  //month range 1-12
    d=rand()%31+1;  //day range 1-31
    y=rand()%3+2020; //year range 2020-2022
    //store month day year of the Date class in the date object
    date.setMonth(m);
    date.setDay(d);
    date.setYear(y);
    
    //display the Date's data value
    date.printDate();
    
    

    return 0;
}

