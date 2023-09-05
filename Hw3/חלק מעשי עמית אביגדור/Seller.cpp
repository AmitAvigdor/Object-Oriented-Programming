#include "Seller.hpp"
//ctor
Seller::Seller(string name,int id,int jobPercentage,int basicSalary, int* customers, int sizeCustomers):Employee( name, id, jobPercentage, basicSalary), sizeCustomers(sizeCustomers)
{
    // deep copy of parameter
    this->customers = new int[sizeCustomers];
    for(int i = 0 ;i < sizeCustomers;i++){
        this->customers[i] =customers[i];
    }
}
//cctor
Seller::Seller(const Seller& other){
    sizeCustomers  = other.sizeCustomers;
    customers = new int[sizeCustomers];
    for(int i = 0 ;i < sizeCustomers;i++)
        customers[i] = other.customers[i];
    
}
Seller& Seller::operator=(const Seller& other){
    if(this!=&other){
        if(this->customers)
            delete[] customers;
        
        sizeCustomers  = other.sizeCustomers;
        customers = new int[sizeCustomers];
        for(int i = 0 ;i < sizeCustomers;i++)
            customers[i] = other.customers[i];
    }
    return *this;
}
//dtor
Seller::~Seller(){
    delete[] customers;
}
//avarge for the salary calculation
int Seller::average(){
    int i = 0 , sum = 0;
    while (sizeCustomers != i) {
        sum += customers[i];
        i++;
    }
    if(i == 0){
        return sum;
    }
    sum = sum / i;
    return sum;
    
}
//adding a customer to the customer array
void Seller::addCustomer(int value){
    int i = 0;
    
    int* newCustomerList = new int[sizeCustomers+1];
    for (i = 0; i<sizeCustomers; i++) {
        newCustomerList[i] = customers[i];
    }
    newCustomerList[i] = value;
    if (customers) {
        delete [] customers;
    }
    customers = newCustomerList;
    sizeCustomers++;
}
