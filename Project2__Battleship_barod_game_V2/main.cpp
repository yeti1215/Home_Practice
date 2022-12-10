
/* 
 * File:   main.cpp
 * Author: Ting Yin Sha
 * Created on November 27, 2022, 1:30 PM
 * Project2: Battle ship board game Version 3( one class set two board with two function)
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
   string name; //ask for the players name
   char again;  //ask player play again or not
     cout<<"Welcome to Battle Ship Game"<<endl;
    //initialize the game board and display how it looks
    BaseBoard baseboard;
    baseboard.displayBoard(baseboard.boardAry1);
    
    // const int arySize=20;
   // Player player[arySize];

    //Add the first player, allocate memory for the PNmame class
    AbsPName *pname1 = new PName;
    //pass the name as an argument
    cout << "Input the first player name:" << endl;
    getline(cin, name); //the name size is 20
    pname1->setName(name);
    //score need to be set after the game started, and update after each game
    AbsPScore *pscore1 = new PScore;

    //Add the second player
    AbsPName *pname2 = new PName;
    //pass the name as an argument
    cout << "Input the second player name:" << endl;
    //cin.ignore();
    getline(cin, name); //the name size is 20
    pname2->setName(name);
    //score need to be set after the game started, and update after each game
    AbsPScore *pscore2 = new PScore;

    do {
        //start play
        //define a PlayerBoard class, so we can set two players game board and play
        PlayerBoard playerboard;
        //set the game board for the first player
        cout << endl;
        cout << pname1->p_name << " set ships" << endl;
        playerboard.setBoard1();
        playerboard.getBoard(playerboard.boardAry1);
        playerboard.displayBoard(playerboard.boardAry1);
        //   set the game board for the second player
        cout << endl;
        cout << pname2->p_name << " set ships" << endl;
        playerboard.setBoard2();
        playerboard.getBoard(playerboard.boardAry2);
        playerboard.displayBoard(playerboard.boardAry2);
          
        //use while loop to check the result and keep guessing
   while(!playerboard.resultCheck(playerboard.boardAry1) && !playerboard.resultCheck(playerboard.boardAry2) ){
        //player1 guess second board and return the new game board after hit
      playerboard.gameguess2( );
      playerboard.getBoard(playerboard.boardAry2);
     // playerboard.displayBoard(playerboard.boardAry2);
       //player2 guess the first baordand return the new game board after hit
      playerboard.gameguess1();
      playerboard.getBoard(playerboard.boardAry1);
    //  playerboard.displayBoard(playerboard.boardAry1);
     
      
      }
    //score++
   if(playerboard.resultCheck(playerboard.boardAry1) && !playerboard.resultCheck(playerboard.boardAry2)){
       cout<<"Winner "<<pname2->p_name<<endl;
       pscore2->operator ++();
       cout<<"LOSER  "<<pname1->p_name<<endl;   
   }
   else
   {
       cout<<"Winner "<<pname1->p_name<<endl;
       pscore1->operator ++();
       cout<<"LOSER "<<pname2->p_name<<endl;
   }
        
        cout<<"Play again? Y/N"<<endl;
        cin>>again;
    //display game board after all sank
  //  playerboard1.displayBoard();
      //display player's name and score after the  game
    } while (toupper(again)=='Y');
    
    Player* player1=new Player(pname1,pscore1);
    cout<<*player1<<endl;
    
    Player* player2=new Player(pname2,pscore2);
    cout<<*player2<<endl;
    
       //release the memory
 
    
    
        return 0;
}
