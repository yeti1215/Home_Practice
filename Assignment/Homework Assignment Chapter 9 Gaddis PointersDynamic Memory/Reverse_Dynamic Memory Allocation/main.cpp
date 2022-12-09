#include <iostream>

using namespace std;
int *getData(int &n);               //Fill the array

int *sort( int *,int) ;        //Sort smallest to largest

int *reverse( int *,int);  //Sort in reverse order

void prntDat(const int *,int); //Print the array

int main(){
	//your code here
	int size;
	int *data=nullptr;
	
	
	 data=getData(size);
	 sort(data,size);
	 prntDat(data, size);
	 
	 cout<<endl;
	 
	 data=reverse(data,size);
	 prntDat(data, size);

     delete []data;
	return 0;
}


int *getData(int &size){
    cin>>size;
    int *data= new int [size];
    for(int i=0; i<size; i++){
        cin>>data[i];
    }
    return data;
    
}
int *sort(int *array,int n) {
  
    for(int i=0; i<n-1; i++){
        for(int j=i+1; j<n; j++){
            if(array[i]>array[j]) 
            swap(array[i], array[j]);
           
        }
    }
    
    
    return array;
    
}

int *reverse(int * array,int size){
       
    
     for(int i=0; i<size/2; i++){
        //  int temp;
        //      temp=array[i]; array[i]=array[n-i-1]; array[n-i-1]=temp;
            
            swap(array[i],array[size-i-1]);
      }
    
    return array;
    
}

void prntDat(const int * array,int size){
    for(int i=0; i<size; i++){
        cout<<array[i];
        if(i<size-1)cout<<" ";
    }
    
}