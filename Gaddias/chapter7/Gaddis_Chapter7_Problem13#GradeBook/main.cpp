

/* 
 * File:   main.cpp
 * Author: Ting
 * Created on May 15, 2022, 4:35 PM
 * Purpose: Grade Book
 */

#include <iostream>
#include <vector>
#include<cmath>
#include<iomanip>

using namespace std;


int main(int argc, char** argv) {
    const int SIZE=5;
    string names[SIZE];
    int score[5][4]; 
    float average[SIZE];
    char  grade[SIZE];
    
    cout<<"Students Name"<<endl;
    for(int i=0; i<SIZE; i++){
        cin>>names[i];
    }
    
    for(int i=0; i<5; i++){
        cout<<names[i]<<" Four test score:";
        for(int j=0; j<4; j++){
            cin>>score[i][j];
        }
    }
    
     for(int i=0; i<5; i++){
         int sum=0;
        for(int j=0; j<4; j++){
            sum +=score[i][j];
        } average[i]= float(sum)/4.0;
        if((average[i]>=90))grade[i]='A';
        if(average[i]<90 && average[i]>=80) grade[i]='B';
        if(average[i]<80 && average[i]>=70) grade[i]='C';
        if(average[i]<69 && average[i]>=60)  grade[i]='D';
        if(average[i]<60 && average[i]>=0)  grade[i]='F';
        /*grade[i]=(average[i]>=90)?'A':;
         grade[i]=(average[i]<90 && average[i]>=80)?'B': ;
         grade[i]=(average[i]<80 && average[i]>=70)?'C': ;
         grade[i]=(average[i]<70 && average[i]>=69)?'D': ;
         grade[i]=(average[i]<60 && average[i]>=0?'F' :;
        */
    }
    
    cout<<fixed<<setprecision(2)<<showpoint;
    cout<<"Name\tAverageScore\tGrade"<<endl;
    for(int i=0; i<SIZE; i++){
        cout<<names[i]<<"\t"<<average[i]<<"\t\t"<<grade[i]<<endl;
    }
    
    
    return 0;
}

