#include "Employee.hpp"
//base class

//ctor
Employee::Employee(string name,int id,int jobPercentage,int basicSalary) :name(name ),id(id),jobPercentage(jobPercentage),basicSalary(basicSalary)
{}

bool Employee::operator == (const Employee& object)const {
    if(this->id == object.id){
        return true;
    }
    return false;
}

int Employee::salaryCalculation(){return 0;}

Employee::~Employee(){}

Employee& Employee::operator = (const Employee& object) {
    if (this != &object) {
        this->name = object.name;
        this->id = object.id;
        this->jobPercentage = object.jobPercentage;
        this->basicSalary= object.basicSalary;
    }
    return *this;
}


