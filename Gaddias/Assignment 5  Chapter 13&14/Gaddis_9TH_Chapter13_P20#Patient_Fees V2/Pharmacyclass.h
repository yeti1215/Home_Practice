/* 
 * File:   main.cpp
 * Author: Ting Yin Sha
 * Created on November 4, 2022, 10:22 PM
 * Project: Gaddis_9TH_Chapter13_P20#Patient Fees
 */

#include <iostream>
#include <iomanip>
using namespace std;

#ifndef PHARMACYCLASS_H
#define PHARMACYCLASS_H

class Pharmacy{
    private:
    string pmname;
    float pmprice;
public:
  //  friend class Patient;
    Pharmacy(){}
    Pharmacy(string n,float p){
        pmname=n;
        pmprice=p;
    }
    const string getName() const{
        return pmname;
    }
   const float getPrice() const{
       return pmprice;
   }
    void showPharmacy(){
    cout<<fixed<<setprecision(2)<<showpoint<<setw(14)<<pmname<<setw(8)<<pmprice<<endl;
}
};

#endif /* PHARMACYCLASS_H */

