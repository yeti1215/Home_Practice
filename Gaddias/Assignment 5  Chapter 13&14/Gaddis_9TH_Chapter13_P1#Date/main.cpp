
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

class Date{
private:
    int month;
    int day;
    int year;       
public:
    void setMonth(int);
    void setDay(int);
    void setYear(int);
    int getMonth()const;
    int getDay() const;
    int getYear() const;
    void printDate();
    
};
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

