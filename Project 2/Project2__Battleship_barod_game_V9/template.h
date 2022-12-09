

/* 
 * File:   template.h
 * Author: Ting Yin Sha
 * Created on December 6, 2022, 9:16 PM
 */

#include <iostream>  //I/O Library
#include <string>    //String Library
#include <vector>   //vector STL
#include <iomanip>

#ifndef TEMPLATE_H
#define TEMPLATE_H

//template class
template<class TN, class TS=int>
class Person{
    public:
        TN Name;
        TS Score;
        Person(TN name, TS score){
            this->Name=name;
            this->Score=score;
         
        }
        void showPerson(){
            cout<<"Player name: "<<setw(10) << setfill(' ') << left<<this->Name
                    << "Score = "<<this->Score<<endl;
        }
};

//template function for print
template <class T, class TT>
void showVector(vector<T>v1, vector<TT>v2){
    for(int i=0; i<v1.size(); i++){
        cout<<"The "<<i+1<<" player: "<<setw(10) << setfill(' ') << left<<v1[i]
                <<"Score: "<<v2[i]<<endl;
    }
    cout<<"Total played "<<v2[0]+v2[1]<<" games"<<endl;
    if (v2[0] > v2[1]) {
        cout<<"----------------------"<<endl;
        cout << "* Winner is " << v1[0] <<" *"<< endl;
        cout<<"----------------------"<<endl;
    } 
    else if(v2[0] < v2[1] )
    { cout<<"----------------------"<<endl;
        cout << "* Winner is " << v1[1] <<" *"<< endl;
     cout<<"----------------------"<<endl;}
    else
    {cout<<"----------------------"<<endl;
        cout<<"* Tie *"<<endl;
        cout<<"----------------------"<<endl;
    }
    
}
//template function for push back an element
template<class T1>
void pushback(vector<T1>&v, T1 name){
    //  srand(static_cast<unsigned int> (time(0)));
    //pointer copyV dynamically allocated memory to a new vector, 1 size greater than old vector
    //  vector<int>*copyV= new vector<int>(v.size()+1); this will copy the old size and add new size=5+5+1
    vector<T1>*copyV = new vector<T1>;
    //copy the old vector to new
    //method 1  
    for (int i = 0; i < v.size(); i++) {
        copyV->push_back(v[i]);
    }

    //push back a name or score
   
    copyV->push_back(name);

    //copy new to oldj
    v=*copyV;
    
     // free memory 
    delete copyV;
}

//template function for pop back an element
template<class T2>
void popback(vector<T2>v, T2 score){
      vector<T2>*popV = new vector<T2>;
      *popV=v;
      popV->pop_back();

      //clear all the element
      v.clear();

      //copy new to old
      v=*popV;
  // free memory 
      delete popV;
}

#endif /* TEMPLATE_H */

