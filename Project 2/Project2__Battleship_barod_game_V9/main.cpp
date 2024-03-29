
/* 
 * File:   main.cpp
 * Author: Ting Yin Sha
 * Created on November 27, 2022, 1:30 PM
 * Project2: Battle ship board game Version 9(use 5 ships and display which ship sank)
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
#include <vector>   //vector STL
#include "board.h" //this class for setting up the ships
#include "player.h" //this class for setting players
#include "game.h"  //this class for playing game
#include "template.h"

using namespace std;




int main(int argc, char** argv) {
   srand(static_cast<unsigned short>(time(0)));
   char *name1; //ask for the players name
   char *name2;
   char again;  //ask player play again or not
   vector<char*>playmap; //to store the name in vector
   vector<int>playscore;
   
     cout<<"Welcome to Battle Ship Game"<<endl;
    //initialize the game board and display how it looks
    BaseBoard baseboard;
    baseboard.displayBoard(baseboard.boardAry1);
    
  

    //Add the first player, allocate memory for the PNmame class
    AbsPName *pname1 = new PName;
    //pass the name as an argument
    cout << "Input the first player name:" << endl;
    cin.getline(name1,20); //the name size is 20
    //push back the player name into a vector
    pushback(playmap,name1);
    //set name to class
    pname1->setName(name1);
    //score need to be set after the game started, and update after each game
    AbsPScore *pscore1 = new PScore;

    //Add the second player
    AbsPName *pname2 = new PName;
    //pass the name as an argument
    cout << "Input the second player name:" << endl;
    cin.getline(name2, 20); //the name size is 20
    //push back the second player name
    pushback(playmap, name2);
    pname2->setName(name2);
    //score need to be set after the game started, and update after each game
    AbsPScore *pscore2 = new PScore;
    
    //use a do while to continue playing
    do{
        //define a Game class
        Game game;
        //call the playgame function from Game class to start play
       
        game.playgame();
        //result check and score++
        if (game.resultCheck1() && !game.resultCheck2()) {
            cout << "--------------------" << endl;
            cout << "Winner: " << pname2->p_name << endl;
            //increment score operator for the winner second player
            pscore2->operator++();
            cout << "LOSER:  " << pname1->p_name << endl;
            cout << "--------------------" << endl;
        }
        else {
            cout << "--------------------" << endl;
            cout << "Winner: " << pname1->p_name << endl;
            //increment score operator for the winner first player
            pscore1->operator++();
            cout << "LOSER:  " << pname2->p_name << endl;
            cout << "--------------------" << endl;
        }

        cout << "Play again? Y/N" << endl;
        cin>>again;
        
    } while (toupper(again) == 'Y');
    
    //push back the score
      pushback(playscore,pscore1->p_socre);
      pushback(playscore,pscore2->p_socre);


    //use template class print
    cout << "Template class show first players data " << endl;
    Person<string>person1(name1, pscore1->p_socre); 

    person1.showPerson();


    cout << "Template class show second players data " << endl;
    Person<string>person2(name2, pscore2->p_socre); 
    person2.showPerson();

        //release the memory in class,
     
    //polymorphism player, and use <<overload operator print out player's data
    cout<<"\nDisplay with polymorphism class"<<endl;
    Player* player1=new Player(pname1,pscore1);
    cout<<*player1<<endl;
  
    Player* player2=new Player(pname2,pscore2);
    cout<<*player2<<endl;
    
    cout<<"\nDisplay with template vector function:"<<endl;
    showVector(playmap, playscore);
    cout<<endl;
    

   
   
    
        return 0;
}
