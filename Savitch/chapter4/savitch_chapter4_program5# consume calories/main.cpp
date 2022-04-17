

/* 
 * File:   main.cpp
 * Author: Ting
 * Created on April 17, 2022, 9:07 AM
 * project: consume calories calculate
 */

#include <iostream>
#include <cmath>

using namespace std;

int basalMetabolic(int);
int physicalActivity(int, int, int);
int energyDigest(int);

int main(int argc, char** argv) {
    
    int P, intens, minutes;// P=weight
    const int foodCalo=450;
    float serv;
    int total, consumC;
    
    cout<<"Input your weight:\n";
    cin>>P;
    cout<<"Input the intensity of physical activity:\n";
    cin>>intens;
    cout<<"Input the minutes spent performing the physical activity: \n";
    cin>>minutes;
    
   total=basalMetabolic(P)+physicalActivity(intens, P, minutes);
   consumC =energyDigest(total);
   
   serv = ( total+ consumC )/foodCalo;
   
   cout<<serv<<" servings of the food should be eaten per day."<<endl;
    
    return 0;
}

int basalMetabolic(int P){
    float Calories=70*pow(P/2.2, 0.756);  
    return Calories;   
}

int physicalActivity(int intens, int P, int minutes){
    float Calories=0.0385*intens*P*minutes;
    return Calories;
}

int energyDigest(int total){
    float Calories= total*0.1;
    return Calories;
}