

/* 
 * File:   main.cpp
 * Author: yeti
 * Created on April 14, 2022, 12:18 PM
 * PROJECT: Rock Paper Scissors Game with FUNTION
 */

#include <iostream> // Input & Output Library
#include <cstdlib> // Random number seed library
#include <ctime>  // time library
using namespace std;

void rule1();
void rule2();
void rule3();

int main(int argc, char** argv) {
     srand(time(NULL));
    int numComp, numPlay; // numComp = computer's choice; numPlay= player's choice;
    
   
    
   do{ 
        cout << "Rock Paper Scissors Game! 1= Rock, 2=Paper, 3= Scissors." << endl;
        numComp = rand() % 3 + 1; // computer pick a random number in the range of 1 through 3

        cout << "Player's turn, please pick a number 1, 2, 3." << endl;
        cin>>numPlay;
      
        
       if (numPlay < 1 || numPlay > 3) {
            cout << "Invalid Enter. Please choose number 1, 2, 3." << endl;
            cin>>numPlay;
        }
          
        switch(numPlay){
            case 1: cout<<"Player Rock"<<endl;break;
            case 2: cout<<"Player Paper"<<endl;break;
            case 3: cout<<"Player Scissors"<<endl;break;
                  
        }
    if (numPlay>=1 && numPlay<=3 ){
        switch(numComp){
            case 1: cout<<"computer Rock"<<endl;break;
            case 2: cout<<"Computer Paper"<<endl;break;
            case 3: cout<<"Computer Scissors"<<endl;break;
                  
        }
        
        if ((numPlay==1 && numComp==3) || (numPlay==3 && numComp==1))
        {  rule1();}
        if((numPlay==2 && numComp==3) || (numPlay==3 && numComp==2) )
        { rule2(); }
        if((numPlay==1 && numComp==2) || (numPlay==2 && numComp==1) )
        { rule3(); }
        
        else{
            cout<<"Both players make the same choice, please play again."<<endl;
            cout<<endl;
        }           
    }
   } while( numPlay == numComp);
    
   

    return 0;
}

void rule1(){
    cout<<"Rock win. The rock smashes the Scissors."<<endl;
}
void rule2(){
    cout<<"Scissors win. Scissors cuts Paper."<<endl;
}
void rule3(){
    cout<<"Paper win, Paper wraps Rock."<<endl;
}