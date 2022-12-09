#include <iostream>
int **getData(int &,int &);//Get the Matrix Data

void printDat(const int * const *,int,int);//Print the Matrix

int **augment(const int * const *,int,int);//Augment the original array

void destroy(int **,int);//Destroy the Matrix, i.e., reallocate memory

using namespace std;

int main(){
	//your code here
	int row,col;
	int **array;
	int **augAry;
	
	array=getData(row,col);
	printDat(array, row, col);
	cout<<endl;
	
	augAry=augment(array,row+1,col+1);
    printDat(augAry, row+1, col+1);

    destroy(array, row);
    destroy(augAry, row);
	
	return 0;
}

int **getData(int & row,int & col){
    
  cin>>row>>col;
  
    int ** data= new int *[row];
     
    
    for(int i=0; i<row; i++){
     data[i]= new int [col];   
    }
    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            cin>>data[i][j];
        }
    }
    
    return data;
}

void printDat(const int * const * array,int row,int col){
    
    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            cout<<array[i][j];
            if(j<col-1)cout<<" ";
        }
       if(i<row-1) cout<<endl;
    }
    
}

int **augment(const int * const * array,int row,int col){
   
  
    int **data= new int*[row];
    
    for(int i=0; i<row; i++){
        data[i]=new int [col];
    }

    
    
    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            
            if(i==0 ||j==0) data[i][j]=0;
        
            else {data[i][j]=array[i-1][j-1]; }

        }
    }
        
        return data;
    
}

void destroy(int ** array,int row){
    for(int i=0; i<row; i++){
        delete []array[i];
    }
    delete []array;
    
}