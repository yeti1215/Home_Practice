
/* 
 * File:   board.cpp
 * Author: yeti
 * Created on November 29, 2022, 10:56 AM
 * Project2: Battle ship board game board cpp
 */
#include <iostream>  //I/O Library
#include <string>    //String Library
#include <ctime>
#include "board.h"


using namespace std;

//initialize static boardAry in base class
int BaseBoard::boardAry1[10][10]={0};
int BaseBoard::boardAry2[10][10]={0};

 PlayerBoard::PlayerBoard() {
    startR = 0; //first spot row
    startC = 0; //first spot column
    direct; //arrange direction
    count = 0;
    selectD;
   for(int i=0;i<10;i++){
            for(int j=0;j<10;j++){
               boardAry1[i][j]=0; 
                boardAry2[i][j]=0; 
            }
        }
   
    }
//first player set the ships
void PlayerBoard::setBoard1()
{
    
    cout<<"The size of ship: Carrier=5 Battleship=4 Submarine=3 Destroyer=2"<<endl;
    cout<<"Choose ship direction: R=right D=down"<<endl;
   //use do while to arrange ships
    
    do{
       for(int i=0;i<10;i++){
            for(int j=0;j<10;j++){
               boardAry1[i][j]=0; 
            }
        }
         int size=5;
         count=0; // for count how many spot,if count=14 means all set
    do{
          selectD=rand()%2+1; //random get 1 or 2,represents Right or Down
          if(selectD==1)direct='R'; 
          else          direct='D';
          
          startR=rand()%(11-size);  //random get row start point 
          startC=rand()%(11-size); //random get column start point 
          
    //Use switch case to check ship direction
    switch(toupper(direct)){
        case 'R':for(int i=startC; i<(startC+size);i++){
          boardAry1[startR][i]=1;     
        }  
            break;

        case 'D': for(int i=startR; i<(startR+size);i++){
            boardAry1[i][startC]=1;
        }
            break;
        default:
            break;}
    size--;
    }while(size>=2);
    
    //check ship arrange successes, total should 14 one
    for(int i=0; i<row;i++){
        for(int j=0; j<row; j++){
            { if(boardAry1[i][j]==1)count++; //'1' means set up, if count doesn't meet 14 need to be reset
           
             }}      
        }
    
    }while(count<14);
  
}

void PlayerBoard::setBoard2()
{
    
    cout<<"The size of ship: Carrier=5 Battleship=4 Submarine=3 Destroyer=2"<<endl;
    cout<<"Choose ship direction: R=right D=down"<<endl;
   //use do while to arrange ships
    
    do{
       for(int i=0;i<10;i++){
            for(int j=0;j<10;j++){
               boardAry2[i][j]=0; 
            }
        }
         int size=5;
         count=0; // for count how many spot,if count=14 means all set
    do{
          selectD=rand()%2+1; //random get 1 or 2,represents Right or Down
          if(selectD==1)direct='R'; 
          else          direct='D';
          
          startR=rand()%(11-size);  //random get row start point 
          startC=rand()%(11-size); //random get column start point 
          
    //Use switch case to check ship direction
    switch(toupper(direct)){
        case 'R':for(int i=startC; i<(startC+size);i++){
          boardAry2[startR][i]=1;     
        }  
            break;

        case 'D': for(int i=startR; i<(startR+size);i++){
            boardAry2[i][startC]=1;
        }
            break;
        default:
            break;}
    size--;
    }while(size>=2);
    
    //check ship arrange successes, total should 14 one
    for(int i=0; i<row;i++){
        for(int j=0; j<row; j++){
            { if(boardAry2[i][j]==1)count++; //'1' means set up, if count doesn't meet 14 need to be reset
           
             }}      
        }
    
    }while(count<14);
  
}

int PlayerBoard::getBoard(int boardAry[10][10]){
      return boardAry[10][10];
}


void BaseBoard::displayBoard(int boardAry[10][10])
{
    
       cout<<"   ";
    for(int i=0; i<row; i++){
        cout<<" "<<i;
    } cout<<endl;
    for(int i=0; i<row; i++){
        cout<<"  "<<char('A'+i);
        for(int j=0;j<col; j++){
          cout<<" "<<boardAry[i][j];  }
            
         cout<<endl;}
      }


BaseBoard::~BaseBoard()
{  
  
    
}

