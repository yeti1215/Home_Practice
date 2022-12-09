
/* 
 * File:   main.cpp
 * Author: Ting Yin Sha
 * Created on October 27, 2022, 1:30 PM
 * Project: Battle ship board game Version 8 one file (final)
 */

//   Memory allocation with arrays and structures.
//     Functions with structures, used as input and output to the function.
//     Pointers with arrays and arrays of structures, internally as well as externally.
//     Use of character arrays as well as string objects.
//     Reading and writing to binary files.
#include <iostream>  //I/O Library
#include <string>    //String Library
#include <fstream>   //File Library
#include <ctime>   //Random Number Generator, Setting Seed
#include <cstring>
#include <iomanip>  //Formatting Library
#include <cstdlib>   //Type Conversion, memory allocation, srand/Rand
#include <cctype>
using namespace std;
//assigning a interger row to enum Variable
enum ROW{A,B,C,D,E,F,G,H,I,J};
const int MAX=100; //MAX can be change here if need larger size

struct Playerinfo{
    char *name;  //player name pinter, string will cause invalid pointer, because of coping structure many times
    int win;      
    int lose;
};

struct PlayerTotal{
    struct Playerinfo playerAry[MAX];//limit the Max player,MAX is a global constant
    int size=0; //count the array structure size
};

void showBoardgame(char **);
char **getData(int &, int &);
char **shipArrange(char **, int row, int );
char **Gameguess(char ** , int , int );
bool resultCheck( char**,int , int );
void addplayer(struct PlayerTotal *);
void resultPrint(struct PlayerTotal * );
void WriteAndRead(fstream &, PlayerTotal *,PlayerTotal *);
void  randomAccessFile(fstream &,PlayerTotal *);
void     destroy(char **,int);

int main(int argc, char** argv) {
    srand(static_cast<unsigned short>(time(0)));
    cout<<"Welcome to battle ship board game!\n"<<endl;

    //declare variables
    int select; // for choose from menu
    int row, col; // rows and columns of game board
    char again; // play again or not
    char **boardAry1=nullptr;; // first game board array pointer
    char **boardAry2=nullptr;; // second game board array pointer
    struct Playerinfo players; //set a structure with 2 players
    struct PlayerTotal PTL; //game data structure
    struct PlayerTotal RTL;//Reading from file and store data in new structure
    struct PlayerTotal ATL;//store random file data;
    fstream file,file2;
    
   //pass value by memory allocation array with function
    boardAry1=getData(row,col); //initialize board to 0
    boardAry2=getData(row,col); //initialize board to 0
    showBoardgame(boardAry1); //use Enumerated data show the board of battle ship game
    //initialize structure's elements to 0 and add player's name
    {addplayer(&PTL);   PTL.size++;} //add one player
    {addplayer(&PTL);   PTL.size++;} //add another player
   
    // Now we can play the game in a loop and can change player, till quit loop
    do{
    // each player secretly arranges their ships
    cout<<"Now each player secretly arranges ships"<<endl;
 
    cout<<PTL.playerAry[PTL.size-2].name<<" arrange ships"<<endl; 
    int size=5;
   
    boardAry1=shipArrange(boardAry1,10,10);  ////player 1 arrange ships
    showBoardgame(boardAry1);         //print player 1's board
   
    cout<<PTL.playerAry[PTL.size-1].name<<" arrange ships"<<endl; 
    boardAry2=shipArrange(boardAry2,row,col);  //player 2 arrange ships
    showBoardgame(boardAry2);           //print player 2's board
    
    //2 players take turns to guess and check result, if any player's result is false,means win and stop guess
      while(resultCheck(boardAry1,row,col)&&  resultCheck(boardAry2,row,col)){
      boardAry1=Gameguess(boardAry1,row,col);
      boardAry2=Gameguess(boardAry2,row,col);
      }
    if(!resultCheck(boardAry1,row,col)) 
    {cout<<PTL.playerAry[PTL.size-2].name<<" Win"<<endl;
    PTL.playerAry[PTL.size-2].win++;
    PTL.playerAry[PTL.size-1].lose++;
    }
    else {
        cout<<PTL.playerAry[PTL.size-1].name<<" Win"<<endl;
         PTL.playerAry[PTL.size-1].win++;
         PTL.playerAry[PTL.size-2].lose++;
    }
    
    cout<<"Play again? Y/N"<<endl;
    cin>>again;
    if(toupper(again)=='Y'){
     cout<<"same player? Y/N"<<endl; //no need add new player's info if the same player
        char choice;
        cin>>choice;
     if(toupper(choice)=='N'){
           cout<< "Hit any key to continue..."<<endl;
        cin.ignore();
    {addplayer(&PTL);   PTL.size++;} //add one player
    {addplayer(&PTL);   PTL.size++;} //add another player
        }}
  //delete 2D array allocate memory and point to nullptr  
    destroy(boardAry1, row); 
    destroy(boardAry2, row);
    boardAry1=nullptr;
    boardAry2=nullptr;
    }while(toupper(again)=='Y');
    
  
    //display the final game report include all the players
    cout<<"Thank you! Here is the result statics:"<<endl;
    resultPrint(&PTL);

    //Input and output binary file simultaneous,Random access file and print
    randomAccessFile(file,&PTL);
      //Writing and reading to file
     WriteAndRead(file2, &PTL,&ATL );
   //destroy structure's  dynamic name
    for(int i=0; i<PTL.size; i++){
        delete []PTL.playerAry[i].name;// clean up the character arrays in the structure
    }
    return 0;
}

