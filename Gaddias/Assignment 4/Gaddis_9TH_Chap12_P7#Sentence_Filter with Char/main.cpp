

/* 
 * File:   main.cpp
 * Author: Ting Sha
 * Created on October 13, 2022, 11:34 AM
 * Project:Sentence Filter with Char
 */

#include <iostream>
#include <fstream>
#include <string>
#include <cctype>

using namespace std;


int main(int argc, char** argv) {
    string inName;
    string outName;
   // string inStr;
    char ch;
    
    
    ifstream inFile;
    ofstream outFile;
   // cout<<"Input file name: sentence.txt "<<endl;
  //  getline(cin,inName); 
    inFile.open("sentence.txt", ios::in);
    outFile.open("second.txt", ios::out);
    if(inFile){
        inFile.get(ch);  //read from file,successful,continue
        
        outFile.put(toupper(ch));// write first letter uppercase to outfile
        
        while(inFile){
                      
            if(ch=='.' ){
                inFile.get(ch);
              outFile.put(toupper(ch)); // ch!='\0' not work, why read two.. ant the end
                
            }
            
            else{     inFile.get(ch);//read another char from sentence file
                   outFile.put(tolower(ch)); 
            }
          
        }
    inFile.close();   
    outFile.close();
    }
   
    return 0;
}

