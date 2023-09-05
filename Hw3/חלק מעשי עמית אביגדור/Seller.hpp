#ifndef Seller_hpp
#define Seller_hpp

#include <stdio.h>
#include "Employee.hpp"
class Seller : public Employee{
protected:
    int *customers;
    int sizeCustomers;
public:
    Seller(string name,int id,int jobPercentage,int basicSalary, int* customers, int sizeCustomers) ;
    Seller(const Seller& other);
    Seller& operator=(const Seller& other);
    ~Seller();
    int average();
    virtual Employee * duplicate()=0;
    virtual void addCustomer(int);
};
#endif /* Seller_hpp */
