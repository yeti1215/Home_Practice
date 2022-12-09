

/* 
 * File:   main.cpp
 * Author: Ting 
 * Created on October 11, 2022, 8:59 PM
 *Project: Array/ File function with pointer and open file in function
 */

#include <iostream>
#include <fstream>
#include <ctime>
using namespace std;

int fileToArray(const string &fileName, int *array, int size){
    
    ifstream inputData;
    inputData.open(fileName);
    if(inputData){
        inputData.read(reinterpret_cast<char *>(array), size*sizeof(int));
       
        inputData.close();
        cout<<"Read Done"<<endl;
        return 0;
    }
    
    
    else return -1;
    
}
int arrayToFile(const string &fileName, int *array, int size){
    ofstream outputData;
    outputData.open(fileName, ios::out|ios::binary);
    if(outputData){
        
       outputData.write(reinterpret_cast<char *>(array), size*sizeof(int)); 
       outputData.close();
       cout<<"write Done"<<endl;
       return 0;
    }
    
    else return -1;
    
}

int main(int argc, char** argv) {
    srand(static_cast<unsigned short>(time(0)));
   
    int size=20;
    int *arrayPtr=new int[size];
    for(int i=0; i<size; i++){
        arrayPtr[i]=rand()%10;
        cout<<arrayPtr[i]<<" ";
                if(i==9) cout<<endl;
    }
    cout<<endl;
    
  //  int *arrayPtr=array;  //*arrayPtr=&array[0]; *arrayPtr[size]=&array
    //pass 3arguments to function: file name, pointer to an int array, size of array
    arrayToFile("data.bin",arrayPtr, size);
    
    //read data from array and pass into array
    int *readAry=new int[size];
    fileToArray("data.bin", readAry,size);
    
     for(int i=0; i<size; i++){
         cout<<(readAry[i])<<" ";
         if (i==9) cout<<endl;
    }
 

   // arrayFile.close();
    return 0;
}

