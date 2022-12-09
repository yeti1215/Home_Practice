

/* 
 * File:   main.cpp
 * Author: yeti
 * Created on November 10, 2022, 10:00 AM
 * Project: Gaddis_9TH_Chapter14_P4#Number Class
 */

#include <iostream>
#include <string>
#include <ctime>
#include <cmath>

using namespace std;

class NumDays{
    friend ostream& operator<<(ostream& cout, NumDays &numd);
    friend NumDays operator+(NumDays& p1, NumDays& p2);
    friend NumDays operator-(NumDays& p1, NumDays& p2);
private:
    int hours;
    float days;
public:
   NumDays(){ hours=0; retrieve();}
   NumDays(int h){ hours=h; retrieve();}
  //++ add operator inside class
   NumDays& operator++(){
       hours++;
       retrieve();
       return *this;
   }
   NumDays operator++(int){
       NumDays temp=*this;
       hours++;
       retrieve();
       return temp;
   }
    //-- subtract operator inside class
   NumDays& operator--(){//prefix decrement
       hours--;
       retrieve();
       return *this;
   }
   NumDays operator--(int){ //postfix decrement
       NumDays temp=*this;
       hours--;
       retrieve(); //How to make it automatically recalculated days??
       return temp;
   }
  
   float retrieve();
   
};

float NumDays::retrieve(){
       days=float(hours)/8;
       return days;
   }
ostream& operator<<(ostream& cout, NumDays &numd){
    cout<<numd.hours<<" hours "<<numd.days<<" days"<<endl;
    return cout;
}
 NumDays operator+(NumDays& p1, NumDays& p2){//write operator outside the class, need two argument
     NumDays temp;                           //write inside class,only need one, because the other one is this
       temp.hours=p1.hours+p2.hours;
       temp.retrieve();//need call the function with object temp, can't call the function by itself
       return temp;
   }
 NumDays operator-(NumDays& p1, NumDays& p2){
     NumDays temp=NULL;
     temp.hours=abs(p1.hours-p2.hours);
     return temp;
     
 }
   

int main(int argc, char** argv) {
    NumDays person1(10);  
    NumDays person2(20);
    NumDays person3; //for store result
    cout<<"person1 worked "<<person1;
    cout<<"person2 worked "<<person2;
    //Add+ operator overloading
    person3=person1+person2;
    cout<<"Person1 + Person2 worked "<<person3;
    //subtraction- operator overloading
    person3=person1-person2;
    cout<<"Person1 - Person2 worked different "<<person3;
    //++ prefix and postfix increment operator overloading
    ++person1;
    cout<<"++person1 worked "<<person1;
    person1++;
    cout<<"person1++ worked "<<person1;
    //-- prefix and postfix decrement operator overloading
    --person2;
    cout<<"--person2 worked "<<person2;
     person2--;
    cout<<"person2-- worked "<<person2;

    return 0;
}

