

/* 
 * File:   game.h
  * Author: Ting Sha
 * Created on November 29, 2022, 1:46 PM
 *  Project2: Battle ship board game player headerfile
 */
#include <iostream>  //I/O Library
#include <string>    //String Library
#include <ctime>
using namespace std;

#ifndef GAME_H
#define GAME_H
#include "board.h"

//this file shows game part
class Game
{
public:
    int guessR, guessC;
    //Aggregation, Game class contains PlayerBoard class
    PlayerBoard playerboard; 
    //default constructor to initialize elements
    Game(){
         guessR=0; guessC=0;
    }
    //start game guess function
    void playgame( );
    //two players take turns to guess, call different guess functions
    void gameguess1();
    void gameguess2();
    bool resultCheck1( );
    bool resultCheck2( );
    //Exception class
    class OutofRange{};// Empty class declaration
   // ~Game()
};


#endif /* GAME_H */

