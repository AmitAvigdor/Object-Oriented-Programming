#include "Cashier's Supervisor.hpp"
//ctor
Cashiers_Supervisor::Cashiers_Supervisor(string name,int id,int jobPercentage,int basicSalary,int NumOfAction) :Employee(name,id,jobPercentage,basicSalary),NumOfAction(NumOfAction){}
//Calculation of the Cashiers Supervisor salary
int Cashiers_Supervisor::salaryCalculation(){
    int salary = (basicSalary+NumOfAction)*jobPercentage;
    return salary;
}

bool Cashiers_Supervisor::operator == (const Cashiers_Supervisor& object)const {
    if(this->id == object.id){
        return true;
    }
    return false;
}
//print all his details
void Cashiers_Supervisor::print(){
    cout<<"Employee Details: "<<endl;
    cout<<"Cashiers Supervisor: "<<name<<"\nID: "<<id<<"\nJob Percentage: "<<jobPercentage<<"\nBasic Salary: "<<basicSalary<<"\nNumber of Actions: "<<NumOfAction<<endl;}

Cashiers_Supervisor& Cashiers_Supervisor::operator = (const Cashiers_Supervisor& object) {
    if (this != &object) {
        this->name = object.name;
        this->id = object.id;
        this->jobPercentage = object.jobPercentage;
        this->basicSalary= object.basicSalary;
        this->NumOfAction=object.NumOfAction;
    }
    return *this;
}
//inc the amount of actions 
void Cashiers_Supervisor::setNumOfAction(){
    NumOfAction++;
}
Employee * Cashiers_Supervisor::duplicate(){
    return new Cashiers_Supervisor(*this);
}
