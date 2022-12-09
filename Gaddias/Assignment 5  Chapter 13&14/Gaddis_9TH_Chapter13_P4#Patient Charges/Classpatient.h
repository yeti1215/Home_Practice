
/* 
 * File:   main.cpp
 * Author: Ting Yin Sha
 * Created on November 3, 2022, 4:53 PM
 * Project: Gaddis_9TH_Chapter13_P4 #Patient Charges/class specification
 */



#ifndef CLASSPATIENT_H
#define CLASSPATIENT_H
#include <cstring>

class Patient{
private:
    char *name;
    char *phone;
    char *address;
        
public:
    Patient(char *n, char*p, char *a) //constructor, automatically call when define a class object
    {//Allocate enough memory for the name, phone and address;
        name= new char[strlen(n)+1];
        phone=new char[strlen(p)+1];
        address=new char[strlen(a)+1];
//copy the name, phone and address to the allocated memory
         strcpy(name,n); 
         strcpy(phone,p);
         strcpy(address,a);
    }
    //destructor, delete memory
    ~Patient()
    {delete []name;
     delete []phone;
     delete []address;
    }
    //accessor function
    const char *getName()const
    { return name;}
    const char *getPhone()const
    { return phone;}
    const char *getAddress()const
    { return address;}
    //

};

#endif /* CLASSPATIENT_H */

