
/* 
 * File:   board.h
 * Author: Ting Sha
 * Created on November 29, 2022, 10:56 AM
 * Project2: Battle ship board game board headerfile
 */
#include <iostream>  //I/O Library
#include <string>


using namespace std;
#ifndef BOARD_H
#define BOARD_H


class BaseBoard
{
public:
    int row=10,col=10;
    //use static member initialize board array to 0
    static int boardAry[10][10];
   //default constructor
    BaseBoard( ){};  
    void displayBoard();//display initial board
    ~BaseBoard(); //destructor delete allocate memory   
};

//player board inheritance from baseboard
class PlayerBoard : public BaseBoard
{
 
public:
     int guessR, guessC;
    //use constructor to arrange the ships
   PlayerBoard(){
      setBoard();
      }
   //set all the ships spot
    void setBoard(); 
    //start game guess function
    void gameguess();
    //result check function
    bool resultCheck( );
   //get the player board array data after set
   int getBoard(); 
};



#endif /* BOARD_H */

