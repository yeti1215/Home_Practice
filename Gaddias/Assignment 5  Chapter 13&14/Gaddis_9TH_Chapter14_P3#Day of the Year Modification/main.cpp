

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

enum Months{January =1,February=2,March= 3,April=4,May=5,June=6,July=7,
  August=8,September=9,October=10,November=11,December=12}month;
  
class DayOfYear{
    friend DayOfYear& operator++(DayOfYear& temp);
    friend ostream& operator<<(ostream& cout, DayOfYear &dy);
public:
    DayOfYear(int m, int d){
        
        emonth=(enum Months)m;
        if(d<days[emonth-1] && d>0)
        {day=d; 
        smonth=months[emonth-1];}// get the this month
        else {cout<<"OUT OF RANGE"<<endl;exit(0); }// exit when out of range    
    }  
//    bool terminal(){ //terminate inside the constructor by checking the day value
//        if(day<days[emonth-1] && day>0)
//            return true;
//        else
//        {cout<<"OUT OF RANGE"<<endl;
//        return false;}  };
    int  day;     //the day of this
    string smonth; //the month of this
    enum Months emonth;
    static string months[12];
    static int days[12];    
    
};
string DayOfYear::months[12]={"January","February","March","April","May","June","July",
"August","September","October","November","December"};
int DayOfYear::days[12]={
   31,28,31,30,31,30,31,31,30,31,30,31};

ostream& operator<<(ostream& cout, DayOfYear &dy){
    cout<<dy.smonth<<" "<<dy.day<<endl;
    return cout;
}
DayOfYear& operator++(DayOfYear& temp){
    temp.day++;
    // check day,if is the last day of month will go to next month, the last day of year then go to a new year
    if(temp.day>temp.days[temp.emonth-1]) {
        temp.day=1;
         if(temp.smonth!=temp.months[11] ){//check if it's December
        temp.smonth=temp.months[temp.emonth];
         }
         else temp.smonth=temp.months[0];      //if now is December and last day,should go to January
    }  
    return temp;
}
DayOfYear& operator--(DayOfYear& temp){
    temp.day--;
   
    if(temp.day<=0){
        if(temp.smonth!=temp.months[0]){//check if it's January
        temp.smonth=temp.months[temp.emonth-2];
        temp.day=temp.days[temp.emonth-2];}
        else temp.smonth=temp.months[11];  //if now is January and day<0,should go to December
       
        return temp;
    }
    
}

int main(int argc, char** argv) {
    srand(static_cast<unsigned short>(time(0)));
    int num1, num2;
    num1=rand()%12+1;
    num2=rand()%31+1;
    DayOfYear date(num1,num2);
    DayOfYear date1=date; //copy a class
    
      cout<<"Today is         "<<date;
      
         ++date;
      cout<<"Next day is      "<<date;
     --date1;
     cout<<"Previous days is "<<date1;
   

    return 0;
}

