
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
    void displayBoard(int boardAry[10][10]);//display initial board
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
    //use two different set function to set each two player's board
    void setBoard1();
    void setBoard2();
    //start game guess function
    void gameguess1();
    void gameguess2();
    //result check function
    bool resultCheck(int boardAry[10][10]);
    //get the player board array data after set or hit
    int getBoard(int boardAry[10][10]); 
   // ~PlayerBoard();
};



#endif /* BOARD_H */

