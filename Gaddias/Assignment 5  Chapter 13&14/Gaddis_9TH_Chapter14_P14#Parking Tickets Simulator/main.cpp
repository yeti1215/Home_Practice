

/* 
 * File:   main.cpp
 * Author: yeti
 * Created on November 10, 2022, 10:00 AM
 * Project: Gaddis_9TH_Chapter14_P14#Parking Tickets Simulator
 */

#include <iostream>
#include <string>
#include <ctime>
#include <cmath>
#include <iomanip>

using namespace std;
class ParkedCar{
public:
    string maker;
    string model;
    string color;
    string  license; //license number
    int  p_time; //parked time
    ParkedCar(){
        setCarInfo("","","","",0);
    }
    ParkedCar(string m,string md,string c, string l,int t){//没有调用此构造函数
        cout<<"ParkedCar constructor"<<endl;
        setCarInfo(m,md,c,l,t);
        printCar();
    }
    void setCarInfo(string m,string md,string c, string l, int t){
        maker=m;
        model=md;
        color=c;
        license=l;
        p_time=t;
        
    }
   
    void printCar(){
              cout<<"Car maker:  "<<maker
                <<"\nCar model:  "<<model
                <<"\nCar color:  "<<color
                <<"\nCar license:"<<license
                <<"\nParked time= "<<p_time<<" minutes"<<endl;
    }
};

class ParkingMeter{
public:
    int b_time;// bought how may minutes
    ParkingMeter(){
        b_time=0;
    }
    ParkingMeter(int btime){
        cout<<"check purchase time"<<endl;
        setBuyTime(btime);
    }
    int setBuyTime(int btime){
        b_time=btime;
        return btime;
    }
    
};

class ParkingTickets{
public:
    float fine;
    int dtime; //different minutes
    ParkingTickets(){fine=0; dtime=0;}
    ParkingTickets(int minutes){  
        
         reportFine(minutes);
         printTickets();
         cout<<"ticket constructor"<<endl;
    }
    void reportFine( int minutes){
         dtime=minutes;
        if(dtime<=60) fine =25;
        else 
        {fine=25+((dtime-60)/60)*10+float((dtime)%60*(10.0/60.0)); }
       
    }
    void printTickets(){
        cout<<fixed<<setprecision(2)<<showpoint;
         cout<<"Parking time has expired "<<dtime<<" minutes"
                 <<" The FINE is = $ "<<fine<<endl;
    }

    
};

class PoliceOffice{
public:
    int d_time;
     ParkedCar parkedcar;
     ParkingMeter parkingmeter;
    ParkingTickets ticket;
     bool result;
     PoliceOffice(string m,string md,string c,string l, int n, int b){
         cout<<"Meter time checker"<<endl;
        
           parkedcar.setCarInfo( m, md,c, l, n);//no need data type
            parkedcar.printCar();
            
           parkingmeter.setBuyTime(b);
         cout<<"purchased = "<<parkingmeter.b_time<<" minutes"<<endl;
         
         result=examine();
       
         if (result==1){
             cout<<"\nISSUE TIKCET"<<endl;
            
            issueTicket();
 
         }
         else cout<<"\nThank you for paying parking fee!"<<endl;
         
     }
     bool examine(){
            d_time= parkedcar.p_time -parkingmeter.b_time;
            if(d_time >0) return true; //if expired return true to issue a parking tickets
            else 
                return false;
     }
     void issueTicket(){
     
         ticket.reportFine(d_time);
         ticket.printTickets();
      //   ParkingTickets(d_time);  can't use another class's constructor?
     }
};

int main(int argc, char** argv) {
    
  
    PoliceOffice("Tesla", "Model X", "Black", "CA9999",120,40);
    
    cout<<"-----------------------------------------"<<endl;
    
    PoliceOffice("Honda", "Bluebird", "blue", "CA5555",20,60);

    return 0;
}

