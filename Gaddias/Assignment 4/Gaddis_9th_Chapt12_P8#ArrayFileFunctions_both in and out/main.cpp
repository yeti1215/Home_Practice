
/* 
 * File:   main.cpp
 * Author: Ting 
 * Created on October 11, 2022, 8:59 PM
 *Project: Array/ File function with pointer， Both Input and Output 
 */

#include <iostream>
#include <fstream>
#include <ctime>
#include <iomanip>
using namespace std;


int arrayToFile(fstream &file, int *array, int *readAry,int size){
    
     for(int i=0; i<size; i++){
        array[i]=rand()%+20;
        cout<<setw(3)<<array[i];
                if(i==9) cout<<endl;
    }
      cout<<endl;
    if(file){  
        cout<<"writing"<<endl;
       file.write(reinterpret_cast<char *>(array), size*sizeof(int));   
       
          cout<<"reading"<<endl;
          file.seekg(0, ios::beg);
          file.read(reinterpret_cast<char *>(readAry), size*sizeof(int));
       return 0; 
    }
    
    else return -1;
    
}
int main(int argc, char** argv) {
    srand(static_cast<unsigned short>(time(0)));
    fstream file;
    file.open("Data.bin", ios::in|ios::out|ios::binary);
    int size=rand()%21+2;
    int *arrayPtr=new int[size];
 
   int *readAry=new int[size];
   arrayToFile(file,arrayPtr, readAry,size);
  //display reading data  
     for(int i=0; i<size; i++){
         cout<<setw(3)<<(readAry[i]);
         if (i==9) cout<<endl;
    }
    file.close();
    delete arrayPtr;
 
    return 0;
}

