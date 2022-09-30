/* 
 * File:   
 * Author: Ting Sha
 * Created on september 28th, 2022; 9:30Am
 * Purpose:   company division
 */

//System Libraries
#include <iostream>
#include <ctime>
#include <iomanip>
using namespace std;

//User Libraries

//Global Constants - No Global Variables
//Only Universal Constants, Math, Physics, Conversions, Higher Dimensions

//Function Prototypes
struct Sales{
   
    float firstqs;
    float secndqs;
    float thirdqs;
    float fourqs;
    float totalAs;
    float arqs;
   
};
void getvalue(struct Sales dname){
    
    cout<<"Enter first-quarter sales:\n";
   cin>>dname.firstqs;
    cout<<"Enter second-quarter sales:\n";
   cin>>dname.secndqs;
    cout<<"Enter third-quarter sales:\n";
    cin>>dname.thirdqs;
    cout<<"Enter fourth-quarter sales:\n";
    cin>>dname.fourqs;
    dname.totalAs=dname.firstqs+dname.secndqs+dname.thirdqs+dname.fourqs;
    cout<<"Total Annual sales:$"<<dname.totalAs<<endl;
    dname.arqs=(dname.totalAs/4);
    cout<<"Average Quarterly Sales:$"<<dname.arqs;
    
}
//Execution Begins Here
int main(int argc, char** argv) {
    //Set Random Number seed
    //srand(time(NULL));
    static_cast<unsigned short>(time(NULL));
    
    //Declare Variable Data Types and Constants
    struct Sales East;
    struct Sales West;
    struct Sales North;
    struct Sales South;
    cout<<fixed<<setprecision(2)<<showpoint;
    
    //Initialize Variables, input value for each division
   
    
    //use prototypes funcion get value
    cout<<"North"<<endl;
    getvalue(North);
    cout<<endl;
    cout<<"West"<<endl;
    getvalue(West);
     cout<<endl;
    cout<<"East"<<endl;
    getvalue(East);
     cout<<endl;
    cout<<"South"<<endl;
    getvalue(South);
    
    //Process or map Inputs to Outputs
    
    //Display Outputs

    //Exit stage right!
    return 0;
}