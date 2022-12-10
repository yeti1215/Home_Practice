
/* 
 * File:   game.cpp
 * Author: yeti
 * Created on November 29, 2022, 10:56 AM
 * Project2: Battle ship board game cpp
 */

#include <iostream>  //I/O Library
#include <string>    //String Library
#include <ctime>
#include "game.h"
#include "board.h"

using namespace std;

void Game::playgame(){
   
        cout << endl;
       // cout << pname1->p_name << " set ships" << endl;
        playerboard.setBoard1();
        playerboard.getBoard(playerboard.boardAry1);
        playerboard.displayBoard(playerboard.boardAry1);
        //   set the game board for the second player
        cout << endl;
       // cout << pname2->p_name << " set ships" << endl;
        playerboard.setBoard2();
        playerboard.getBoard(playerboard.boardAry2);
        playerboard.displayBoard(playerboard.boardAry2);
          
        //use while loop to check the result and keep guessing
   while(!resultCheck1() && !resultCheck2() ){
        //player1 guess second board and return the new game board after hit
     try{ 
         gameguess2( );
      playerboard.getBoard(playerboard.boardAry2);
      //if the guess number out of range throw exception class
      if(guessR<0 ||guessR>9 ||guessC<0 ||guessC>9)
      {
          throw OutofRange();
      }
     }
     //Exception class catch
     catch(Game::OutofRange)
     {
         cout<<"Error: A out of range value was entered"<<endl;
         //reinput value agian after exception call
          gameguess2( );
      playerboard.getBoard(playerboard.boardAry2);
     }
     try{
       //player2 guess the first board and return the new game board after hit
      gameguess1();
      playerboard.getBoard(playerboard.boardAry1);
      if(guessR<0 ||guessR>9 )
      {
          throw "ERROR: Row value out of range 0-9";
      }
      if(guessC<0 ||guessC>9)
      {
          throw 0;
      }
     }
     // catch string exception
     catch(const char* exceptionStr)
     {
         cout<<"ERROR: Row value out of range 0-9"<<endl;
         gameguess1();
      playerboard.getBoard(playerboard.boardAry1);
     }
     // catch int exception
     catch (int exceptionInt)
     {
         cout<<"ERROR: Column value out of range 0-9"<<endl;
         gameguess1();
      playerboard.getBoard(playerboard.boardAry1);
     }


    }

}

void Game::gameguess1() {
    guessR = rand() % +10; //random row range 0-9
    guessC = rand() % +10; //random column range 0-9
    if (playerboard.boardAry1[guessR][guessC] == 1) //if guess spot is '1' means hit
    {

        playerboard.boardAry1[guessR][guessC] = 0;
    } // then need set this spot to '0'
}

void Game::gameguess2() {
    //random row range 0-9, in order to call the exception, so extend the rang 0-10
    guessR = rand() % +10; 
 
    guessC = rand() % +10; //random column range 0-9
    if (playerboard.boardAry2[guessR][guessC] == 1) //if guess spot is '1' means hit
    {

        playerboard.boardAry2[guessR][guessC] = 0;
    } // then need set this spot to '0'
}
 
 
 bool Game::resultCheck1( ){
    //check the first player's ship
    bool result=true; //true means all sank
    for(int i=0; i<playerboard.row; i++){
        for (int j=0; j<playerboard.col; j++){
            if(playerboard.boardAry1[i][j]==1) 
                result=false;
            // return false if still has '1' in game board,
             //otherwise return true, means all the ships sank
            
        }
    }
    return result;
}
  bool Game::resultCheck2( ){
    //check the second player's ship
    bool result=true; 
    for(int i=0; i<playerboard.row; i++){
        for (int j=0; j<playerboard.col; j++){
            if(playerboard.boardAry2[i][j]==1) 
                result=false;
            // return false if still has '1' in game board,
            //otherwise return true, means all the ships sank
            
        }
    }
    return result;
}