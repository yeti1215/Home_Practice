

/* 
 * File:   main.cpp
 * Author: Ting Yin Sha
 * Created on September 3, 2022, 10:07 PM
 * Project: Rain or Shine
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <time.h>
using namespace std;


int main(int argc, char** argv) {
    // Declare variables here
    char array[3][30];
    char alpha[3]={'C','R','S'};
    int c=0, r=0, s=0;
    ifstream inputFile;
    ofstream outputFile;
    //store values in the array
    srand(time(NULL));
    outputFile.open("weather.txt");
    for(int i=0; i<3; i++){
        for (int j=0; j<30; j++){
            int r= rand()%3;
            array[i][j]=alpha[r];
        }
    }
    //write the array contents to the file
    for(int i=0; i<3; i++){
        for (int j=0; j<30; j++){
            outputFile<<array[i][j];
        }
     
    }
    //close the file
    outputFile.close();
    
  //read the data from file
    inputFile.open("weather.txt");
    
    for(int i=0; i<3; i++){
        for (int j=0; j<30; j++){
            cout<<array[i][j];
            switch(array[i][j]){
                case 'C':c++; break;
                case 'R':r++; break;
                case 'S':s++; break;
            }
        }
        cout<<endl;
    }
    cout<<endl;
    cout<<"In the past summer, there were "<<s<<" sunny days,"<<c<<" cloudy days, "<<r<<" rainy days."<<endl;

    inputFile.close();
    return 0;
}
