/* 
 * File:   main.cpp
 * Author: Ting Yin Sha
 * Created on November 4, 2022, 10:22 PM
 * Project: Gaddis_9TH_Chapter13_P20#Patient Fees
 */

#include <iostream>

using namespace std;

#ifndef PATIENCLASS_H
#define PATIENCLASS_H

class Patient{
    private:
       float charges;
       int days;  
       float total;
    public:
        Patient(int d){
            charges=0.0;
            total=0.0;
            days=d;
        }
        void setCharge(float s,float p){
            charges=s+p;
            total +=charges;
        }
        const float getCharge(){
            return charges;
        }
        void showDayCharge(){
            cout<<"Today's charges = "<<charges<<endl;
        }
        void showTotalCharge(){
            cout<<"Spent "<<days<<" in hospital"<<endl;
            cout<<"Total charges = "<<total<<endl;
        }
};

#endif /* PATIENCLASS_H */

