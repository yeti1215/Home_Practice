

/* 
 * File:   main.cpp
 * Author: Ting Yin Sha
 * Created on May 23, 2022, 10:42 PM
 * Purpose: project 2# Battle ship Version 3
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
void setShips(string [][10]);  // initialize the game board fill with *
bool guess(string [][10],int ,int );
string hitWhichShip( string [10][10],int , int , string  ); // display the ship's name which be hit
bool searchSink1(string [10][10]);// Search the ship for sinking
bool searchSink2(string [10][10]);
bool searchSink3(string [10][10]);
bool searchSink4(string [10][10]);

int main(int argc, char** argv) {
    srand(static_cast<unsigned int>(time(0)));
    
    const int ROWS=10,
              COLS=10;
    int    firstR, firstC; //The first spot to set ship
    int    ship,  //use 2,3,4,5 represent each ship     
           space, //the ship take how many space
           count=0; //count how many ship sink
    char    direct;// the ship direction
    string  Label; //ship label
    //initialize the game board for two players
    string myBoard[ROWS][COLS];
        
     //Display how the board looks like
     systemBoard();
     setShips(myBoard);
    
    //first player place the ship, the spot initialize to 1 if place a ship.
   
     ship=2; // initialize the ship length start from 2 
  do{
     shiplabel(ship, Label, space);
     cout<<"Choose the first starting point for '"<<Label<<"' need space "<<space<<endl;
     cout<<"Input Row[0-9]/Column[0-9]"<<endl;
     cin>>firstR>>firstC;
   //  myBoard[firstR][firstC]="1";
     //choose the horizontal or vertical direction to place ship
     cout<<"Choose the direction to place the ship."<<endl;
     cout<<"Enter R=Right, L=Left, D=Down, U=Up, "<<endl;
     cin>>direct;
     while(direct!='R'&& direct!='L' && direct!='U'&& direct!='D'){
     cout<<"ERROR INPUT";
     cin>>direct;
     }
     
     switch(direct){
         case 'R': for(int i=firstC; i<(firstC+space); i++){
             if(space==2) myBoard[firstR][i]="D";
             if(space==3) myBoard[firstR][i]="C";
             if(space==4) myBoard[firstR][i]="B";
             if(space==5) myBoard[firstR][i]="A";
             }
             break;
          case 'L': for(int i=firstC; i>(firstC-space); i--){
             if(space==2) myBoard[firstR][i]="D";
             if(space==3) myBoard[firstR][i]="C";
             if(space==4) myBoard[firstR][i]="B";
             if(space==5) myBoard[firstR][i]="A";
             }
             break;
         case 'D':for(int i=firstR; i<(firstR+space); i++){
             if(space==2) myBoard[i][firstC]="D";
             if(space==3) myBoard[i][firstC]="C";
             if(space==4) myBoard[i][firstC]="B";
             if(space==5) myBoard[i][firstC]="A";}
             break;
          case 'U':for(int i=firstR; i>(firstR-space); i--){
             if(space==2) myBoard[i][firstC]="D";
             if(space==3) myBoard[i][firstC]="C";
             if(space==4) myBoard[i][firstC]="B";
             if(space==5) myBoard[i][firstC]="A";}
             break;
               }
     cout<<endl;
     cout<<left;
     cout<<setw(19)<<setfill('=')<<"Your Board"<<endl;
     displayBoard(myBoard, ROWS);
     ship++; 
     cout<<endl;
    if(ship>5) cout<<"Your ships are settled as above,Let's battle."<<endl;
   }  while(ship<=5);
    
   // start to guess, if hit change the value to "0", if miss change the value to "X"
     
  do{int guessR, guessC;  //guessR= guess row number; guessC= guess Column number;
     string name; 
     cout<<"Input a guess row and column number from 0-9"<<endl;
     cin>>guessR>>guessC;
     guess(myBoard,guessR,guessC);
     if( guess(myBoard,guessR,guessC) ) {
         name= hitWhichShip(  myBoard,guessR,guessC, name);
         cout<<"HIT "<<name<<endl<<endl;
         myBoard[guessR][guessC]="1";}
     else {
         cout<<"MISS"<<endl<<endl;; 
         myBoard[guessR][guessC]="0";}
     
      displayBoard(myBoard, ROWS);
      // searching for the sink ship and display, count how many spot hit, 4ships total take 14 spot
      if(name=="Carrier") {searchSink1( myBoard); count++;}
      else if (name=="Battleship") { searchSink2( myBoard); count++;}
      else if (name=="Cruiser") {searchSink3( myBoard); count++;}
      else if (name=="Destroyer") { searchSink4( myBoard); count++;}
      
   }while ( count<14);
   
   cout<<"WIN"<<endl;
    return 0;
}

bool searchSink1(string myBoard[10][10]){
    for (int i=0; i<10; i++){
        for(int j=0; j<10; j++){
            if( myBoard[i][j]=="A") return false;
          
        }
        }{cout<<"Carrier is sink"<<endl<<endl;
         return true;}
}
bool searchSink2(string myBoard[10][10]){
    for (int i=0; i<10; i++){
        for(int j=0; j<10; j++){
            if( myBoard[i][j]=="B") return false;
        }
    }cout<<"Battleship is sink"<<endl<<endl;
     return true;
}
bool searchSink3(string myBoard[10][10]){
    for (int i=0; i<10; i++){
        for(int j=0; j<10; j++){
            if( myBoard[i][j]=="C") return false;
        }
    } cout<<"Cruiser is sink"<<endl<<endl;
      return true;
}
bool searchSink4(string myBoard[10][10]){
    for (int i=0; i<10; i++){
        for(int j=0; j<10; j++){
            if( myBoard[i][j]=="D") return false;
        }
    } cout<<"Destroyer is sink"<<endl<<endl; 
    return true;
}
string hitWhichShip( string myBoard[10][10],int i, int j, string name){
     if(myBoard[i][j]== "A")       name="Carrier";
     else if(myBoard[i][j]==  "B") name="Battleship";
     else if(myBoard[i][j]==  "C") name="Cruiser"; 
     else if(myBoard[i][j]==  "D") name="Destroyer";
    
    return name;
}
bool guess(string a[10][10],int i,int j){
    if (a[i][j]=="A" || a[i][j]=="B" || a[i][j]=="C" || a[i][j]=="D" ) return true;
    else return false;
}
void setShips(string a[10][10]){
  for (int i=0; i<10; i++){
        for(int j=0; j<10; j++){
            a[i][j]="*";
        }}
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