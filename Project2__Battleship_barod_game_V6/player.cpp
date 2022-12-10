
/* 
 * File:   player.cpp
 * Author: Ting Sha
 * Created on November 29, 2022, 1:46 PM
 *  Project2: Battle ship board game player cpp
 */

#include <iostream>  //I/O Library
#include <string>    //String Library
#include <iomanip>
using namespace std;
#include "player.h"

Player::Player()
{
    pname->p_name="";
        pscore->p_socre=0;
}

Player::Player(AbsPName* name, AbsPScore* score)
{
  pname=name;
       pscore=score;  
}
//copy constructor ??????????
Player::Player(const Player &obj){
    pname=new PName;
    pscore=new PScore;
    pname=obj.pname;
    pscore=obj.pscore;
}
//copy operator==
Player& Player::operator=(const Player &obj){
    if(this==&obj) return *this;
    delete pname;
    delete pscore;
    pname=new PName;
    pscore=new PScore;
    pname->p_name=obj.pname->p_name;
    pscore->p_socre=obj.pscore->p_socre;
}
//overload operator <<to cout player information
ostream&operator<<(ostream &cout, Player player) 
{
    cout << "Name= " << setw(10) << setfill(' ') << left << player.pname->p_name

            << "Score= " << player.pscore->p_socre;
    return cout;
}

Player::~Player()
{
    // cout<<"player constructor"<<endl;
        if(pname !=NULL){
            delete pname;
            pname=NULL;
        }
        if(pscore != NULL){
            delete pscore;
            pscore=NULL;
        } 
}

