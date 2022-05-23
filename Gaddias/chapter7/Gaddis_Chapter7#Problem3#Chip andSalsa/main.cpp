

/* 
 * File:   main.cpp
 * Author: Ting
 * Created on May 15, 2022, 4:35 PM
 * Purpose: Chips and Salsa
 */

#include <iostream>

using namespace std;


int main(int argc, char** argv) {
    const int SIZE=5;
    string salsa[SIZE]={"mild","medium","sweet","hot","zesty"};
    int    jars[SIZE],
            index;
    for(int i=0; i<SIZE; i++){
        cout<<"Enter the number of jars sold of "<<salsa[i]<<endl;
        cin>>jars[i];
    }
    //display report
     cout<<"Sales report"<<endl;
    for(int i=0;  i<SIZE; i++){
        cout<<salsa[i]<<"\t"<<jars[i]<<endl;
    }
     //display the highest selling and lowest selling
     int highest=jars[0];
     for(int i=0; i<SIZE; i++){
         if(jars[i]>highest){
             highest=jars[i];
             index=i;
         }
     }
     cout<<"The highest selling salsa is "<<salsa[index]<<" sold "<<highest<<endl;
     
     int lowest=jars[0];
     for(int i=0; i<SIZE; i++){
         if(jars[i]<lowest){
             lowest=jars[i];
             index=i;
         }
     }
     cout<<"The lowest selling salsa is "<<salsa[index]<<" sold "<<lowest<<endl;
     
     
    return 0;
}

