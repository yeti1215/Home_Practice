

/* 
 * File:   main.cpp
 * Author: yeti
 * Created on April 15, 2022, 7:24 PM
 * PROJECT: Experience calculator with FUNCTION
 */

#include <iostream>


using namespace std;

const int evoCand=12;
const int evoExp=500;

int transfer(int, int,int );  
int evolve(int, int, int);

int main(int argc, char** argv) {
    char ch;
    do{
    int edoc, margorp=0, exp=0,candy;
        cout<<"Enter the number of candies in your possession."<<endl;
        cin>>candy;
        cout<<"Enter the number of Edocs caught."<< endl;
        cin >> edoc;
        
     while(candy + edoc + margorp>=12 && edoc > 0 ){
         transfer(candy, edoc, margorp);
     
        if (candy >= evoCand && edoc > 0)
            evolve(candy, edoc, margorp);
        }
        
        cout<<"Total experience points ="<< exp<< endl;
        cout<<"Do you want to repeat the process? Y/N"<<endl;
        cin>>ch;
    }
    while( ch=='y' || ch=='Y');

    return 0;
}

int transfer(int candy, int edoc, int margorp){
    
      int  edoc_transfer ;
      edoc_transfer = (12 * edoc -candy)/13/12;
            cout <<edoc_transfer<<endl;
            edoc_transfer *= 12;
            int diff = 12 - candy % 12;
            edoc_transfer += diff;
            if( edoc + margorp > edoc_transfer){
                candy += edoc_transfer;
                int margorp_transfer = 0;
                if(margorp >= edoc_transfer ){
                    margorp_transfer = edoc_transfer;
                }
                else{
                    margorp_transfer = margorp;
                }
                margorp -= margorp_transfer;
                edoc -= edoc_transfer - margorp_transfer;
                cout<<"Transfer "<<edoc_transfer-margorp_transfer<< "Edoc and "<<margorp_transfer
                        <<"Margorp resulting in\n"<< candy<<" candy, "<< edoc<<"Edoc, and "
                        <<margorp<<" Margorp"<<endl;
                return candy, edoc, margorp;
    
}
}

int evolve(int candy, int edoc, int margorp){
    
     
                int evolutions = candy / 12;
                if (evolutions > edoc ){
                    evolutions =edoc;
                }
                candy = candy - evolutions *12 + evolutions;
               int exp = exp + evolutions*500;
                margorp += evolutions;
                edoc -=evolutions;
                cout<<"Evolve "<<evolutions<<" Edoc to get "<<500*evolutions
                        <<" experience points and resulting in \n"<<candy<<"candy,"
                        <<edoc<<" Edoc, and "<< margorp << "Margorp" << endl;
            
                return exp;
}