void showBoardgame(char **boardAry){
   
    cout<<"   ";
    for(int row=A; row<=J; row=static_cast<ROW>(row+1)){
        cout<<" "<<row;
    } cout<<endl;
    for(int row=A; row<=J; row=static_cast<ROW>(row+1)){
        cout<<"  "<<char('A'+row);
        for(int col=A; col<=J; col=static_cast<ROW>(col+1)){
          cout<<" "<<boardAry[row][col];  }
         cout<<endl;}
}

char **getData(int &row, int &col){
 
 // initialize 2D array to '0'   
    row=10; col=10;
    char **data = new char *[row];// this data need to be return, so will delete the return dynamic array in main
    for(int i=0; i<row; i++){
        data[i]=new char[col];//allocate column memory for 2D pointer array
    }
    for (int i=0; i<row; i++){
        for (int j=0; j<col; j++){
            data[i][j]='0'; //initialize game board with '0'
        }
    }

    return data;//return what I filled
}


char **shipArrange(char **array, int row, int col){
   
    int startR=0; //first spot row
    int  startC=0; //first spot column
    char direct; //arrange direction
   int count=0;
    int selectD;
    
    cout<<"The size of ship: Carrier=5 Battleship=4 Submarine=3 Destroyer=2"<<endl;
    cout<<"Choose ship direction: R=right D=down"<<endl;
   //use do while to arrange ships
    
    do{
        array=getData(row,col);
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
          array[startR][i]='1';     
        }  
            break;

        case 'D': for(int i=startR; i<(startR+size);i++){
            array[i][startC]='1';
        }
            break;
        default:
            break;}
    size--;
    }while(size>=2);
    
    //check ship arrange successes, total should 14 one
    for(int i=0; i<row;i++){
        for(int j=0; j<row; j++){
            { if(array[i][j]=='1')count++; //'1' means set up, if count doesn't meet 14 need to be reset
            
             }}      
        }
    
    }while(count<14);
    
    return array;
}

char **Gameguess(char ** array, int row, int col){
    int guessR, guessC;
    guessR=rand()%+10; //random row range 0-9
    guessC=rand()%+10;//random column range 0-9
    if(array[guessR][guessC]=='1') //if guess spot is '1' means hit
    {
        
    array[guessR][guessC]='0';} // then need set this spot to '0'
   
    return array;//return the array after each guess
}

