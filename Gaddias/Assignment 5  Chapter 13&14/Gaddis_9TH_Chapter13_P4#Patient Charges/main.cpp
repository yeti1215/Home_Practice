

/* 
 * File:   main.cpp
 * Author: Ting Yin Sha
 * Created on November 3, 2022, 4:53 PM
 * Project: Gaddis_9TH_Chapter13_P4 #Patient Charges
 */

#include <iostream>
#include <cstdlib>
#include <cstring>

using namespace std;

#include "Classpatient.h"
#include "Classprocedure.h"

int main(int argc, char** argv) {
    //define a Patient object with the following data:
    Patient entry("Kristen Lee","666-1234","999 Avenue,riverside,CA");
    //Display the Patient object's data
    cout<<"Patient name: "<<entry.getName()<<endl;
    cout<<"Phone number: "<<entry.getPhone()<<endl;
    cout<<"Address:      "<<entry.getAddress()<<endl<<endl;
    
     
    cout<<"This is "<<entry.getName() <<" procedure charges:"<<endl;
    cout<<"--------------------------------------"<<endl;
    //define first Procedure object
    Procedure first("Physical Exam","11/03/2022","Dr.Irvine",250);
    cout<<"Procedure #1:"<<endl;
    first.display();
     cout<<"--------------------------------------"<<endl;
    Procedure second("X-ray","11/03/2022","Dr.Jamison",500);
    cout<<"Procedure #2:"<<endl;
    second.display();
     cout<<"--------------------------------------"<<endl;
    Procedure third("Blood test","11/03/2022","Dr.Smith",200);
    cout<<"Procedure #3:"<<endl;
    third.display();
    
    return 0;
}

