#include "Senior Seller.hpp"

//ctor
Senior_Seller::Senior_Seller(string name,int id,int jobPercentage,int basicSalary,int *customers,int sizeCustomers, int* canceledTransaction, int sizeCanceled) :Seller( name, id, jobPercentage, basicSalary,customers, sizeCustomers), sizeCanceled(sizeCanceled){
    this->canceledTransaction = new int[sizeCanceled];
    for (int i = 0; i < sizeCanceled; i++)
        this->canceledTransaction[i] = canceledTransaction[i];
}
 //cctor
Senior_Seller::Senior_Seller(const Senior_Seller& object):Seller( object.name, object.id, object.jobPercentage, object.basicSalary,object.customers,object.sizeCustomers), sizeCanceled(object.sizeCanceled){
   
    this->canceledTransaction = new int[sizeCanceled];
    for (int i = 0; i < sizeCanceled; i++)
        this->canceledTransaction[i] = object.canceledTransaction[i];
}

Senior_Seller& Senior_Seller::operator = (const Senior_Seller& object) {
    if (this != &object) {
        this->name = object.name;
        this->id = object.id;
        this->jobPercentage = object.jobPercentage;
        this->basicSalary= object.basicSalary;
        
        if (customers){
            delete[] customers;
        }
        canceledTransaction = new int[sizeCanceled];
        for (int i = 0; i < sizeCanceled; i++)
            this->canceledTransaction[i] = object.canceledTransaction[i];
    }
    else
        cout << "Self assignment!" << endl;

    return *this;
}

//dtor
Senior_Seller::~Senior_Seller(){
    delete [] canceledTransaction;
}

//salary calculation of senior seller
int Senior_Seller::salaryCalculation(){
    int salary = ((basicSalary+average()+sizeCustomers)*jobPercentage)*1.5;
    return salary;
}

bool Senior_Seller::operator == (const Senior_Seller& object)const {
    if(this->id == object.id){
        return true;
    }
    return false;
}
//print all his details
void Senior_Seller::print(){
    cout<<"Employee Details: "<<endl;
    cout<<"Senior Seller: "<<name<<"\nID: "<<id<<"\nJob Percentage: "<<jobPercentage<<"\nBasic Salary: "<<basicSalary<<"\nNumber of customers he served: "<<sizeCustomers<<"\nNumber Of Canceled Transaction: "<<sizeCanceled<<endl;
    cout<<"The Prices Of All The Transactions This Employee Made: "<<endl;
    for(int i = 0;i<sizeCustomers;i++){
        cout<<customers[i]<<endl;
    }
    cout<<"The Prices Of All The Canceled Transaction This Employee Made: "<<endl;
    for(int i = 0;i<sizeCanceled;i++){
        cout<<canceledTransaction[i]<<endl;
    }
}


//add Canceled Transaction to the array
void Senior_Seller::addCanceledTransaction(int value){
    int i = 0,size;
    
    int* newCanceledList = new int[sizeCanceled+1];
    for (i = 0; i<sizeCanceled; i++) {
        newCanceledList[i] = canceledTransaction[i];
    }
    newCanceledList[i] = value;
    if (canceledTransaction) {
        delete [] canceledTransaction;
    }
    canceledTransaction = newCanceledList;
    sizeCanceled++;
}

Employee * Senior_Seller::duplicate(){
    return new Senior_Seller(*this);
}
