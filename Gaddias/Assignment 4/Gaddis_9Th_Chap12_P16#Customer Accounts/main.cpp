
/* 
 * File:   main.cpp
 * Author: Ting Sha
 * Created on October 14, 2022, 8:56 PM
 * Project: Customer Accounts
 */

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

const int MAX=100;  //accept 100 customers data
struct Data{
    string name;
    string address;
    string teleph;
    int    balance;
    string paydate;
};

struct Datatotal{
    struct Data dataAry[MAX];
    int size=0;
};
void showmenu(){
    cout<<"----------------------------"<<endl;
    cout<<"1.Add a new customer account"<<endl;
    cout<<"2.Search customer and display"<<endl;
    cout<<"3.Delete a customer"<<endl;
    cout<<"4.Modify a customer account"<<endl;
    cout<<"5.Display entire file and Exist"<<endl;
    cout<<"6.Quit"<<endl;
    cout<<"----------------------------"<<endl;
}
void addCustomer(Datatotal *dtl){
    if(dtl->size==MAX){
        cout<<"The system is full! "<<endl;
        return;
    }
    else { //add new customer
        string newname;
        cout<<"Enter a customer name:"<<endl;
        cin>>newname;
        dtl->dataAry[dtl->size].name=newname;
        cin.ignore();
        string newaddr;
        cout<<"Enter address"<<endl;
        getline(cin,newaddr);
        dtl->dataAry[dtl->size].address=newaddr;
        cout<<"Enter telephone"<<endl;
        string newtel;
        getline(cin,newtel);
        dtl->dataAry[dtl->size].teleph=newtel;
        cout<<"Enter a account balance"<<endl;
        int newbal;
        cin>>newbal;
        dtl->dataAry[dtl->size].balance=newbal;
        cin.ignore();
        cout<<"Enter last payment date, M/D/Y"<<endl;
        string newdate;
        getline(cin,newdate);
        dtl->dataAry[dtl->size].paydate=newdate;
            
    }
    
   system("clear"); 
}
int isExist(Datatotal *dtl, string sname){
    
    for(int i=0; i<dtl->size;i++){
        if(dtl->dataAry[dtl->size].name==sname) 
            cout<<"Found at "<<i<<endl; return i; //return the index i
    }
   return -1; 
}
void searchData(Datatotal *dtl){
    if(dtl->size<=0){
        cout<<"The system is empty."<<endl;
        return;
    }
    else {
        cout<<"Enter a name you need search\n ";
        string sname;
        cin>>sname;
        int result=isExist(dtl,sname);
        if(result!=-1){
            cout<<"Name:    "<<dtl->dataAry[result].name<<endl;
            cout<<"Address: "<<dtl->dataAry[result].address<<endl;
            cout<<"Tel:     "<<dtl->dataAry[result].teleph<<endl;
            cout<<"Balance: "<<dtl->dataAry[result].balance<<endl;
            cout<<"Pay Date:"<<dtl->dataAry[result].paydate<<endl;
        }
        
    }
}
void deleteData(Datatotal *dtl){
     if(dtl->size<=0){
        cout<<"The system is empty."<<endl;
        return;
    }
    cout<<"Enter a customer name you need delete"<<endl;
    string dname;
   // getline(cin,dname); //why not working
    cin>>dname;
    int result=isExist(dtl,dname);
    if(result != -1){
        //delete a customer, need move all the behind customer forward 1
        for(int i=result; i<dtl->size;i++){
            dtl->dataAry[i]=dtl->dataAry[i+1];
        }
        dtl->size--;
    }
    else cout<<"Not Found"<<endl;
    
}
void modifyData(Datatotal *dtl){
    if(dtl->size<=0){
        cout<<"The system is empty."<<endl;
        return;
    }
    cout<<"Enter a customer name you need modify"<<endl;
    string mname;
    //getline(cin,mname);
    cin>>mname;
    int result=isExist(dtl,mname);
    if(result!=-1){
        string newname;
        cout<<"Enter a customer name:"<<endl;
       // getline(cin,newname);
        cin>>newname;
        dtl->dataAry[result].name=newname;
        cin.ignore();
        string newaddr;
        cout<<"Enter address"<<endl;
        getline(cin,newaddr);
        dtl->dataAry[result].address=newaddr;
        cout<<"Enter telephone"<<endl;
        string newtel;
        getline(cin,newtel);
        dtl->dataAry[result].teleph=newtel;
        cout<<"Enter a account balance"<<endl;
        int newbal;
        cin>>newbal;
        dtl->dataAry[result].balance=newbal;
        cin.ignore();
        cout<<"Enter last payment date, M/D/Y"<<endl;
        string newdate;
        getline(cin,newdate);
        dtl->dataAry[result].paydate=newdate;
    }
    
}
void writeAndDisplay(fstream &file,Datatotal *dtl, Datatotal *readata){

    if(file.fail()){cout<<"ERROR"<<endl;}
    else {
        file.write(reinterpret_cast<char *>(&dtl), (dtl->size) *sizeof(Data));
        cout<<"Wrote into file successes"<<endl;
        file.close();
        
    
    file.open("accountData.bin", ios::in|ios::binary);
     file.seekg(0,ios::beg);
    file.read(reinterpret_cast<char *>(&readata),(dtl->size) *sizeof(Data));
      file.close();
    cout<<"Read from file successes"<<endl;
    }
//print file
    for(int i=0; i<readata->size; i++){
          cout<<"Name:    "<<readata->dataAry[i].name<<endl;
            cout<<"Address: "<<readata->dataAry[i].address<<endl;
            cout<<"Tel:     "<<readata->dataAry[i].teleph<<endl;
            cout<<"Balance: "<<readata->dataAry[i].balance<<endl;
            cout<<"Pay Date:"<<readata->dataAry[i].paydate<<endl;
    }
   
    
}

int main(int argc, char** argv) {
    Datatotal dtl;
    Datatotal readata;
    int select=0;
    fstream file;
   
    
    while(true){
        showmenu();
        cin>>select;
        switch(select){
            case 1://add new customer
                addCustomer(&dtl);dtl.size++;
                break;
            case 2:
                searchData(&dtl);
                break;
            case 3:
                deleteData(&dtl);
                break;
            case 4:
                modifyData(&dtl);
                break;
            case 5:
//                cout<<"Before file.open"<<endl;
                file.open("accountData.bin", ios::out|ios::binary|ios::trunc);
              
                writeAndDisplay(file,&dtl,&readata);
                return 0;
                break;
            case 6:
                cout<<"Thank you!"<<endl;
                return 0;
                break;
            default:
                break;
        }
    }
    
    
    

    return 0;
}

