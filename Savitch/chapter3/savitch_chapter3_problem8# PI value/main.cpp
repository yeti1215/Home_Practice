
/* 
 * File:   main.cpp
 * Author: yeti
 * project: pi value calculate
 * Created on April 12, 2022, 9:03 AM
 */

#include <iostream>
#include <cmath>
#include <string>

using namespace std;


int main(int argc, char** argv) {
    
    int n;
    
    char ch;
   
    do{
        float pi=0; 
        cout<<"Enter the N value:"<<endl;
    cin>>n;
     for (float i=0; i<= n; i+=2){
            pi += 4*(1/(2*i+1));
        } 
    for ( float i=1; i<=n; i+=2){
        pi -= 4*(1/(2*i+1));
    }
    
        cout<<"The approximate pi value is "<<pi<<endl;
        
        cout<<"Do you want repeat this calculation, Y/N? "<<endl;
        cin>>ch;
        
    }while( ch=='y' || ch=='Y');
  
    
    return 0;
}

