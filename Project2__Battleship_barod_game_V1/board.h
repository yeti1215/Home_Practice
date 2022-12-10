
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
    static int boardAry1[10][10];
     static int boardAry2[10][10];
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
    int startR; //first spot row
    int startC; //first spot column
    char direct; //arrange direction
    int count;
    int selectD;
    //default constructor 

    PlayerBoard();
    //set all the ships spot
    void setBoard();
    //start game guess function
    void gameguess();
    //result check function
    bool resultCheck();
    //get the player board array data after set or hit
    int getBoard(); 
   // ~PlayerBoard();
};



#endif /* BOARD_H */

