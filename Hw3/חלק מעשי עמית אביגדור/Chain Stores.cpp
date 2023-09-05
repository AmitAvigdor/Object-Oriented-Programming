#include "Chain Stores.hpp"

//ctor
ChainStores::ChainStores(string name,Stores* allStore,int amountAllStores) : name(name),allStore(allStore),amountAllStores(amountAllStores){}

// copy constructor
ChainStores::ChainStores(const ChainStores& other){
    // string name;
    name = other.name;
    amountAllStores = other.amountAllStores;
    
    allStore = new Stores[amountAllStores];
    for(int i = 0 ;i < amountAllStores;i++)
        allStore[i] = other.allStore[i];
}

// copy assigment operator
ChainStores& ChainStores::operator = (const ChainStores& other){
    if(this != &other){
        name = other.name;
        amountAllStores = other.amountAllStores;
        if(allStore)
            delete[] allStore;
        allStore = new Stores[amountAllStores];
        for(int i = 0 ;i < amountAllStores;i++)
            allStore[i] = other.allStore[i];
        
    }
    return *this;
}
//dtor
ChainStores::~ChainStores(){
    delete [] allStore;
}
//check if the only worker in the chain
bool ChainStores::checkUniqueness(Stores newStore){
    for (int i = 0; i<amountAllStores; i++) {
        if(allStore[i] == newStore){
            return false;
        }
    }
    return true;
}
//find the employee
bool ChainStores::findEmployee(Employee* newEmployee){ 
    for (int i = 0 ; i<amountAllStores; i++) {
        for (int j = 0; j<allStore[i].getAmountOfWorkers(); j++) {
            if(allStore[i].getEmployee()[j] == newEmployee){
                return true;
            }
        }
    }
    return false;
}
//set the new store
void ChainStores::setStores(Stores* allStores){
    this->allStore = allStores;
}
//inc the amount of stores
void ChainStores::incAmountAllStores(){
    amountAllStores++;
}

//work in one store in the chain
bool ChainStores::workInOnlyOneStore(int id){
    for (int i = 0 ; i<amountAllStores; i++) {
               for (int j = 0; j<allStore[i].getAmountOfWorkers(); j++) {
                   if(allStore[i].getEmployee()[j]->getID() == id){
                       return false;
                   }
               }
    }
    return true;
}

//print his details
void ChainStores::print(){
    cout << "Chain name: "<< name<< " number of stores in chain: "<< amountAllStores<<endl;
    for(int i = 0 ;i < amountAllStores ;i++){
        allStore[i].print();
    }
}
//print store
void ChainStores::printStore(){
    for(int i = 0 ;i < amountAllStores ;i++){
        allStore[i].print();
    }
}
