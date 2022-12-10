
/* 
 * File:   main.cpp
 * Author: Ting Yin Sha
 * Created on November 27, 2022, 1:30 PM
 * Project2: Battle ship board game Version 2(only one player)
 */

//  Class with private member, .h .cpp files split
//constructor, destructors
//Arrays of Objects
//Static, friends, copy constructors
//overload 3operators, aggregation
//inheritance: protected members, base class to derived, polymorphic 
//Abstract class, exception and templates, STL
#include <iostream>  //I/O Library
#include <string>    //String Library
#include <ctime>   //Random Number Generator, Setting Seed
#include <cstring>
#include <iomanip>  //Formatting Library
#include <cstdlib>   //Type Conversion, memory allocation, srand/Rand
#include <cctype>
#include "board.h"
#include "player.h"

using namespace std;
int main(int argc, char** argv) {
   srand(static_cast<unsigned short>(time(0)));
     cout<<"Welcome to Battle Ship Game"<<endl;
    //initialize the gameboard and display how it looks
     BaseBoard baseboard;
    baseboard.displayBoard();
    
    // const int arySize=20;
   // Player player[arySize];
    
    //Add the first players, allocate memory for the PNmame class
    AbsPName *pname1=new PName;
    //pass the name as an argument
    pname1->setName("Ting");
    //score need to be set after the game started, and update after each game
    AbsPScore *pscore1=new PScore;

    for(int i=0; i<5;i++){
    //start play
    //set the game board for the first player
   PlayerBoard playerboard1;
   playerboard1.displayBoard();
   
        int guesstime=0;   
        //use while loop to check the result and keep guessing
   while(playerboard1.resultCheck()){
       //player1 guess and return the new game board after hit
      playerboard1.gameguess();
      playerboard1.getBoard();
      guesstime++;
     // cout<<"guesstime="<<guesstime<<endl;
     // boardAry2=Gameguess(boardAry2,row,col);
      }
    //score++
   if(!playerboard1.resultCheck()){
    pscore1->operator ++();
   }
    //display game board after all sank
  //  playerboard1.displayBoard();
      //display player's name and score after the  game
    }
    Player* player1=new Player(pname1,pscore1);
    cout<<*player1<<endl;
    
       //release the memory
   //set the game board for the second player
 //  PlayerBoard playerboard2;
 // playerboard2.displayBoard();
    
    
        return 0;
}
