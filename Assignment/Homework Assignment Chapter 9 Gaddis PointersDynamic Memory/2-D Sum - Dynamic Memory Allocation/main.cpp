#include <iostream>

using namespace std;
int **getData(int &,int &);        //Return the 2-D array and its size.

void prntDat(const int* const *,int,int);//Print the 2-D Array

void destroy(int **,int,int);       //Deallocate memory

int sum(const int * const *, int,int);    //Return the Sum

int main(){
	//your code here
	int rows, cols;
	int **array=nullptr;
	int total;

   array=getData(rows,cols);
	
	prntDat(array, rows, cols);
	
  total=sum(array,  rows, cols);
  cout<<total;
    
   // cout<<sum(array,  rows, cols);   why not work withou previous total value??????????????
   
  destroy(array,rows, cols); 
  
	
	return 0;
}

int **getData(int & rows,int & cols){
    
    
    cin>>rows>>cols;
    int **data= new int* [rows];
   
    for(int i=0; i<rows;i++){
        data[i]=new int[cols];
    }
    
    for(int i=0; i<rows; i++){
        for(int j=0; j<cols;j++)
    {
        cin>>data[i][j];

    }
  
    }
    
    
    return data;
    }

void prntDat(const int* const * array,int rows,int cols){
    
     for(int i=0; i<rows; i++){
        
        for(int j=0; j<cols;j++)
    {
         
        cout<<array[i][j];
        if(j<(cols-1)) cout<<" ";
    }
    cout<<endl;
    }
}

void destroy(int **array,int rows,int cols){
    for(int i=0; i<rows;i++){
        delete [] array[i]; //free(array[i])                       ??? where to use?
    }
    delete []array;  //free(array)
    
}

int sum(const int * const * array, int rows,int cols){
    
    int sum=0;
    for(int i=0; i<rows; i++){
        for(int j=0; j<cols; j++){
            sum +=array[i][j];
        }
    }
  
    return sum;
}