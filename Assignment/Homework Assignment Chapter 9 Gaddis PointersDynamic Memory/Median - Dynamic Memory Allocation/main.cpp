#include <iostream>
#include <iomanip>

using namespace std;
int *getData(int &);         //Return the array size and the array

void prntDat(int *,int);    //Print the integer array

float *median(int *,int);  //Fill the median Array with the Float array size, the median, and the integer array data

void prntMed(float *, int);     //Print the median Array

int main(){
	//your code here
	int size;
	int *array=nullptr;
	float *medAry=nullptr;
	array=getData(size);
	prntDat(array,size);
	medAry=median(array,size+2);
	prntMed(medAry,size+2);
	
	delete []array;
	delete []medAry;   //do I also need delete the point array in prototype function?
	
	return 0;
}

int *getData(int & size){
    cin>>size;
    int *data = new int [size];
    
    for(int i=0; i<size; i++){
        cin>>data[i];
    }
    return data;
    
}

void prntDat(int * array,int size){
    for(int i=0; i<size; i++){
        cout<<array[i];
        if(i<size-1)cout<<" ";
        else cout<<endl;
    }
    
}

float *median(int *array,int size){
    float *data= new float [size];
    float sum=0;
    for(int i=0; i<size-2; i++){
        sum +=array[i];
    }
    float med=sum/(size-2);
    
    data[0]=size;
    data[1]=med;
    
    for(int i=2; i<size; i++){
        data[i]=array[i-2];
        
    }
    
    return data;
    
    
}

void prntMed(float * array, int size){
    
    for(int i=0; i<size; i++){
        if(i==0) cout<<array[i];
        
    else cout<<fixed<<setprecision(2)<<showpoint<<array[i];
    if(i<size-1) cout<<" ";    }
    
    
}