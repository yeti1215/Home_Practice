
/* 
 * File:   main.cpp
 * Author: yeti
 * project: display temperature with FUNCTION
 * Created on April 15, 2022, 9:03 AM
 */

#include <iostream>
#include <cmath>
#include <string>

using namespace std;

bool containsDigit(int);

int main(int argc, char** argv) {
    
     int A, B, C, temP, LtemP, StemP;
     
    cout<<"Enter the temperature between 0 to 999 ."<<endl;
    cout<< "If the temperature contains 1, 4, 7 then output the next largest and the next smallest temperature."<<endl;
    
    cin>>temP;
    
    A= temP/100; //The number of hundreds
    B= (temP/10) %10; //the number of tens
    C=temP%10; // the number of ones
    
    if( containsDigit(temP))
       
    {
        if ( A == 1 || A == 4 || A== 7){
            LtemP = (A + 1)*100;
            StemP = (A - 1)*100+99;
                cout << "The next largest number is :" << LtemP << endl;

                cout << "The next smallest number is :" << StemP << endl;
        }
        
        
            else if ( B ==1 || B== 4 || B == 7){
               
                LtemP=A*100+(B+1)*10+0;
                StemP=A*100+(B-1)*10+9;
                 cout<<"The next largest number is :"<<LtemP<<endl;
                 cout<<"The next smallest number is :"<<StemP<<endl;
            }
        
        
        else if( C==1 || C == 4 || C==7){
             LtemP=A*100+B*10+(C+1);
             StemP=A*100+B*10+(C-1);
                 cout<<"The next largest number is :"<<LtemP<<endl;
                 cout<<"The next smallest number is :"<<StemP<<endl;
            
        }
       

    }
    
    else  cout<<"The temperature is "<<temP<<endl;
    
    return 0;
}

bool containsDigit(int temP){
    int A, B, C;
    
    A= temP/100; //The number of hundreds
    B= (temP/10) %10; //the number of tens
    C=temP%10; // the number of ones
    
   if( ( A!= 1 && A!= 4 && A!= 7 )&&( B!= 1 && B != 4 && B!= 7) &&(C!= 1 && C != 4 && C!= 7))
       
       return false;

}