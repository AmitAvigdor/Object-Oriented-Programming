#include "Branch Manager.hpp"
//ctor
Branch_Manager::Branch_Manager(string name,int id,int jobPercentage,int basicSalary,int managementLevel) :Employee(name, id, jobPercentage, basicSalary), managementLevel(managementLevel){}
//Calculation of the salary
int Branch_Manager::salaryCalculation(){
    int salary = basicSalary*managementLevel*jobPercentage;
    return salary;
}

bool Branch_Manager::operator == (const Branch_Manager& object)const {
    if(this->id == object.id){
        return true;
    }
    return false;
}

Branch_Manager& Branch_Manager::operator = (const Branch_Manager& object) {
    if (this != &object) {
        this->name = object.name;
        this->id = object.id;
        this->jobPercentage = object.jobPercentage;
        this->basicSalary= object.basicSalary;
        this->managementLevel = object.managementLevel;
    }
    return *this;
}

//print the Branch Manager details
void Branch_Manager::print(){
    cout<<"Employee Details: "<<endl;
    cout<<"Branch Manager: "<<name<<"\nID: "<<id<<"\nJob Percentage: "<<jobPercentage<<"\nBasic Salary: "<<basicSalary<<"\nManagement Level: "<<managementLevel<<endl;
    
}

Employee * Branch_Manager::duplicate(){
    return new Branch_Manager(*this);
}


