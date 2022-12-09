
/* 
 * File:   main.cpp
 * Author: Ting Sha
 * Created on October 13, 2022, 9:21 AM
 * Project: File Encryption Filter with both TXT and Binary file
 */

#include <iostream>
#include <fstream>
#include <ctime>

using namespace std;

char arrayToFile(const string fileName, char *aryPtr, int size){
    ofstream outputData;
    outputData.open(fileName, ios::out|ios::binary);
    if(outputData){
        outputData.write(reinterpret_cast<char *> (aryPtr), size*sizeof(char));
        outputData.close();
       // cout<<"size*sizeof(char)"<<size*sizeof(char)<<endl;
        cout<<"write into binary file done"<<endl;
        return 0;
    }
    
    else return -1;
}
char fileToArray(const string fileName, char *aryPtr, int size){
    ifstream inputData;
    inputData.open(fileName,ios::in|ios::binary);
    if(inputData){
        int i=0;
        while(i<size){
       //need read one by one from file and add 10
        inputData.seekg(0L, ios::cur); //actually read from 1L the first address, if use 1L will read from the second element
       // inputData.seekg(1L, ios::end); works? why?
        inputData.get(aryPtr[i]);
        aryPtr[i]=(static_cast<int>(aryPtr[i]))+1; //add 1 to code;
        cout<<aryPtr[i];
        i++;
        }
        return 0;
    }
    else return -1;
}
int main(int argc, char** argv) {
    srand(time(0));
    int size=rand()%20+2;
    char array[size];
    int length=sizeof(array)/sizeof(array[0]);
    char readAry[length];
    fstream textFile;
    textFile.open("text.txt",ios::out);
    
    for(int i=0; i<size; i++){
        array[i]=rand()%25+65;  //range from A-Y
        cout<<array[i];
        if(textFile) textFile<<array[i];
        else cout<<"error"<<endl;
    }
    textFile.close();
    cout<<endl;
   //write into first file
    arrayToFile("original.bin", array, size);
     cout<<endl;
     //read from file and add 1
     cout<<"Read from binary file and add 1 "<<endl;
    fileToArray("original.bin", readAry, length);
    cout<<endl;
    
    textFile.open("text.txt",ios::in);
    char txtAry[length];
    
    if(textFile){
        cout<<"read from text file and add 1"<<endl;
        int i=0;
        while(textFile>>txtAry[i] && i<length){
            txtAry[i]=txtAry[i]+1;
             cout<<txtAry[i];

            i++;
                   }
    }
 
    else cout<<"open error"<<endl;
    textFile.close();
    
    cout<<endl<<endl;
    //write into second file
    arrayToFile("encryption.bin", readAry, size);
   
    //open text file write to second file
     textFile.open("encryption.txt",ios::out);
     if(textFile){
         cout<<"Write into text file\n";
         for(int i=0; i<length; i++){
             textFile<<txtAry[i];
         }
     }
    
    return 0;
}

