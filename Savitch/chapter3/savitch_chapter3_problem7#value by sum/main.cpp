

/* 
 * File:   main.cpp
 * Author: Ting
 * Created on April 14, 2022, 10:23 AM
 * project: the value e^x
 */

#include <iostream> // library for output and input
#include <cmath> //bring math library
#include <iomanip> //bring the format library

using namespace std;
float eachvalue(int,int);



int main(int argc, char** argv) {
  
    float sum=1; //the initial sum value is 1;  
    int x, n;
    cout << "Enter the value of X: " << endl;
    cin>>x;
    cout << "Enter the value of n between 1 to 100:" << endl;
    cin>>n;
          for(int i=1; i <=n; i++)
          {
            sum += eachvalue(x,i);
            cout<<fixed<<setprecision(2)<<showpoint;
            cout<<sum<<"  ";
            if(i%10==0)cout<<endl;
          }
     
   
    return 0;
}

float eachvalue(int x, int i){
    float eachV= pow(x,i)/i; //calculate each x^n/n value and return the value
           return eachV;
}