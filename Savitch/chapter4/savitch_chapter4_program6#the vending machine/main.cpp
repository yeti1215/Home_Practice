

/* 
 * File:   main.cpp
 * Author: Ting
 * Created on April 17, 2022, 9:07 AM
 * project: simulate the vending machine
 */

#include <iostream>

using namespace std;

float dollar(float);
float quater(float);
float dime(float);
float nickel(float);

int main(int argc, char** argv) {
    char coin;
    int dollar, quarter, dime, nickel;
    float sum=0;
    
    do{cout<<"Only accept dollar, quarter, dime, nickel.\n";
        cout<<"Insert the coin: ";
    cin>>coin;
    
    switch (coin){
        case 'dollar': sum += dollar(sum);break;
            
        case 'quarter':sum += quarter(sum); break;
            
        case 'dime': sum += dime(sum); break;
            
        case 'nickel': sum += nickel(sum);break;
        
        default : cout<<"we don't accept it. Please insert the coin:"<<endl; break;
      
    }
     cout<<"Total insert "<<sum<<endl;   
     cout<<"The left amount is "<<3.5-sum<<endl;
    }
    while( sum <=3.50);
    
    if (sum >3.5) {
        float change= sum-3.5;
        cout<<"Here is your change: "<<change<<endl;
    }

    cout<<"Please enjoy your deep-fried twinkie."<<endl;
    
    return 0;
}

float dollar(float amount){
   amount =1;
    return amount;
}

float quarter(float amount){
  amount=0.25;
    return amount;
}

float dime(float amount){
    amount=0.1;
    return amount;
}
float nickel(float amount){
    amount=0.05;
    return amount;
}