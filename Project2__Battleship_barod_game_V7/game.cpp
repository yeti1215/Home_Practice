
/* 
 * File:   game.cpp
 * Author: Ting Yin Sha
 * Created on November 29, 2022, 10:56 AM
 * Project2: Battle ship board game cpp
 */

#include <iostream>  //I/O Library
#include <string>    //String Library
#include <ctime>
#include <vector>
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
        //set each ship check bool to false
        bool isCarrier1=false;
        bool isBattle1=false;
        bool isSubmarine1=false;
        bool isDestroy1=false;
        
        bool isCarrier2=false;
        bool isBattle2=false;
        bool isSubmarine2=false;
        bool isDestroy2=false;
        
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
         //reinput value again after exception call
         cout<<"Please input number between 0-9"<<endl;
          gameguess2( );
      playerboard.getBoard(playerboard.boardAry2);
     }
      // catch string exception
     catch(const char* exceptionStr)
     {
         cout<<"ERROR: Row value out of range 0-9"<<endl;
         cout<<"Please input number between 0-9"<<endl;
         gameguess2();
       playerboard.getBoard(playerboard.boardAry2);
     }
     // catch int exception
     catch (int exceptionInt)
     {
         cout<<"ERROR: Column value out of range 0-9"<<endl;
         cout<<"Please input number between 0-9"<<endl;
         gameguess2();
      playerboard.getBoard(playerboard.boardAry2);
     }
     
      //player2 guess the first board and return the new game board after hit
     try{
      
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
         cout<<"Please input number between 0-9"<<endl;
         gameguess1();
      playerboard.getBoard(playerboard.boardAry1);
     }
     // catch int exception
     catch (int exceptionInt)
     {
         cout<<"ERROR: Column value out of range 0-9"<<endl;
         cout<<"Please input number between 0-9"<<endl;
         gameguess1();
      playerboard.getBoard(playerboard.boardAry1);
     }
      //Exception class catch
     catch(Game::OutofRange)
     {
         cout<<"Error: A out of range value was entered"<<endl;
         cout<<"Please input number between 0-9"<<endl;
         //re-input value again after exception call
          gameguess1( );
      playerboard.getBoard(playerboard.boardAry1);
     }
     
//check player2 Carrier sank or not
          if(!isCarrier2 && Carriercheck2()){
                 cout<<"Player2 Carrier Sank"<<endl;
              isCarrier2=true;
          }
      if(!isBattle2 && Battlecheck2()){
          cout<<"Player2 Battleship Sank"<<endl;
          isBattle2=true;
      }
      
      if(!isSubmarine2 && Submarinecheck2()){
          cout<<"Player2 Submarine/Cruiser Sank"<<endl;
          isSubmarine2=true;
      }
      if(!isDestroy2 && Destroycheck2()){
          cout<<"Player2 Destroy Sank"<<endl;
          isDestroy2=true;
      }
      //check player1 Carrier sank or not
          if(!isCarrier1 && Carriercheck1()){
                 cout<<"Player1 Carrier Sank"<<endl;
              isCarrier1=true;
          }
      if(!isBattle1 && Battlecheck1()){
          cout<<"Player1 Battleship Sank"<<endl;
          isBattle1=true;
      }
      
      if(!isSubmarine1 && Submarinecheck1()){
          cout<<"Player1 Submarine/Cruiser Sank"<<endl;
          isSubmarine1=true;
      }
      if(!isDestroy1 && Destroycheck1()){
          cout<<"Player1 Destroy Sank"<<endl;
          isDestroy1=true;
      }

    }

}

void Game::gameguess1() {
    guessR = rand() % +10; //random row range 0-9
    guessC = rand() % +11; //random column range 0-9
    //if guess spot is not 0 means hit
    if (playerboard.boardAry1[guessR][guessC] !=0) 
    {

        playerboard.boardAry1[guessR][guessC] = 0;
    } // then need set this spot to '0'
}

void Game::gameguess2() {
    //random row range 0-9, in order to call the exception, so extend the rang 0-10
    guessR = rand() % +10; 
 
    guessC = rand() % +10; //random column range 0-9
    //if guess spot is not 0 means hit
    if (playerboard.boardAry2[guessR][guessC] !=0) 
    {

        playerboard.boardAry2[guessR][guessC] = 0;
    } // then need set this spot to '0'
}
 
 
 bool Game::resultCheck1( ){
    //check the first player's ship
    bool result=true; //true means all sank
    
    for(int i=0; i<playerboard.row; i++){
        for (int j=0; j<playerboard.col; j++){
             
            if(playerboard.boardAry1[i][j]!=0) 
                result=false;
            // return false if the array not all 0,
             //otherwise return true, means all the ships sank
        }
        
    }
    
    return result;
}
  bool Game::resultCheck2( ){
    //check the second player's ship
    bool result=true; 
    for(int i=0; i<playerboard.row; i++){
        for (int j=0; j<playerboard.col; j++)
        {
            if(playerboard.boardAry2[i][j]!=0) 
                result=false;
           // return false if the array not all 0,
            //otherwise return true, means all the ships sank
            
        }
    }
  
    return result;
}
  bool Game::Carriercheck2(){
      bool sank=false;
      
          for(int i=0; i<playerboard.row; i++){
        for (int j=0; j<playerboard.col; j++){
            if(playerboard.boardAry2[i][j]!=5 ) 
              
            sank=true;
        }  
    }
     return sank; 
  }

bool Game::Battlecheck2() {
    bool sank = false;

    for (int i = 0; i < playerboard.row; i++) {
        for (int j = 0; j < playerboard.col; j++) {
            if (playerboard.boardAry2[i][j] != 4)

                sank = true;
        }
    }
    return sank;
}

bool Game::Submarinecheck2() {
    bool sank = false;

    for (int i = 0; i < playerboard.row; i++) {
        for (int j = 0; j < playerboard.col; j++) {
            if (playerboard.boardAry2[i][j] != 3)

                sank = true;
        }
    }
    return sank;
}

bool Game::Destroycheck2() {
    bool sank = false;

    for (int i = 0; i < playerboard.row; i++) {
        for (int j = 0; j < playerboard.col; j++) {
            if (playerboard.boardAry2[i][j] != 2)

                sank = true;
        }
    }
    return sank;
}

  bool Game::Carriercheck1(){
      bool sank=false;
      
          for(int i=0; i<playerboard.row; i++){
        for (int j=0; j<playerboard.col; j++){
            if(playerboard.boardAry1[i][j]!=5 ) 
              
            sank=true;
        }  
    }
     return sank; 
  }

bool Game::Battlecheck1() {
    bool sank = false;

    for (int i = 0; i < playerboard.row; i++) {
        for (int j = 0; j < playerboard.col; j++) {
            if (playerboard.boardAry1[i][j] != 4)

                sank = true;
        }
    }
    return sank;
}

bool Game::Submarinecheck1() {
    bool sank = false;

    for (int i = 0; i < playerboard.row; i++) {
        for (int j = 0; j < playerboard.col; j++) {
            if (playerboard.boardAry1[i][j] != 3)

                sank = true;
        }
    }
    return sank;
}

bool Game::Destroycheck1() {
    bool sank = false;

    for (int i = 0; i < playerboard.row; i++) {
        for (int j = 0; j < playerboard.col; j++) {
            if (playerboard.boardAry1[i][j] != 2)

                sank = true;
        }
    }
    return sank;
}
