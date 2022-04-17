

/* 
 * File:   main.cpp
 * Author: Ting Sha
 * Created on April 11, 2022, 7:58 PM
 * project: Sales Bar Chart
 */

#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;


int main(int argc, char** argv) {
   
    char ans;
    do{
        const int evolvecond=12;
        const int evolveExp=500;
        int edocs, margorp=0, exp=0,candies;
        cout<<"Enter the number of candies in your possession."<<endl;
        cin>>candies;
        cout<<"Enter the number of Edocs caught."<< endl;
        cin >> edocs;
        while(candies+edocs+margorp>=12 && edocs > 0 ){
            int edoc_transfer = (12 * edocs -candies)/13/12;
            cout <<edoc_transfer<<endl;
            edoc_transfer *= 12;
            int diff = 12 - candies % 12;
            edoc_transfer += diff;
            if( edocs + margorp > edoc_transfer){
                candies += edoc_transfer;
                int margorp_transfer = 0;
                if(margorp >= edoc_transfer ){
                    margorp_transfer = edoc_transfer;
                }
                else{
                    margorp_transfer = margorp;
                }
                margorp -= margorp_transfer;
                edocs -= edoc_transfer - margorp_transfer;
                cout<<"Transfer "<<edoc_transfer-margorp_transfer<< "Edoc and "<<margorp_transfer
                        <<"Margorp resulting in\n"<< candies<<" candy, "<< edocs<<"Edoc, and "
                        <<margorp<<" Margorp"<<endl;
                
            }
            if (candies >= evolvecond && edocs > 0)
            {
                int evolutions = candies / evolvecond;
                if (evolutions > edocs ){
                    evolutions =edocs;
                }
                candies = candies - evolutions *evolvecond + evolutions;
                exp += evolutions*500;
                margorp += evolutions;
                edocs -=evolutions;
                cout<<"Evolve "<<evolutions<<" Edoc to get "<<500*evolutions
                        <<" experience points and resulting in \n"<<candies<<"candy,"
                        <<edocs<<" Edoc, and "<< margorp << "Margorp" << endl;
            }
        }
            cout<<"Total experience points ="<< exp<< endl;
            cout<<"Do you want to repeat the process? Y/N"<<endl;
            cin>>ans;
            
            
        
    }while (ans=='y' || ans=='Y');
    
    cout<<"Good bye!"<<endl;
    
    
    
            
    
    
    
    
    return 0;
}

