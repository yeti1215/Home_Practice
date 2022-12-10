

/* 
 * File:   player.h
 * Author: Ting Sha
 * Created on November 29, 2022, 1:46 PM
 *  Project2: Battle ship board game player headerfile
 */

#include <iostream>  //I/O Library
#include <string>    //String Library
using namespace std;
#ifndef PLAYER_H
#define PLAYER_H
//player file to get player's data
//Abstract class and polymorphic association
class AbsPName
{

public:
    
    string p_name;  //player name
    //pure virtual member function
    virtual void setName(string)=0;   
};
class AbsPScore
{
public:
    int p_socre=0; //player score
    virtual AbsPScore& operator++()=0;   //pure virtual function
};
//  polymorphism pass PName and PScore two virtual class to Player class
//so we can get the player information
class Player
{//define <<operator as a friend to read private member
   friend ostream&operator<<(ostream &cout, Player player);
private:
    //polymorphism requires pointers or reference
    AbsPName *pname;
    AbsPScore *pscore;
public:
    //default constructor to initialize members
    Player(){
        pname->p_name="";
        pscore->p_socre=0;
    }
    //constructor with argument to pass the value to the member
    Player(AbsPName *name, AbsPScore *score)
    {
       pname=name;
       pscore=score;
    }
    //destructor to release memory
    ~Player(){
        if(pname !=NULL){
            delete pname;
            pname=NULL;
        }
        if(pscore != NULL){
            delete pscore;
            pscore=NULL;
        }
    }            
};
//overload operator <<to cout player information
ostream&operator<<(ostream &cout, Player player)
{
    cout<<"Name= "<<player.pname->p_name<<" Score= "<<player.pscore->p_socre;
    return cout;
}

//encapsulation into a real PName and PScore class
class PName:public AbsPName
{
public:
    //implementation of pure vitual AbsPName function
     void setName(string name){
        p_name=name;
    } 
     string getName(){
         return p_name;
     }
};

//encapsulation into a real PScore class
class PScore:public AbsPScore
{
public:
    //overload ++operator, to increment the player win score
    PScore& operator++(){
        p_socre++;
        return (*this);
    } 
    
};

#endif /* PLAYER_H */

