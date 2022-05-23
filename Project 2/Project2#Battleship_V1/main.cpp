

/* 
 * File:   main.cpp
 * Author: Ting Yin Sha
 * Created on May 17, 2022, 10:42 PM
 * Purpose: project 2# Battle ship Version 1
 */

#include <iostream> // Input/Output Stream Library
#include <iomanip> //Formatting Library
#include <cstdlib> // Random Value Library
#include <ctime> // Unique Seed Value Library
#include <string> //String Library
#include <cmath> // Math Library
#include <fstream> //File I/O

using namespace std;

void systemBoard(); //Display how the board looks like
void displayBoard(string [][10], int); //display game board
void shiplabel(int , string &, int &); //ship's mark label

int main(int argc, char** argv) {
    srand(static_cast<unsigned int>(time(0)));
    
    const int ROWS=10,
              COLS=10;
    int    firstR, firstC; //The first spot to set ship
    int    ship,  //use 2,3,4,5 represent each ship     
           space; //the ship take how many space
    char    direct;// the ship direction
    string  Label; //ship label
    //initialize the game board for two players
    string myBoard[ROWS][COLS]={
        {"0","0","0","0","0","0","0","0","0","0"},
        {"0","0","0","0","0","0","0","0","0","0"},
        {"0","0","0","0","0","0","0","0","0","0"},
        {"0","0","0","0","0","0","0","0","0","0"},
        {"0","0","0","0","0","0","0","0","0","0"},
        {"0","0","0","0","0","0","0","0","0","0"},
        {"0","0","0","0","0","0","0","0","0","0"},
        {"0","0","0","0","0","0","0","0","0","0"},
        {"0","0","0","0","0","0","0","0","0","0"},
        {"0","0","0","0","0","0","0","0","0","0"}  };
    
    string youBoard[ROWS][COLS]={
        {"0","0","0","0","0","0","0","0","0","0"},
        {"0","0","0","0","0","0","0","0","0","0"},
        {"0","0","0","0","0","0","0","0","0","0"},
        {"0","0","0","0","0","0","0","0","0","0"},
        {"0","0","0","0","0","0","0","0","0","0"},
        {"0","0","0","0","0","0","0","0","0","0"},
        {"0","0","0","0","0","0","0","0","0","0"},
        {"0","0","0","0","0","0","0","0","0","0"},
        {"0","0","0","0","0","0","0","0","0","0"},
        {"0","0","0","0","0","0","0","0","0","0"}  };
    
     //Display how the board looks like
     systemBoard();
    
    //first player place the ship, the spot initialize to 1 if place a ship.
   //  cout<<"Which ship do you want to place?"<<endl;
   //  cout<<" Enter 2,3,4,5,represents Destroyer Cruiser Battleship Carrier"<<endl;
     ship=2; // initialize the ship length start from 2 
   do{
     shiplabel(ship, Label, space);
     cout<<"Choose the first dot for "<<Label<<"need space "<<space<<endl;
     cin>>firstR>>firstC;
     myBoard[firstR][firstC]="1";
     //choose the horizontal or vertical direction to place ship
     cout<<"Choose the direction to place the ship."<<endl;
     cout<<"Enter H=horizontal, V=vertical"<<endl;
     cin>>direct;
     switch(direct){
         case 'H': for(int i=firstC+1; i<(firstC+space); i++){
             myBoard[firstR][i]='1';}break;
         case 'V':for(int i=firstR+1; i<(firstR+space); i++){
             myBoard[i][firstC]='1';}break;
               }
    displayBoard(myBoard, ROWS);
    ship++; }while(ship<=5);
    
    //player 2 set the ships
    ship=2;
      do{
     shiplabel(ship, Label, space);
     cout<<"Choose the first dot for "<<Label<<"need space "<<space<<endl;
     cin>>firstR>>firstC;
     youBoard[firstR][firstC]="1";
     cout<<"Choose the direction to place the ship."<<endl;
     cout<<"Enter H=horizontal, V=vertical"<<endl;
     cin>>direct;
     switch(direct){
         case 'H': for(int i=firstC+1; i<(firstC+space); i++){
             youBoard[firstR][i]='1';}break;
         case 'V':for(int i=firstR+1; i<(firstR+space); i++){
             youBoard[i][firstC]='1';}break;
               }
    displayBoard(youBoard, ROWS);
    ship++; }while(ship<=5);
    
    //start to guess 
   
 int r,c;// the number of guess row and column
     //first guess a rand row and column;
     r=rand()%9;
     c=rand()%9;
     if(myBoard[r][c]=="1"){
         myBoard[r][c]="O"; cout<<"HIT"<<endl; //if hit change the value to "O"
     }
     else {myBoard[r][c]="X";  cout<<"MISS"<<endl;} //if miss change the value to "X"
    // second searching array has any "O", so we can guess starts next to the "O"
    for(int i=0; i<ROWS;i++){
        for(int j=0; j<COLS; j++){
            if (myBoard[i][j]=="O"){// if find a hit spot, then check the four spot around it to find next spot;
                if(myBoard[i][j+1]=="1")     myBoard[i][j+1]="O";
                else if(myBoard[i][j-1]=="1")myBoard[i][j-1]=="O";
                else if(myBoard[i+1][j]=="1")myBoard[i+1][j]=="O";
                else if(myBoard[i-1][j]=="1")myBoard[i-1][j]=="0";
            }
        }
    } 
     
     
    return 0;
}
void displayBoard( string Board[][10], int R){
    for (int i=0; i<R; i++){
        for(int j=0; j<10; j++){
            cout<<Board[i][j]<<" ";
        } cout<<endl;
    }
    
}
void shiplabel(int n, string &L, int &space){
    switch(n){
        case 5: L="Carrier";   space=5; break;
        case 4: L="Battleship";space=4; break;
        case 3: L="Cruiser";   space=3; break;
        case 2: L="Destroyer"; space=2; break;
    }
}
void systemBoard(){
        cout<< "  Battle Ship Game"<<endl;
       //Display how the board looks like
        cout << "    System Board " << endl;
	cout << "............................." << endl;
	cout << " |1|2|3|4|5|6|7|8|9|10|"<<endl;
        for(int i=1; i<=10;i++){
            switch(i){
                case 1: cout<<"A";break;
                case 2: cout<<"B";break;
                case 3: cout<<"C";break;
                case 4: cout<<"D";break;
                case 5: cout<<"E";break;
                case 6: cout<<"F";break;
                case 7: cout<<"G";break;
                case 8: cout<<"H";break;
                case 9: cout<<"I";break;
                case 10:cout<<"J";break;
            }
             for(int i=1; i<=21;i++)
             { if(i%2==0) cout<<"*";else cout<<" ";}
            cout<<endl;
        }
       cout<<endl<<endl; 
}