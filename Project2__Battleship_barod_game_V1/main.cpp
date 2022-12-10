
/* 
 * File:   main.cpp
 * Author: Ting Yin Sha
 * Created on November 27, 2022, 1:30 PM
 * Project2: Battle ship board game Version 3( add second player)
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
    baseboard.displayBoard();
    
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
        //set the game board for the first player
        cout << endl;
        cout << pname1->p_name << " set ships" << endl << endl;
        PlayerBoard playerboard1;
        playerboard1.setBoard1();
        playerboard1.getBoard1();
        playerboard1.displayBoard();
        //   set the game board for the second player
        cout << pname2->p_name << " set ships" << endl << endl;
        PlayerBoard playerboard2;
        playerboard2.setBoard2();
        playerboard2.getBoard2();
        cout<<"after call board2"<<endl;
        playerboard2.displayBoard();
          
        //use while loop to check the result and keep guessing
   while(!playerboard1.resultCheck() && !playerboard2.resultCheck() ){
        //player1 guess and return the new game board after hit
      playerboard2.gameguess();
      playerboard2.getBoard();
      playerboard2.displayBoard();
       //player2 guess and return the new game board after hit
      playerboard1.gameguess();
      playerboard1.getBoard();
      playerboard1.displayBoard();
     
      
      }
    //score++
   if(playerboard1.resultCheck() && !playerboard2.resultCheck()){
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
