/* 
 * File:   main.cpp
 * Author: Ting Yin Sha
 * Created on November 3, 2022, 8:32 PM
 * Project:Gaddis_9TH_Chapter13_P5#RetailItem Class
 */

#include <cstring>
#include <iostream>
#include <iomanip>
using namespace std;

#ifndef CLASSRETAILITEM_H
#define CLASSRETAILITEM_H

int count=0;

class RetailItem {
     private:
       // string item;
        char *item;
        int units;
        float price;
    public:
        RetailItem(){  //default constructor without argument, initialize variable
            item="";
            units=0;
            price=0.0;
        }
       
        //constructor with 3 argument
        RetailItem(char *i, int u, float p){
            item=i;
            units=u;
            price=p;
        }
        
        void setItem( char *i ){
            item=i;
        }
        void setUnits(int u){
            units=u;
        }
        void setPrice(float p){
            price=p;
        }
      char * getItem()  const {
          return item;
      }
      int getUnits()  const {
          return units;
      }
      float getPrice()  const {
          return price;
      }  
      void displayItem(){
          count++;
          cout<<"Item #"<<count<<"\t"<<setw(20)<<setfill(' ')<<left<<item<<units<<"\t\t"<<price<<endl;
          
      }
};


#endif /* CLASSRETAILITEM_H */

