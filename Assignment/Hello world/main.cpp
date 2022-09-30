

/* 
 * File:   main.cpp
 * Author: Ting Yin Sha
 * Created on August 31, 2022, 9:33 PM
 * Project: Hello World
 */

#include <iostream>
#include <cstring>

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    
//    char arr[]="four score and seven years ago,";
//    char *strPtr=nullptr;
//    cout<<arr<<endl;
//    strPtr=strstr(arr, "seven");
//    cout<<strPtr<<endl;  //?? cout seven years ago, not an address
//    cout<<*strPtr<<endl;  //??cout s
    
    string mystring=" my name";
    string str="Ting";
     cout<<mystring<<endl;
    cout<<mystring.assign(str,0,4)<<endl;
    cout<<mystring<<endl;
    
    cout<<mystring.back()<<endl;
    cout<<*mystring.begin()<<endl;
    

    return 0;
}

