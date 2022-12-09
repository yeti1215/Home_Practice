
/* 
 * File:   main.cpp
 * Author: Ting Yin Sha
 * Created on November 4, 2022, 10:22 PM
 * Project: Gaddis_9TH_Chapter13_P20#Patient Fees
 */

#include <iostream>
#include<string>
#include <iomanip>
#include "Patienclass.h"
#include "Pharmacyclass.h"
#include "Surgeryclass.h"

using namespace std;


int main(int argc, char** argv) {
    int size=5;
    char ch;
    int days;
    float price1, price2;
    //declare Surgery object array and store the price
    Surgery surgAry[size]={ 
        Surgery("X-ray", 500),
        Surgery("Physical Exam", 250),
        Surgery("Blood test", 300),
        Surgery("Ultrasound", 220),
        Surgery("Tooth clear", 280) };
     //declare Pharmacy object array and store the price
    Pharmacy phmyAry[size]={
        Pharmacy("Eye-drop",6.8),
        Pharmacy("sanitizer",2.1),
        Pharmacy("Pain-killer",10.8),
        Pharmacy("Allergy-relief",14.5),
        Pharmacy("Cough-relief",9.9)
    };
    cout<<setw(14)<<"surgery"<<setw(8)<<"Cost"<<endl;
    for(int i=0; i<5; i++){
        cout<<setw(14)<<surgAry[i].getName()<<setw(8)<<surgAry[i].getPrice()<<endl;
    }
   cout<<"-----------------------------------\n"; 
   cout<<setw(14)<<"Pharmacy"<<setw(8)<<"Cost"<<endl;
    for(int i=0; i<5; i++){
        phmyAry[i].showPharmacy();
    }
    cout<<"-----------------------------------\n"; 
    cout<<"Enter how many day spent in hospital?"<<endl;
    cin>>days;
    int count=1;
    Patient patient(days);
    while(count<=days){
        cout<<"The "<<count<<" days"<<endl;
    cout<<"Choose a type of surgery: X/P/B/U/T, type any key for NONE"<<endl;
    cin>>ch;
    switch(toupper(ch)){
        case 'X':  price1=surgAry[0].getPrice();
            break;
        case 'P':price1=surgAry[1].getPrice();
            break;
        case 'B':price1=surgAry[2].getPrice();
            break;
        case 'U':price1=surgAry[3].getPrice();
            break;
        case 'T':price1=surgAry[4].getPrice();
            break;
        default: price1=0;
            break;
    }
    
    cout<<"Choose a type of medication: E/S/P/A/C, type any key for NONE"<<endl;
    cin>>ch;
    switch(toupper(ch)){
        case 'E': price2=phmyAry[0].getPrice();
            break;
        case 'S':price2=phmyAry[1].getPrice();
            break;
        case 'P':price2=phmyAry[2].getPrice();
            break;
        case 'A':price2=phmyAry[3].getPrice();
            break;
        case 'C':price2=phmyAry[4].getPrice();
            break;
        default: price2=0;
            break;
    }
    
   
    patient.setCharge(price1,price2);
    patient.showDayCharge();
    
    count++;
    }
    patient.showTotalCharge();
    
    return 0;
}

