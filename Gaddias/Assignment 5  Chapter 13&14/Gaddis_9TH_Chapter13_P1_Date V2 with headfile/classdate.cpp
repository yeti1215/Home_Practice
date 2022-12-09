

/* 
 * File:   main.cpp
 * Author: Ting Yin Sha
 * Created on November 3, 2022, 3:02 PM
 * Project: Gaddis Chapter13 problem1#Date
 */
#include "classdate.h"

#include <iostream>
#include <cstdlib>
#include <iomanip>

using namespace std;

void Date::setMonth(int m){
    month=m;  
}
void Date::setDay(int d){
    day=d;
}
void Date::setYear(int y){
    year=y;
}
int Date::getMonth() const
{
    return month;
}
int Date::getDay() const{
    return day;
}
int Date::getYear() const{
    return year;
}
void Date::printDate(){
    cout<<setw(2)<<setfill('0')<<right<<month<<"/"<<day<<"/"<<year<<endl;
    switch(month){
        case 1: cout<<"January "<<day<<", "<<year<<endl;
                cout<<day<<" "<<"January "<<year<<endl;
            break;
        case 2: cout<<"February "<<day<<", "<<year<<endl;
                cout<<day<<" "<<"February "<<year<<endl;
            break;
        case 3:  cout<<"March "<<day<<", "<<year<<endl;
                cout<<day<<" "<<"March "<<year<<endl;
            break;
        case 4: cout<<"April "<<day<<", "<<year<<endl;
                cout<<day<<" "<<"April "<<year<<endl;
            break;
        case 5: cout<<"May "<<day<<", "<<year<<endl;
                cout<<day<<" "<<"May "<<year<<endl;
            break;
        case 6: cout<<"June "<<day<<", "<<year<<endl;
                cout<<day<<" "<<"June "<<year<<endl;
            break;
        case 7:cout<<"July "<<day<<", "<<year<<endl;
                cout<<day<<" "<<"July "<<year<<endl;
            break;
        case 8:cout<<"August "<<day<<", "<<year<<endl;
                cout<<day<<" "<<"August "<<year<<endl;
            break;
        
        case 9: cout<<"September "<<day<<", "<<year<<endl;
                cout<<day<<" "<<"September "<<year<<endl;
            break;
        case 10:cout<<"October "<<day<<", "<<year<<endl;
                cout<<day<<" "<<"October "<<year<<endl;
            break;
        case 11:cout<<"November "<<day<<", "<<year<<endl;
                cout<<day<<" "<<"November "<<year<<endl;
            break;
            case 12:cout<<"December "<<day<<", "<<year<<endl;
                cout<<day<<" "<<"December "<<year<<endl;
            break;
                     }
}