

/* 
 * File:   main.cpp
 * Author: Ting
 * Created on May 15, 2022, 4:35 PM
 * Purpose: Largest/smallest array number
 */

#include <iostream>

using namespace std;


int main(int argc, char** argv) {
    const int SIZE=10;
    int number[SIZE];
    for(int i=0; i<SIZE;i++){
    cout<<"Please Enter number["<<(i+1)<<"] :"<<endl;
    cin>>number[i];
    }
    int largest=number[0];
    for(int i=0; i<SIZE; i++){
        if(number[i]>largest) largest=number[i];
    }
    
    int smallest=number[0];
    for(int i=0; i<SIZE; i++){
        if(number[i]<smallest) smallest=number[i];
    }
    
    cout<<"The largest number of array is "<<largest<<endl;
    cout<<"The smallest number of array is "<<smallest<<endl;
    
    return 0;
}

