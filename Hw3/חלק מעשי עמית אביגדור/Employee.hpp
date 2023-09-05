#ifndef Employee_hpp
#define Employee_hpp
#include <iostream>
#include <string>

using namespace std;

class Employee {
protected:
    string name;
    int id;
    int jobPercentage;
    int basicSalary;
    
public:
    Employee(string name = "none",int id = 0,int jobPercentage = 0 ,int basicSalary = 0);
    virtual ~Employee()=0;
    virtual int salaryCalculation();
    virtual bool operator == (const Employee&)const;
    virtual void print() = 0;
    Employee& operator = (const Employee&);
    void addCustomer();
    int getID(){return id;}
    virtual Employee* duplicate() = 0;
};
#endif /* Employee_hpp */
