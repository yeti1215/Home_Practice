

/* 
 * File:   main.cpp
 * Author: Ting Yin Sha
 * Created on May 23, 2022, 10:42 PM
 * Purpose: project 2# Battle ship Version 5, Two players
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
void initialBoard(string [][10]);  // initialize the game board fill with *
bool guess(string [][10],int ,int );
string hitWhichShip( string [10][10],int , int , string  ); // display the ship's name which be hit
bool searchSink1(string [10][10]); // Search for sinking Carrier ship
bool searchSink2(string [10][10]); // Search for sinking Battleship ship
bool searchSink3(string [10][10]); // Search for sinking Cruiser ship
bool searchSink4(string [10][10]); // Search for sinking Destroyer ship
void decorationLine();   // only use for decoration


int main(int argc, char** argv) {
    srand(static_cast<unsigned int>(time(0)));
    
    const int ROWS=10,
              COLS=10;
    int    firstR, firstC; //The first starting point to set ship
    int    ship,     //use 2,3,4,5 represent each ship     
           space,    //the ship's length
           countM=0, //count how many ship spot I hit
           countY=0; //count how many ship spot opponent hit
    char   direct;  // how to set the ship direction
    string Label;   //ship's name
    string myBoard[ROWS][COLS], //two player's game board array[10][10]
           youBoard[ROWS][COLS];
    string myName,// first player name
           youName,//opponent player name
           winner;
    
    //Display the battle ship game board looks like
     systemBoard();
     
    //read the last game winner data from file
    ifstream lastFile;
    lastFile.open("BattleShip.dat",ios::in);
    lastFile>>winner;
    lastFile.close();
    cout<<"Last game winner is "<<winner<< endl;
    cout<<endl;
    
    // open file to write new game data
      ofstream myFile;
      myFile.open("BattleShip.dat");
      
     
     //initialize two player's game board, all set to *
     initialBoard(myBoard);
     initialBoard(youBoard);
     //input player's name
     cout<<"First player name :"<<endl;
     cin>>myName;
     cout<<"second player name:"<<endl;
     cin>>youName;
     // just a decorate line
     decorationLine();
    
     
    //First, players set all the ships
     //the first player starts to set 
     cout<<myName<<" set the ships"<<endl;
     ship=2; // initialize the ship minimum length start from 2 
  do{
     shiplabel(ship, Label, space);
     cout<<"Choose the first starting point for '"<<Label<<"' need space "<<space<<endl;
     cout<<"Input Row[0-9]/Column[0-9]"<<endl;
     cin>>firstR>>firstC;
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
    if(ship>5) cout<<"My ships are settled as above!!"<<endl;
   }  while(ship<=5);
    
      decorationLine();
   //Opponent place the ship, 
     cout<<youName<<" set the ships"<<endl;
     ship=2; // initialize the ship length start from 2 
  do{
     shiplabel(ship, Label, space);
     cout<<"Choose the first starting point for '"<<Label<<"' need space "<<space<<endl;
     cout<<"Input Row[0-9]/Column[0-9]"<<endl;
     cin>>firstR>>firstC;
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
             if(space==2) youBoard[firstR][i]="D";
             if(space==3) youBoard[firstR][i]="C";
             if(space==4) youBoard[firstR][i]="B";
             if(space==5) youBoard[firstR][i]="A";
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
             if(space==2) youBoard[i][firstC]="D";
             if(space==3) youBoard[i][firstC]="C";
             if(space==4) youBoard[i][firstC]="B";
             if(space==5) youBoard[i][firstC]="A";}
             break;
          case 'U':for(int i=firstR; i>(firstR-space); i--){
             if(space==2) youBoard[i][firstC]="D";
             if(space==3) youBoard[i][firstC]="C";
             if(space==4) youBoard[i][firstC]="B";
             if(space==5) youBoard[i][firstC]="A";}
             break;
               }
     cout<<endl;
     cout<<left;
     cout<<setw(19)<<setfill('=')<<"Your Board"<<endl;
     displayBoard(youBoard, ROWS);
     ship++; 
     cout<<endl;
    if(ship>5) cout<<"Your ships are settled as above,Let's battle."<<endl;
   }  while(ship<=5);
    
  decorationLine(); 
  
   // start to guess, if hit change the value to "0", if miss change the value to "X"
   // first player guess turn  
  do{
     int guessR, guessC;  //guessR= guess row number; guessC= guess Column number;
     string nameM, nameY; 
     
     cout<<myName<<endl;
     cout<<"Input row and column number between 0-9"<<endl;
   //  cin>>guessR>>guessC;
      guessR=rand()%10; //generate random guess number for second player
     guessC=rand()%10;
     cout<<guessR<<" "<<guessC<<endl;
     
     guess(youBoard,guessR,guessC);
     if( guess(youBoard,guessR,guessC) ) {
         nameY= hitWhichShip(  youBoard,guessR,guessC, nameY);
         cout<<"HIT "<<nameY<<endl<<endl;
         youBoard[guessR][guessC]="1";}
     else {
         cout<<"MISS"<<endl<<endl;; 
         youBoard[guessR][guessC]="0";}
     
 //     displayBoard(youBoard, ROWS);
      // searching for the sink ship and display, count how many spot hit, 4ships total take 14 spot
           if (nameY=="Carrier")    {searchSink1( youBoard);  countM++;}
      else if (nameY=="Battleship") {searchSink2( youBoard);  countM++;}
      else if (nameY=="Cruiser")    {searchSink3( youBoard);  countM++;}
      else if (nameY=="Destroyer")  {searchSink4( youBoard);  countM++;}
     
     decorationLine();
    
     // second player's guess turn
     cout<<youName<<endl;
     cout<<"Input row and column number between 0-9"<<endl;
   //  cin>>guessR>>guessC;
     
     guessR=rand()%10; //generate random guess number for second player
     guessC=rand()%10;
     cout<<guessR<<" "<<guessC<<endl;
     guess(myBoard,guessR,guessC);
     if( guess(myBoard,guessR,guessC) ) {
         nameM= hitWhichShip(  myBoard,guessR,guessC, nameM);
         cout<<"HIT "<<nameM<<endl<<endl;
         myBoard[guessR][guessC]="1";}
     else {
         cout<<"MISS"<<endl<<endl;; 
         myBoard[guessR][guessC]="0";}
     
       //   displayBoard(myBoard, ROWS);
      // searching for the sink ship and display, count how many spot hit, 4ships total take 14 spot
           if (nameM=="Carrier")    {searchSink1( myBoard); countY++;}
      else if (nameM=="Battleship") {searchSink2( myBoard); countY++;}
      else if (nameM=="Cruiser")    {searchSink3( myBoard); countY++;}
      else if (nameM=="Destroyer")  {searchSink4( myBoard); countY++;}

     
   }while ( countM<14 && countY<14);
   
    cout<<myName<<"   Game Board"<<endl;
    displayBoard(myBoard, ROWS);
    cout<<endl;
    cout<<youName<<"  Game Board"<<endl;
    displayBoard(youBoard, ROWS);
   
        if(countM==14)    winner=myName;
   else if(countY==14)    winner=youName;
   //write winner data into file
   myFile<<winner<<endl;
   
   cout<<setw(30)<<setfill('-')<<"-"<<endl;
   cout<<"WINNER"<<setw(24)<<setfill(' ')<<right<<winner<<endl;
   cout<<setw(30)<<setfill('-')<<"-"<<endl;
   

 
  //Close file
 myFile.close(); 

    return 0;
}
void decorationLine(){
    for (int i=0; i<25; i++){
        cout<<"-";
    }cout<<endl;
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
void initialBoard(string a[10][10]){
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
	cout << " |0|1|2|3|4|5|6|7|8|9|"<<endl;
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