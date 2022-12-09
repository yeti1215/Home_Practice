#include <iostream>
#include <cstring>
#include<iomanip>
#include<cmath>

using namespace std;
struct TempYear{
    string name;
    float rainfall;
  
    int lowT;
    int highT;
    float arvgT;
};

int main(){
    int size=12;
    float arvgR; //average rainfall
    float rainT=0;
    float sumT =0;
   
    TempYear temAry[size];
    
   
    
    for(int i=0; i<size; i++){
        cin>>temAry[i].name>>temAry[i].rainfall>>temAry[i].lowT>>temAry[i].highT;
        
        sumT=temAry[i].highT+temAry[i].lowT+sumT;
     //   cout<<sumT<<endl;
       //average temprature 
        temAry[i].arvgT =round(sumT/(2*(i+1)));
      //  cout<< temAry[i].arvgT<<endl;
        // total rainfall
        rainT +=temAry[i].rainfall;
       }
           
            arvgR =rainT/12;  //average rain
            
     //for loop find out the lowest and highest temperature
      int lowest=temAry[0].lowT;
     
      int highest=temAry[0].highT;
      int Hindex;
      int Lindex;
            
        for(int i=0; i<size; i++){
            if(temAry[i].lowT<=lowest) {lowest=temAry[i].lowT; Lindex=i;}
            if(temAry[i].highT>=highest) {highest=temAry[i].highT; Hindex=i;}
        
        }
        cout<<"Average Rainfall "<<fixed<<setprecision(1)<<arvgR<<" inches/month"<<endl;
        
        cout<<"Lowest  Temperature "<<temAry[Lindex].name<<"  "<<lowest<<" Degrees Fahrenheit"<<endl;
        cout<<"Highest Temperature "<<temAry[Hindex].name<<"  "<<highest<<" Degrees Fahrenheit"<<endl;
        cout<<"Average Temperature for the year "<<static_cast<int>(temAry[11].arvgT)<<" Degrees Fahrenheit"<<endl;
        
	//your code here
	return 0;
}