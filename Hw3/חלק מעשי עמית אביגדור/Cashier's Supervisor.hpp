#ifndef Cashier_s_Supervisor_hpp
#define Cashier_s_Supervisor_hpp
#include "Employee.hpp"


class Cashiers_Supervisor : public Employee {
    
private:
    int NumOfAction;
public:
    Cashiers_Supervisor(string name = "none",int id = 0,int jobPercentage = 0 ,int basicSalary = 0,int NumOfAction = 0);
    
    virtual int salaryCalculation();
    bool operator == (const Cashiers_Supervisor&)const;
    Cashiers_Supervisor& operator = (const Cashiers_Supervisor&);
    void print();
    int getNumOfAction(){return NumOfAction;}
    void setNumOfAction();
    Employee * duplicate();
};
#endif /* Cashier_s_Supervisor_hpp */
