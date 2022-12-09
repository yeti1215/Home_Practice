#include <iostream>

using namespace std;

int *getData(int &);            

int *sumAry(const int *,int);

void prntAry(const int *,int);

int main(){
	//your code here

	int *array=nullptr;
	int *sum=nullptr;
	int size;

//dynamically allocate an array large enough to hold
    array=getData(size);
 
	prntAry(array,size);
    cout<<endl;
	
   sum=sumAry(array,size);
   prntAry(sum,size);
   
	delete [] array;
    delete [] sum;
	array= nullptr;
	sum=nullptr;
	return 0;
}

int *getData(int & size){
    
    int *number=new int[size]; //since need return pointer,need  declare the variable as a pointer in prototype
                              //function , otherwise need pass by argument.
    cin>>size;
    
    for(int i=0; i<size; i++){
        cin>>number[i];
    }
    
    return number;
}  

int *sumAry(const int * number,int size){
    int *sum=new int[size];
      
    
    for(int i=0; i<size; i++){
        if(i==0) sum[0]=number[0];
        else
        sum[i] =sum[i-1]+number[i];
        
 
    }
    
    
    
    return sum;
    
}

void prntAry(const int *array,int size){
    
     for(int i=0; i<size; i++){
        cout<<array[i];
        if(i<size-1) cout<<" ";
    }
}