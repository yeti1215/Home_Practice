

/* 
 * File:   main.cpp
 * Author: Ting
 * Created on May 15, 2022, 4:35 PM
 * Purpose: Driver's License Exam
 */

#include <iostream>

using namespace std;

void display(char [], int);
int main(int argc, char** argv) {
    const int SIZE=10;
    char correct[SIZE]={'A','D','B','B','C','B','A','B','C','D'};
    char answer[SIZE];
    int  pass=0,
         failed=0;
 
    cout<<"Enter your answer:"<<endl;
    for(int i=0; i<SIZE; i++){
        cin>>answer[i];
   
    }cout<<endl;
       
     display(correct,SIZE);
     display(answer,SIZE);
    
    for(int i=0; i<SIZE; i++){
        if(answer[i]==correct[i]) pass++;
        else {failed++; cout<<"Incorrect Question"<<(i+1)<<endl;}
    }
    
    if(pass>=7) cout<<"Pass!"<<endl;
    else cout<<"Failed"<<endl;
    
    
     
    return 0;
}

void display(char display[], int SIZE){
     for(int i=0; i<SIZE; i++){
        cout<<display[i]<<" ";
    }cout<<endl;
}