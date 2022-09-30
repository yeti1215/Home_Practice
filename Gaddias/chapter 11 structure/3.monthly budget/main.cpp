/* 
 * File:   
 * Author: Ting Sha
 * Created on september 28th, 2022; 12:55PM
 * Purpose: monthly budget  
 */

//System Libraries
#include <iostream>
# include <iomanip>
using namespace std;

//User Libraries

//Global Constants - No Global Variables
//Only Universal Constants, Math, Physics, Conversions, Higher Dimensions

struct Budget{
    float house;
    float utility;
    float houseE;
    float transp;
    float food;
    float medical;
    float insur;
    float entertm;
    float cloth;
    float miscls;
    // float budgetAray[10]; //how to pass a array value through Prototypes function
    
};
//Function Prototypes
void spentCheck(struct Budget *spent){
    cout<<"Enter housing cost for the month:$"<<endl;
    cin>>spent->house;
    
    cout<<"Enter utilities cost for the month:$"<<endl;
     cin>>spent->utility;
    
    cout<<"Enter household expenses cost for the month:$"<<endl;
    cin>>spent->houseE;
    
    cout<<"Enter transportation cost for the month:$"<<endl;
     cin>>spent->transp;
     
    cout<<"Enter food cost for the month:$"<<endl;
     cin>>spent->food;
     
    cout<<"Enter medical cost for the month:$"<<endl;
    cin>>spent->medical;
    
    cout<<"Enter insurance cost for the month:$"<<endl;
    cin>>spent->insur;
    cout<<"Enter entertainment cost for the month:$"<<endl;
    cin>>spent->entertm;
    cout<<"Enter clothing cost for the month:$"<<endl;
    cin>>spent->cloth;
    cout<<"Enter miscellaneous cost for the month:$"<<endl;
    cin>>spent->miscls;
   
}
string compareBudget(float a, float b,string  &r, float & sum){
  
         if(a>b) r="Under";
    else if(a==b) r="Even";
     else if(a<b) r="Over";
     
     sum = sum+(a-b);
return r;
    
}
//Execution Begins Here
int main(int argc, char** argv) {
    //Set Random Number seed
    
    //Declare Variable Data Types and Constants
    float remain;
    string result;
    float sum=0;
    struct Budget spent;
    struct Budget monthly={
     500.00, 
     150.00,
     65.00,
     50.00,
     250.00,
     30.00,
     100.00,
     150.00,
     75.00,
     50.00 };
    
    string strAry[]={
        "Housing",
"Utilities","Household",
"Transportation",
"Food",
"Medical",
"Insurance",
"Entertainment",
"Clothing"
"Miscellaneous"
    };
    
    //input the spend value pass by prototype Function
    spentCheck(&spent);
    // cout<<spent.[0]<<endl;
  
    //compare the spent with the Budget
  
    compareBudget(monthly.house, spent.house, result,sum);
    cout<<  "Housing "<<result<<endl;

   compareBudget(monthly.utility, spent.utility, result, sum);
    cout<<  "Utilities "<<result<<endl;
    
    compareBudget(monthly.houseE, spent.houseE, result, sum);
    cout<<  "Household Expenses "<<result<<endl;
    
    compareBudget(monthly.transp, spent.transp, result, sum);
    cout<<  "Transportation "<<result<<endl;
    
     compareBudget(monthly.food, spent.food, result, sum);
    cout<<  "Food "<<result<<endl;
    
    compareBudget(monthly.medical, spent.medical, result, sum);
    cout<<  "Medical "<<result<<endl;
    
     compareBudget(monthly.insur, spent.insur, result, sum);
    cout<<  "Insurance "<<result<<endl;
    
    compareBudget(monthly.entertm, spent.entertm, result, sum);
    cout<<  "Entertainment "<<result<<endl;
    
    compareBudget(monthly.cloth, spent.cloth, result, sum);
    cout<<  "Clothing "<<result<<endl;
    
     
    compareBudget(monthly.miscls, spent.miscls, result, sum);
    cout<<  "Miscellaneous "<<result<<endl;
    cout<<fixed<<setprecision(2)<<showpoint;
    
    if (sum>0) cout<<"You were $"<<sum<<" under budget";
    
   else if (sum<0) cout<<"You were $"<<sum*(-1)<<" over budget";
    
    
   if (sum==0) cout<<"You were even under budget";

    //Exit stage right!
    return 0;
}