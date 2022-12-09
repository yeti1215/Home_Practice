/* 
 * File:   main.cpp
 * Author: Ting Yin Sha
 * Created on November 3, 2022, 4:53 PM
 * Project: Gaddis_9TH_Chapter13_P4 #Patient Charges/class specification
 */

#ifndef CLASSPROCEDURE_H
#define CLASSPROCEDURE_H
#include <iostream>
#include <memory>
#include <cstring>
#include <iomanip>
using namespace std;


class Procedure{
private:
    char *pname;//procedure name
    char *date;
    char *dname; //practitioner name
    float  charge; //use int can't showpoint when display, bcz private member
public:
    //constructor for display
    Procedure(char *, char *, char *, float);
    ~Procedure(){
        delete []pname;
        delete []date;
        delete []dname;
    }
    void display();
    const char *getPname()const{
        return pname;
    }
    const char *getDate()const{
        return date;
    }
    const char *getDname()const{
        return dname;
    }
    const int getCharge()const{
        return charge;
    }
    
};

Procedure::Procedure(char *p, char *d,char *n, float c){
   
    pname=new char[strlen(p)+1];
    date=new char[strlen(d)+1];
    dname=new char[strlen(n)+1];
    strcpy(pname,p);
    strcpy(date,d);
    strcpy(dname,n);
    charge=c;  
       
    } 
void Procedure::display(){
       cout<<"Procedure name: "<<pname<<endl;
        cout<<"Date: "<<date<<endl;
        cout<<"Practitioner: "<<dname<<endl;
        cout<<"Charge: "<<fixed<<setprecision(2)<<showpoint<<charge<<endl;
        
}

#endif /* CLASSPROCEDURE_H */

