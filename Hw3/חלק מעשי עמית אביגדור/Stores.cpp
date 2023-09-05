#include "Stores.hpp"
//ctor
Stores::Stores(int IdOfStore,string chainStoreName,Employee** allWorkers,int amountOfWorkers) :IdOfStore(IdOfStore),chainStoreName(chainStoreName),allWorkers(allWorkers),amountOfWorkers(amountOfWorkers){}
//cctor
Stores::Stores(const Stores& other){
     IdOfStore = other.IdOfStore ;
    chainStoreName = other.chainStoreName;
    amountOfWorkers = other.amountOfWorkers;
    allWorkers = new Employee*[amountOfWorkers];
    for(int i = 0 ;i < amountOfWorkers;i++){
        allWorkers[i] =  other.allWorkers[i];
    }
}
//dtor
Stores::~Stores(){
    for(int i = 0 ;i < amountOfWorkers ;i++){
        delete allWorkers[i];
    }
    delete allWorkers;

}

Stores& Stores::operator = (const Stores& object) {
//    cout<<"stores copy assignment operator: id "<< object.IdOfStore <<" name: "<< object.chainStoreName<< endl;
    if (this != &object) {
        this->IdOfStore = object.IdOfStore;
        this->chainStoreName = object.chainStoreName;
        this->amountOfWorkers = object.amountOfWorkers;
        if (allWorkers){ // if (numbers != nullptr)
            delete[] allWorkers;
        }
        allWorkers = new Employee*[amountOfWorkers];
        allWorkers = object.allWorkers;
        for (int i = 0; i < amountOfWorkers; i++)
            allWorkers[i] = object.allWorkers[i];
    }
    else
        cout << "Self assignment!" << endl;

    return *this;
}

bool Stores::operator == (const Stores& object)const {
    if(this->IdOfStore == object.IdOfStore){
        return true;
    }
    return false;
}
//set for the new employee
void Stores::setEmployee(Employee* newEmployee){
    Employee** tempEmployeeArr = new Employee*[amountOfWorkers+1];
    int m;
    for( m = 0;m< amountOfWorkers;m++){
        tempEmployeeArr[m] = allWorkers[m];
    }
    tempEmployeeArr[m] = newEmployee;
    // delete old array of workers
    delete[] allWorkers;
    allWorkers = tempEmployeeArr;
    incAmountOfWorkers();
    cout<<"Employee Added!"<<endl;
}
//inc amount of employee
void Stores::incAmountOfWorkers(){
    amountOfWorkers++;
}
//print
void Stores::print(){
    cout<<"Shop Details: "<<endl;
    cout << "Store Id: "<< IdOfStore << "\nNumber Of Employees: "<< amountOfWorkers<< endl;
    for(int i = 0 ;i < amountOfWorkers ;i++){
        allWorkers[i]->print();
    }
}

void Stores::printEmployee(){
    for(int i = 0 ;i < amountOfWorkers ;i++){
        allWorkers[i]->print();
    }
}