bool resultCheck( char**array,int row, int col){
    
    bool result=0; 
    for(int i=0; i<row; i++){
        for (int j=0; j<col; j++){
            if(array[i][j]=='1') result=1;// return true if still has '1' in game board,
                                          //otherwise return false, means all the ships sank
            
        }
    }
    return result;
}


void addplayer(struct PlayerTotal *PTL){
    
    PTL->playerAry[PTL->size].lose = 0; //initialize lose and win time to 0
    PTL->playerAry[PTL->size].win = 0;  //will be add up after each game
    
 int nsize=81;
 PTL->playerAry[PTL->size].name= new char[nsize];//dynamic char pointer
 cout<<"Please enter a player's name"<<endl;
 cin.getline(PTL->playerAry[PTL->size].name, nsize-1);//name in an array structure

}
void resultPrint(struct PlayerTotal *PTL ){
    for(int i=0; i<(PTL->size); i++){
        cout<<"-------------------------"<<endl;
        cout<<"Name: "<<PTL->playerAry[i].name<<endl;
        cout<<"Win   "<<PTL->playerAry[i].win<< " times"<<endl;
        cout<<"Lose  "<<PTL->playerAry[i].lose<<" times"<<endl;
      
    }
    cout<<"// Above is structure result printing  //\n"<<endl;
}

void  randomAccessFile(fstream &file,PlayerTotal *PTL){

   Playerinfo rAry; //delcare new player array for return
    int count=0; 
    //input and ouput binary file simultaneous
      file.open("randomfile.bin",ios::out|ios::in| ios::binary);
     if(file.is_open()){
         //write the structure array into file, I don't need write the size into file
         while(count<PTL->size){
             file.write(reinterpret_cast<char *>(&PTL->playerAry[count]), sizeof(PTL->playerAry[count]));
             count++;
         }
    }else cout<<"Error"<<endl;

      if(file.is_open()){
          cout<<"\nBelow is reading EVEN player's info by random access binary file: "<<endl;
          //reading even player information by using seekg() move cursor position
          for(int i=1; i<PTL->size; i=i+2){
        cout<<setw(20)<<setfill('*')<<left<<"*"<<endl;
        file.seekg(i * sizeof (Playerinfo), ios::beg);
        file.read(reinterpret_cast<char *> (&rAry), sizeof (Playerinfo));
        cout <<"The "<<i+1<<" Player's name: " <<rAry.name << endl;
        cout <<"The "<<i+1<<" Player win  "<< rAry.win <<" times"<< endl;
        cout <<"The "<<i+1<<" Player lose "<< rAry.lose <<" times"<< endl;
        cout<<setw(20)<<setfill('*')<<left<<"*"<<endl;}

        file.close(); //Close file after writing and reading
    }
   
      
}
void WriteAndRead(fstream &file, PlayerTotal *PTL,PlayerTotal *ATL ){
    PlayerTotal *RTL= new PlayerTotal[PTL->size];
    file.open("copyfile.bin",ios::out|ios::in| ios::binary);
    if(file.is_open()){   
        int count=0;
        //read whole structure into binary file
         while(count<PTL->size){
             file.write(reinterpret_cast<char *>(&PTL->playerAry[count]), sizeof(PTL->playerAry[count]));
             count++;
         }
        file.write(reinterpret_cast<char *>(&PTL->size), sizeof(int));   
    }else cout<<"Error"<<endl;
    if(file.is_open()){
          file.seekg(0,ios::beg);
        int count=0;
         while(count<PTL->size){
             file.read(reinterpret_cast<char *>(&RTL->playerAry[count]), sizeof(PTL->playerAry[count]));
             count++;
         }
         file.read(reinterpret_cast<char *>(&RTL->size), sizeof(int));
         file.close();
          cout<<"// The second Binary file reading and writing success //\n"<<endl;
    } else cout<<"ERROR"<<endl;


    delete []RTL;

}
void     destroy(char **array,int row){
    for(int i=0; i<row; i++){
        delete []array[i];
    }
    delete []array;
}