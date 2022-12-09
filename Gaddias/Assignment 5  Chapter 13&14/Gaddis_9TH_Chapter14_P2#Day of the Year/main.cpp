

/* 
 * File:   main.cpp
 * Author: yeti
 * Created on November 10, 2022, 10:00 AM
 * Project: Gaddis_9TH_Chapter14_P2#Day of the Year
 */

#include <iostream>
#include <string>
#include <ctime>

using namespace std;

class DayOfYear{
    
public:
    int number;
    int month, day;
    static string months[12];
    static int days[12];
    DayOfYear(int num){
        number=num;}
    void  calculate();
    int   getMonth();
    int getDay();
    void printDate();
    
};
string DayOfYear::months[12]={"January","February","March","April","May","June","July",
"August","September","October","November","December"};
int DayOfYear::days[12]={
    31,28,31,30,31,30,31,31,30,31,30,31};

void DayOfYear::printDate(){
    cout<<this->months[month-1]<<" "<<this->day<<endl;
}
void DayOfYear::calculate(){
    int sum=0;
    int i=1;
    if(number<=31) {this->month=1;day=number;}
    else 
        do{    
           number -=this->days[i-1];
           
           if(number<=this->days[i] &&number>0)
           { month=i+1;day=number;}
           
           else   if(number==0)
            {month=i;day=this->days[i];}
         
           else  if(number>this->days[i]) 
           {i++; }
              
        }while(i<12 &&number>this->days[i]);
}

int DayOfYear::getMonth(){ return month;}
int DayOfYear::getDay(){ return day;}

int main(int argc, char** argv) {
    srand(static_cast<unsigned short>(time(0)));
    int num;
    num=rand()%365+1;
    DayOfYear dayofyear(num);
    dayofyear.calculate();
    dayofyear.getMonth();
    dayofyear.getDay();
    cout<<"Day "<<num<<" would be ";// need update this part.
    dayofyear.printDate();

    return 0;
}

