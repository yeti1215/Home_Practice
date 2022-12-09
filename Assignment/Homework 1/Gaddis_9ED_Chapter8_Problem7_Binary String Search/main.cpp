

/* 
 * File:   main.cpp
 * Author: Ting Yin Sha
 * Created on September 3, 2022, 10:07 PM
 * Project: Binary string search
 */

#include <iostream>
#include <iomanip>
#include <vector>
#include <cstring>
using namespace std;

void selectSort(string [], int );
int binarySearch(string [], int , int , string );
int main(int argc, char** argv) {
    // Declare variables here
    const int NUM_NAMES =20;
    string names[NUM_NAMES]={"Collins", "Smith","Allen","Griffin",
                              "Stamey","Rose", "Taylor", "Johnson",
                            "Allison","Looney", "Wolfe", "James","Weaver"};
    int len=sizeof(names)/sizeof(names[0]);
    selectSort(names, len);
    for(int i=0; i<len; i++){
        cout<<names[i]<<endl;
    }
    
    string name;
    cout<<"Enter the name to search\n";
    cin>>name;
    
    int index=binarySearch(names, 0, len-1, name);
    if(index==-1){
        cout<<name<<" is not present in the array."<<endl;  
    }
    else {
                cout<<name<<" is present at the index "<<index<<" in the array."<<endl;  

    }
    
    return 0;
}
void selectSort(string name[], int size){
    int minIndex;
    string minValue;
    for(int start=0; start<size-1; start++){
        minIndex=start;
        minValue=name[start];
        for(int index =start+1; index<size; index++){
            if(name[index]<minValue){
                minValue =name[index];
                minIndex=index;
            }
    }
        swap(name[minIndex], name[start]);
    }
}
int binarySearch(string names[], int first, int last, string str){
    if(first<last){
        int mid= (first+last)/2;
        if(names[mid]==str) return mid;
        if(names[mid]>str) return binarySearch(names, first, mid-1, str);
        if(names[mid]<str) return binarySearch(names, mid+1, last, str);
    }
    return -1;
}