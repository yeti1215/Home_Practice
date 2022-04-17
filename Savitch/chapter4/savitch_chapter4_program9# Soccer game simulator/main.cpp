

/* 
 * File: main.cpp
 * Author: yeti
 * Created on April 14, 2022, 8:11 PM
 * project: Soccer game simulator
 */

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int event1p(int); // team 1 event score
int event2p(int);  //team 2 event score
int penalty1(int); //team 1 penalty 
int penalty2(int); //team 2 penalty

int main(int argc, char** argv) {
    
  
    
    int number, team1=0, team2=0, randN1, randN2;
    number= rand()%15+1;
    cout<<"The number of event is "<<number<<endl;
    for(int i=1; i <=number;i++){
        int event;
          srand(time(NULL)); //??? why didn't  generate random number, and says weak random generator???
        event=rand()%6+1;
        cout<<"event "<<event<<endl;
       if( event==1 || event==3) {
           int event1=event;
           team1 +=event1p(event1);
       }
        if( event==2 || event==4) {
            int event2=event;
           team2 +=event2p(event2);
       }
        if (event==5 ){
            srand(time(NULL));
        randN1=rand()%4+1;
        cout<<"RandN1"<<randN1<<endl;
           team1+= penalty1(randN1);
        }
        if (event == 6){
             srand(time(NULL));
      randN2=rand()%4+1;
        cout<<"RandN1"<<randN2<<endl;
            team2 +=penalty2(randN2);
        }
    
    }
    
    
    
    cout<<"Team 1 total scored "<<team1<<endl;
    
    cout<<"Team 2 total scored "<<team2<<endl;
    return 0;
}

int event1p(int event1){
    int score1=0, score2=0;
    switch(event1){
        case 1: cout<<"Team 1 scored a goal."<<endl;
        score1 +=1; break;
        case 3: cout<<"Team 1 committed an offside."<<endl; break;
     
    }
    return score1;
}

int event2p(int event2){
    int score1=0, score2=0;
    switch(event2){
        
        case 2: cout<<"Team 2 scored a goal."<<endl;
        score2 +=1; break;
       
        case 4: cout<<"Team 2 committed an offside."<<endl; break;
     
    }
    return score2;
}
int penalty1(int randN){
       
    int score1p=0;
    switch(randN){
        case 1: cout<<"Team 1 scored a goal."<<endl;
        score1p +=1; break;
        case 2: cout<<"Team 1 miss the penalty."<<endl;break;
        case 3: cout<<"Team 1 get a yellow card."<<endl; break;
        case 4: cout<<"Team 1 get a red card."<<endl; break;
        
    }
    return score1p;
 }

int penalty2(int randN){
     srand(time(NULL));
       randN=rand()%4+1;
    
    int score2p=0;
    switch(randN){
        case 1: cout<<"Team 2 scored a goal."<<endl;
        score2p +=1; break;
        case 2: cout<<"Team 2 miss the penalty."<<endl;break;
        case 3: cout<<"Team 2 get a yellow card."<<endl; break;
        case 4: cout<<"Team 2 get a red card."<<endl; break;
        
    }
    return score2p;
 }