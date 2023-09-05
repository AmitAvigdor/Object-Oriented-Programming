#ifndef Junior_seller_hpp
#define Junior_seller_hpp
#include "Employee.hpp"
#include "Cashier's Supervisor.hpp"
#include "Seller.hpp"

class Junior_seller : public Seller {
    
public:
    Junior_seller(string name = "none",int id = 0,int jobPercentage = 0 ,int basicSalary = 0,int* customers = nullptr, int sizeCustomers = 0);
    
    virtual int salaryCalculation();
    Junior_seller& operator = (const Junior_seller&);
    ~Junior_seller();
    bool operator == (const Junior_seller&)const;
    void print();
    Employee * duplicate();
};

#endif /* Junior_seller_hpp */
