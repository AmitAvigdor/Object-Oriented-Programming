#ifndef Stores_hpp
#define Stores_hpp
#include <iostream>
#include <string>
#include "Employee.hpp"


using namespace std;

class Stores {
protected:
    int IdOfStore;
    string chainStoreName;
    Employee** allWorkers;// this is a dynamic array , every element holds an address
    int amountOfWorkers;
    
public:
    Stores(int IdOfStore = 0,string chainStoreName = "none",Employee** allWorkers = nullptr,int amountOfWorkers = 0);
    ~Stores();
    Stores(const Stores& other);
    Stores& operator=(const Stores& other);
    bool operator == (const Stores&)const;
    virtual Employee** getEmployee(){return allWorkers;}
    virtual int getAmountOfWorkers(){return amountOfWorkers;}
    void print();
    void setEmployee(Employee*);
    void incAmountOfWorkers();
    int getID(){return IdOfStore;}
    void printEmployee();

};


#endif /* Stores_hpp */
