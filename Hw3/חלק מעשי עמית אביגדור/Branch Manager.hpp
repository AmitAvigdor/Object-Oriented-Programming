#ifndef Branch_Manager_hpp
#define Branch_Manager_hpp
#include "Employee.hpp"

class Branch_Manager : public Employee {
private:
     int managementLevel;
 
public:
    Branch_Manager(string name = "none",int id = 0,int jobPercentage = 0 ,int basicSalary = 0, int mamanagementLevel = 1);
    virtual int salaryCalculation();
    bool operator == (const Branch_Manager&)const;
    void print();
    Branch_Manager& operator = (const Branch_Manager&);
    Employee * duplicate();
};

#endif /* Branch_Manager_hpp */
