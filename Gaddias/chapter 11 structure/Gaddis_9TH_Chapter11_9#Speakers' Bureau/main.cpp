

/* 
 * File:   main.cpp
 * Author: Ting Sha
 * Created on September 29, 2022, 9:54 PM
 * Project: Speakers' Bureau
 */

#include <iostream>
#include <string>
#include <cstring>
#include <stdlib.h>
using namespace std;

const int MAX=10;
struct Speaker{
    string s_name;
    string s_tele;
    string s_topic;
    int    s_fee;
};
struct SpeakerTotal{
    struct Speaker speakAry[MAX];
    int size=0;
};
void showmenu(){
    cout<<"***********************"<<endl;
    cout<<"1. Add new speaker"<<endl;
    cout<<"2. Change the speaker's data"<<endl;
    cout<<"3. Delete speaker"<<endl;
    cout<<"4. Search topic"<<endl;
    cout<<"5. Print all the dates"<<endl;
    cout<<"6. Clear all data!"<<endl;
    cout<<"0. Quit program"<<endl;
    cout<<"***********************"<<endl;
}
void addSpeaker(SpeakerTotal *stl){
    //check if it is maximum size of speaker
    if(stl->size==MAX){
        cout<<"The system is full!"<<endl;
        return;
    }
    else {//add a speaker's information
     //   cin.ignore();
        string name;
        cout<<"Please enter name:"<<endl;
        cin>>name;
        stl->speakAry[stl->size].s_name=name;
        // input telephone and save to structure
        cout<<"Please enter telephone number:"<<endl;
        cin>>(stl->speakAry[stl->size].s_tele);
        cin.ignore();
        // input topic and save to structure
        string topic;
        cout<<"Please enter topic:"<<endl;
        getline(cin,topic);
        stl->speakAry[stl->size].s_topic=topic;
        // input positive fee and save to structure
        int fee=0;
        cout<<"Please enter speaker's fee:"<<endl;
        while (true){
        cin>>fee;
       
        if(fee>=0)
        { stl->speakAry[stl->size].s_fee=fee;
        break;}
        cout<<"warning:Positive number only!"<<endl;
        }  cin.ignore();
        
    }
    
    system ("clear"); //clear the screen
    
}
void printSpeaker(struct SpeakerTotal *stl){
    if(stl->size ==0)cout<<"There is no speaker."<<endl;
    else
    for(int i=0; i<stl->size;i++){
        cout<<"Name:"<<stl->speakAry[i].s_name<<"\t"
        "Telephone:"<<stl->speakAry[i].s_tele<<"\t"
        "Topic:"<<stl->speakAry[i].s_topic<<"\t"
        "Fee"<<stl->speakAry[i].s_fee<<endl;
    }
    
}

int isExist(struct SpeakerTotal *stl, string name){
    for(int i=0; i<stl->size; i++){
        if(stl->speakAry[i].s_name==name) {
            return i; // if find the speaker return  the index
        }
    }
    return -1; //if not find return -1;
}
void deleteSpeaker(SpeakerTotal *stl){
    cout<<"Enter the name of the speaker need to be deleted"<<endl;
    string name;
    cin>>name;
    
    int result=isExist(stl, name);
    if(result!=-1){
        //delete a speaker, need move all the behind speaker forward 1
        for(int i=result; i<stl->size; i++){
            stl->speakAry[i]=stl->speakAry[i+1];
    }
        stl->size--;
    }
    else cout<<"Not found!"<<endl;   
}
void checkTopic(SpeakerTotal *stl){
   
    if(stl->size<=0) {cout<<"No speaker information input yet"<<endl; return;}
    else
    cout<<"Enter topic that you need:"<<endl;
    string topic;
    cin>>topic;
    for(int i=0; i<stl->size; i++){
        string found=(stl->speakAry[i].s_topic);
        if(found.find(topic)!=string::npos)
        { cout<<"Name:"<<stl->speakAry[i].s_name<<"\t"
        "Telephone:"<<stl->speakAry[i].s_tele<<"\t"
        "Topic:"<<stl->speakAry[i].s_topic<<"\t"
        "Fee"<<stl->speakAry[i].s_fee<<endl; 
       }
     
        else  if(found.find(topic)==string::npos && i==(stl->size-1))
         cout<<"Topic not found"<<endl;
    }
}
//modify speaker
void modifySpeaker(SpeakerTotal *stl){
    cout<<"Enter the speaker you need to modify:"<<endl;
    string name;
    cin>>name;
   int result= isExist(stl, name);
   if(result!=-1)//speaker found
   {
       string name;//modify speaker's name
       cout<<"Enter new name: "<<endl;
       cin>>name;
       stl->speakAry[result].s_name=name;
       //modify telephone
       string teleph;
       cout<<"Enter new telephone number:"<<endl;
       cin>>teleph;
       stl->speakAry[result].s_tele=teleph;
       cin.ignore();
       //modify topic
       string mtopic;
       cout<<"Enter new topic"<<endl;
       getline(cin, mtopic);
       stl->speakAry[result].s_topic=mtopic;
       //modify fee
       int nfee;
       cout<<"Enter new fee:"<<endl;
       cin>>nfee;
       stl->speakAry[result].s_fee=nfee;
       
       
   }
   else {
       cout<<"Speaker not found!"<<endl;
   }
}
void clearData(SpeakerTotal *stl){
    cout<<"Do you need clear all data?? Y/N"<<endl;
    char ch;
    cin>>ch;
    
    if(toupper(ch) =='Y') // return uppercase
    {
    stl->size=0; // set the size to 0, clear all data at one time
    cout<<"Data is Cleared"<<endl;}
    
}

int main(int argc, char** argv) {
// menu-drive
// 1. add speaker; 2 delete speaker; 3.change speaker's data; 4, topic search
   // int size=10;
  Speaker speaker;
  SpeakerTotal stl;
    int select=0;
  
  while(true){
       showmenu();  
      
      cin>>select;
      switch(select){
          case 1: //1. Add new speaker
              addSpeaker(&stl); stl.size++;
              break;
          case 2: //modify the speaker's data
             modifySpeaker(&stl);
              break;
          case 3: //Delete speaker
              //check speaker by name
             deleteSpeaker(&stl);
              
              break;
          case 4: //Search topic
            checkTopic(&stl);
              
              break;
          case 5: //Print all the dates
              printSpeaker(&stl);
              break;
          case 6: //clear all data
              clearData(&stl);
              break;
          case 0: //quit program
              cout<<"Thank you!"<<endl;
              return 0;
              break;
              
          default:
              break;
      }
  }
  
  
    return 0;
}

