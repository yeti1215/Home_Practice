

/* 
 * File:   main.cpp
 * Author: Ting
 * Created on May 15, 2022, 4:35 PM
 * Purpose: LO SHU magic square
 */

#include <iostream>
#include <vector>

using namespace std;
const int COLS=3;

bool test(int [][COLS],int);
void loshu(int[][COLS], int);
int main(int argc, char** argv) {
    const int ROW=3;
    int square[ROW][COLS];
    
    loshu(square , ROW);
 

  
  if(test( square, ROW)) cout<<"This is a LOSHU magic square."<<endl;
  else cout<<"NOT a magic square."<<endl;
    return 0;
}
void loshu(int square[][COLS],int ROW){
    
    for(int i=0;i<ROW;i++){
        for(int j=0; j<COLS; j++){
            cin>>square[i][j];
        }
    }
       for(int i=0; i<ROW; i++){
        for(int j=0; j<COLS; j++){
            cout<<square[i][j]<<" ";
        }cout<<endl;
    }
}
bool test(int square[][COLS],int ROW){
    vector<int>sum; //store the sum
    //calculate each row sum
    for(int i=0; i<ROW; i++){
        int total=0;
       for(int j=0; j<COLS; j++){
                total +=square[i][j];
            }sum.push_back(total);
           
    }
    //calculate each column sum       
 
    for(int i=0; i<COLS; i++){
        int total=0;
        for(int j=0; j<ROW; j++){
            total +=square[j][i];
        } sum.push_back(total);
    }
  //calculate each diagonal sum  
      int totalD1=0,
          totalD2=0;
    for(int i=0; i<ROW; i++){
       
       for(int j=0; j<COLS; j++){
          
               if(i==j) totalD1 +=square[i][j];
               if(i+j==2) totalD2 +=square[i][j];
            }
    }sum.push_back(totalD1);
    sum.push_back(totalD2);
    
    //            for(int val:sum)cout<<<<val<<",";
      //    cout<<"length "<<sum.size()<<endl;
    for(int count=0; count<sum.size()-1;count++){
           if( sum[count]!=sum[count+1])
            return false;break;  
    }  return true;
    
    
}