

/* 
 * File:   main.cpp
 * Author: Ting Yin Sha
 * Created on November 3, 2022, 8:32 PM
 * Project:Gaddis_9TH_Chapter13_P5#RetailItem Class
 */

#include <iostream>
#include <cstdlib>
#include "Classretailitem.h"


using namespace std;


/*
 * 
 */
int main(int argc, char** argv) {
    
    RetailItem item1; //declare one class object without argument
    item1.setItem("Jacket");
    item1.setUnits(12);
    item1.setPrice(59.95);
    
    RetailItem item2("Designer Jeans",40,34.95);
    RetailItem item3("Shirt", 20, 24.95);
    
    
    cout<<"\t"<<"Description\tUnits On Hand\tPrice"<<endl;
    item1.displayItem();
    item2.displayItem();
    item3.displayItem();

    return 0;
}

