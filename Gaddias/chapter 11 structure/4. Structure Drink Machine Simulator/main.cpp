#include <iostream>
#include<iomanip>
#include <cstring>

using namespace std;
struct Drink{
     string Name; float Cost; int Number;
};
void printDrink(struct Drink drinkAry[5]){
    for(int i=0; i<5; i++){
        cout<<left<<setw(11)<<drinkAry[i].Name<<drinkAry[i].Cost<<"  "<<drinkAry[i].Number<<endl;
    }
}

int main(){
 //   string input;
     float amount;
    
    struct	Drink drinkAry[5]={
	   {"Cola",75, 20},
       {"Root Beer",75, 20},
       {"Lemon-Lime",75, 20},
       {"Grape Soda",80, 20},
       {"Cream Soda",80, 20}
	};

char input[20];
int total=0;

 	do{
	   
      printDrink(drinkAry);
      cout<<"Quit"<<endl;
	   
	  cin.getline(input,20);

	
   if(input[0] != 'Q') { 
       cin>>amount;

	   if(input==drinkAry[0].Name)        {amount=amount-75; drinkAry[0].Number--; total +=75;} 
	   else if (input==drinkAry[1].Name)  {amount=amount-75;drinkAry[1].Number--;total +=75;}  //died loop with the name Root Beer
	   else if (input==drinkAry[2].Name)  {amount=amount-75;drinkAry[2].Number--;total +=75;} 
	   else if (input==drinkAry[3].Name)  {amount=amount-80;drinkAry[3].Number--;total +=80;} 
	   else if (input==drinkAry[4].Name)  {amount=amount-80;drinkAry[4].Number--;total +=80;} 
	  
	   cout<<amount<<endl;
 	   cin.ignore();
       
   }

 	   else cout<<total<<endl;
	   
 	}while(input[0]!='Q');
	
	return 0;
}