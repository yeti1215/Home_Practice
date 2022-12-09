

/* 
 * File:   main.cpp
 * Author: yeti
 * Created on November 10, 2022, 8:17 AM
 * Project Gaddis_9TH_Chapter14_P1#Numbers Class
 */
 

#include <iostream>
#include <string>

using namespace std;

class Numbers{
public:
   int number;
   static string lessThan[20];
   static string hundred;
   static string thousand;
   bool positiveOnly(int );
   int setNumber();
   void printNumber();
   string tensNumber(int);
};
//initialize static string
 string Numbers::thousand=" thousand ";
 string Numbers::hundred=" hundred ";
 string Numbers::lessThan[20]={"zero",
    "one","two","three","four","five","six","seven","eight","nine","ten","eleven",
    "twelve","thirteen","fourteen","fifteen","sixteen","seventeen","eighteen","nineteen"
};
//use bool check the number and initialize number;
bool Numbers::positiveOnly(int n){
    if(n<0 ||n>9999) {cout<<"ERROR,OUT OF RANGE"<<endl;return false;}
    else {number=n; return true;}
}
//return number to class
int Numbers::setNumber(){
    return number;
}
void Numbers::printNumber(){
   int n1000s,n100s,n10s,n1s;
   n1000s=number/1000; if(n1000s>0) {cout<<this->lessThan[n1000s]<<thousand;}
   n100s=(number%1000)/100; if(n100s>0){cout<<this->lessThan[n100s]<<hundred;}
   n10s=(number%100)/10;
   if(n10s>1){
       cout<<" "<<this->tensNumber(n10s)<<" ";
       n1s=(number%10);
       if(n1s>0){cout<<this->lessThan[n1s]<<endl;}
   }
   if(n10s<2){
       n10s=number%100; cout<<this->lessThan[n10s]<<endl;
   }
   
}
 
string Numbers::tensNumber(int n10s){
    string s;
    switch (n10s){
        case 9:s= "ninety"; break;
        case 8:s= "eighty"; break;
        case 7:s= "seventy"; break;
        case 6:s= "sixty"; break;
        case 5:s= "fifty"; break;
        case 4:s= "forty"; break;
        case 3:s= "thirty"; break;
        case 2:s= "twenty"; break;
    }
    return s;
}

int main(int argc, char** argv) {
    
    int num;
    char ch;
    do{
    cout<<"Please enter a number from 0 to 9999"<<endl;
    cin>>num;
    Numbers englishNum;
    englishNum.positiveOnly(num); 
    englishNum.setNumber();
    englishNum.printNumber();
    cout<<"Try another number? Y/N"<<endl;
    cin>>ch;
    }while (toupper(ch)=='Y');
    
    return 0;
}

