

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


int main(int argc, char** argv) {

    int x, n;
    float sum=1; //the initial sum value is 1;
    char ch;
    
    
    do{
        cout<<"Enter the value of X: "<<endl;
          cin>>x;
        cout<<"Enter the value of n between 1 to 100:"<<endl;
          cin>>n;
        
        for(int i=1; i<=n; i++){
            sum += pow(x,i)/i;
            cout<<fixed<<setprecision(2)<<showpoint;
            cout<<"n= "<<i<<" e^x = "<<sum<<"\t";
            if(i%10==0)cout<<endl;
        }
        cout<<endl;
        
        cout<<"Do you want repeat the calculate, Y/N? "<<endl;
        cin.get(ch);
    }
    while(ch=='y' && ch=='Y');
    
    return 0;
}

