#include <iostream>

int *getData(int &);//Read the array

int *augment(const int *,int);//Augment and copy the original array

void prntAry(const int *,int);//Print the array

using namespace std;

int main(){
	//your code here
	
	int *array=nullptr;
	int *augAry=nullptr;
	int size;
	
	array=getData(size);
	 prntAry(array,size);
	 cout<<endl;
	 augAry=augment(array,size);
	
	prntAry(augAry,size+1);
	
	delete [] array;
	delete []augAry;
	
	return 0;
}

int *getData(int &size){
    int *data= new int[size];
    cin>>size;
    
    for(int i=0; i<size; i++){
        cin>>data[i];
    }
    return data;
    
}

int *augment(const int * array,int size){
    int *data=new int[size];
     data[0]=0;
    for(int i=1; i<size+1; i++){
       
        data[i]=array[i-1];
    }
    
    
    
    return data;
    
}

void prntAry(const int * array,int size){
    for(int i=0; i<size; i++){
        cout<<array[i];
        if(i<size-1) cout<<" ";
    }
    
}