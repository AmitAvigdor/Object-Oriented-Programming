#include "Junior seller.hpp"

//ctor
Junior_seller::Junior_seller(string name,int id,int jobPercentage,int basicSalary,int *customers,int sizeCustomers) : Seller(name,id,jobPercentage,basicSalary, customers,sizeCustomers) {}


//salary calculation of Junior seller
int Junior_seller::salaryCalculation(){
    int salary = (basicSalary+average()+sizeCustomers)*jobPercentage;
    return salary;
}

//dtor
Junior_seller::~Junior_seller(){
    delete [] customers;
    
}

bool Junior_seller::operator == (const Junior_seller& object)const {
    if(this->id == object.id){
        return true;
    }
    return false;
}
//print his details
void Junior_seller::print(){
    cout<<"Employee Details: "<<endl;
    cout<<"Junior Seller: "<<name<<"\nID: "<<id<<"\nJob Percentage: "<<jobPercentage<<"\nBasic Salary: "<<basicSalary<<"\nNumber of customers he served: "<<sizeCustomers<<endl;
    cout<<"The Prices Of All The Transactions This Employee Made: "<<endl;
    for(int i = 0;i<sizeCustomers;i++){
        cout<<customers[i]<<endl;
    }
}

Junior_seller& Junior_seller::operator = (const Junior_seller& object) {
    if (this != &object) {
        this->name = object.name;
        this->id = object.id;
        this->jobPercentage = object.jobPercentage;
        this->basicSalary= object.basicSalary;
        if (customers){
            delete[] customers;
        }
        customers = new int[sizeof(object.customers)];
        for (int i = 0; i < sizeof(object.customers); i++)
            customers[i] = object.customers[i];
    }
    else
        cout << "Self assignment!" << endl;

    return *this;
}


Employee * Junior_seller::duplicate(){
    return new Junior_seller(*this); 
}
