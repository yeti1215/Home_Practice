
/* 
 * File:   board.cpp
 * Author: yeti
 * Created on November 29, 2022, 10:56 AM
 * Project2: Battle ship board game board cpp
 */
#include <iostream>  //I/O Library
#include <string>    //String Library
#include "board.h"

using namespace std;

//initialize static boardAry in base class
int BaseBoard::boardAry[10][10]={0};

//set the ships
void PlayerBoard::setBoard()
{
    int startR=0; //first spot row
    int  startC=0; //first spot column
    char direct; //arrange direction
   int count=0;
    int selectD;
    
    cout<<"The size of ship: Carrier=5 Battleship=4 Submarine=3 Destroyer=2"<<endl;
    cout<<"Choose ship direction: R=right D=down"<<endl;
   //use do while to arrange ships
    
    do{
        //array=getData(row,col);
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
          boardAry[startR][i]=1;     
        }  
            break;

        case 'D': for(int i=startR; i<(startR+size);i++){
            boardAry[i][startC]=1;
        }
            break;
        default:
            break;}
    size--;
    }while(size>=2);
    
    //check ship arrange successes, total should 14 one
    for(int i=0; i<row;i++){
        for(int j=0; j<row; j++){
            { if(boardAry[i][j]==1)count++; //'1' means set up, if count doesn't meet 14 need to be reset
            
             }}      
        }
    
    }while(count<14);
  
}
 void PlayerBoard::gameguess(){
     
    guessR=rand()%+10; //random row range 0-9
    guessC=rand()%+10;//random column range 0-9
          if(boardAry[guessR][guessC]==1) //if guess spot is '1' means hit
    {
              cout<<"HIT"<<endl;
    boardAry[guessR][guessC]=0;} // then need set this spot to '0'
 
}
 bool PlayerBoard::resultCheck( ){
    
    bool result=0; 
    for(int i=0; i<row; i++){
        for (int j=0; j<col; j++){
            if(boardAry[i][j]==1) result=1;// return true if still has '1' in game board,
                                          //otherwise return false, means all the ships sank
            
        }
    }
    return result;
}
//return the array value
int PlayerBoard::getBoard(){
      return boardAry[10][10];
}


void BaseBoard::displayBoard(){
    
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
        cout<<"test:Destructor of BaseBoard"<<endl;
    
}

