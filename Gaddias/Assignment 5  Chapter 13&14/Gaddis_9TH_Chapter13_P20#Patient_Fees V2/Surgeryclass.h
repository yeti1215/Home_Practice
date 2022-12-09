/* 
 * File:   main.cpp
 * Author: Ting Yin Sha
 * Created on November 4, 2022, 10:22 PM
 * Project: Gaddis_9TH_Chapter13_P20#Patient Fees
 */

#include <iostream>


using namespace std;

#ifndef SURGERYCLASS_H
#define SURGERYCLASS_H

class Surgery{
private:
    string sgname;
    float sgprice;
public:
    
    Surgery(){}
    Surgery(string n,float p){
        sgname=n;
        sgprice=p;
    }
    const string getName() const{
        return sgname;
    }
   const float getPrice() const{
       return sgprice;
   }  
   
   void showSurgery(){
    cout<<sgname<<"\t"<<sgprice<<endl;
}
    
};


#endif /* SURGERYCLASS_H */

