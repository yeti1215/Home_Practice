

/* 
 * File:   main.cpp
 * Author: Ting Sha
 * Created on October 13, 2022, 9:50 PM
 * Project:Corporate Sales Data Output
 */

#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include<iomanip>




using namespace std;
const int gsize=4;  //global size

struct DataSale{

    string Dname;
    int quarter[gsize];
    int qSale[gsize];
};

int main(int argc, char** argv) {
  srand((static_cast<unsigned short>(time(0)))) ;
 
  struct DataSale writeAry[gsize];
  char *nameAry[]={"East","Wast","South","North"};
  
    for(int i=0; i<gsize; i++){
      writeAry[i].Dname=nameAry[i];

      cout<<writeAry[i].Dname<<endl;;
      for(int j=0; j<gsize; j++){
      writeAry[i].quarter[j]=j+1;
      cout<<writeAry[i].quarter[j]<<" ";
      writeAry[i].qSale[j]=rand()%901+100;
      cout<<  writeAry[i].qSale[j]<<" ";
      }
      cout<<endl;
  }
  
  fstream outputFile;
  outputFile.open("sales.bin",ios::out|ios::binary);
  outputFile.write(reinterpret_cast<char *>(&writeAry), gsize*sizeof(DataSale));
  cout<<"Writing done."<<endl;
  outputFile.close();
  
  //reading file to structure
  fstream inputFile;
   DataSale readAry[gsize];
  inputFile.open("sales.bin",ios::in|ios::binary);
  if(inputFile.is_open()){
  inputFile.read(reinterpret_cast<char *>(&readAry),gsize*sizeof(readAry));
   cout<<"Reading done,show result\n"<<endl;
   inputFile.close();
   
  }
 
 for(int i=0; i<gsize; i++){
     
      cout<<"Name\t"<<readAry[i].Dname<<endl;
      cout<<"Quarter\t";
      for(int j=0; j<gsize; j++){ 
      cout<<setw(4)<<readAry[i].quarter[j];
      }cout<<endl;
      cout<<"Sales\t";
      for(int j=0; j<gsize; j++){ 
      cout<<setw(4)<<readAry[i].qSale[j]<<" ";
      }
      cout<<endl;
  }

    return 0;
}

