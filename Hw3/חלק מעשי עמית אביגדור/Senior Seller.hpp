#ifndef Senior_Seller_hpp
#define Senior_Seller_hpp
#include "Employee.hpp"
#include "Cashier's Supervisor.hpp"
#include "Seller.hpp"


class Senior_Seller : public Seller { 
    
private:
    int *canceledTransaction;
    int sizeCanceled;
public:
    Senior_Seller(string name = "none",int id = 0,int jobPercentage = 0 ,int basicSalary = 0,int* customers = nullptr, int sizeCustomers=0, int* canceledTransaction = nullptr, int sizeCanceled=0);
    
    Senior_Seller(const Senior_Seller&);
    Senior_Seller& operator = (const Senior_Seller&);
    ~Senior_Seller();
    virtual int salaryCalculation();
    bool operator == (const Senior_Seller&)const;
    void print();
    void addCanceledTransaction(int value);
    Employee * duplicate();
};

#endif /* Senior_Seller_hpp */
