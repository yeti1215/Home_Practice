
/* 
 * File:   main.cpp
 * Author: yeti
 * project: display temperature
 * Created on April 12, 2022, 9:03 AM
 */

#include <iostream>
#include <cmath>
#include <string>

using namespace std;


int main(int argc, char** argv) {
    
   int size,kilo, bytes;
   char ch;
   cout<<"Enter the size of the file"<<endl;
   cin>>size;
   cout<<"Enter the units of the file"<<endl;
   cin>>ch;
   
   switch(ch){
       case 'M': kilo=size*1024; cout<< size <<" megabyte is euqal to "<< kilo <<" Kilobytes."<<endl;
       bytes = kilo*1024; cout<< kilo <<" kilobytes is equal to "<< bytes << "Bytes."<<endl;
       break;
       case 'K': bytes = size*1024;cout<<size<<" kilobytes is equal to "<< bytes << "Bytes."<<endl;
       break;
       case 'B':  cout<< size << " bytes";
       break;
   }
  
    
    return 0;
}

