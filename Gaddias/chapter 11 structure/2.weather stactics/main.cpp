/* 
 * File:   
 * Author: Ting Sha
 * Created on september 28th, 2022;10:00AM
 * Purpose:  weather stactics
 */

//System Libraries
#include <iostream>
#include <iomanip>
using namespace std;

//User Libraries

//Global Constants - No Global Variables
//Only Universal Constants, Math, Physics, Conversions, Higher Dimensions

//Function Prototypes
struct Statics{
  float totalr;
  float hight;
  float lowt;
};

enum month{JANUARY, FEBRUARY,MARCH,APRIL, MAY, JUNE, JULY, AUGUST,SEPTEMBER,OCTOBER, NOVEMBER,DECEMBER };

//Execution Begins Here
int main(int argc, char** argv) {
    //Set Random Number seed
    
    //Declare Variable Data Types and Constants
   //  int SIZE=6;
    Statics weather[DECEMBER];
    float argr; //average rain
    float argt;//average temprature
    float highMt; //high maxium temp
    float lowMt; //low minimum temp
     
    // cout<<fixed<<setprecision(2);
    //Initialize Variables
    

    
    month size =JANUARY ;
     while (cin >> weather[size].totalr>> weather[size].hight >> weather[size].lowt){
        cout<<"Enter the total rainfall for the month:"<<endl;
        cout<<"Enter the high temp:"<<endl;
        cout<<"Enter the low temp:"<<endl;
        
        size=static_cast<month>(size+1);
        
     //  cout<<"size="<<size<<endl;
    }
    
  
    //Process or map Inputs to Outputs
    //calculate monthly total rain and temprature
    float sumR=0;
    float sumT=0;
    highMt=weather[JANUARY].hight;
    lowMt=weather[JANUARY].lowt;
    for(month i=JANUARY; i<size; i=static_cast<month>(i+1)){
       sumR += weather[i].totalr; 
       sumT= sumT +weather[i].hight + weather[i].lowt;
       if(weather[i].hight>highMt) highMt=weather[i].hight;
       if(weather[i].lowt<lowMt) lowMt=weather[i].lowt;
    }
    
  // cout<<"sumT"<<sumT<<endl;
    argr=sumR/size;
    argt=sumT/(size*2);
    //Display Outputs
    cout<<"Average monthly rainfall:"<<fixed<<setprecision(2)<<argr<<endl;
    
    cout<<"High Temp:"<<static_cast<int>(highMt)<<endl;
    cout<<"Low Temp:"<<static_cast<int>(lowMt)<<endl;
    cout<<"Average Temp:"<<fixed<<setprecision(1)<<argt; 
 
   

    //Exit stage right!
    return 0;
}