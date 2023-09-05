#ifndef Chain_Stores_hpp
#define Chain_Stores_hpp
#include <iostream>
#include <string>
#include "Stores.hpp"
#include "Branch Manager.hpp"
#include "Senior Seller.hpp"
#include "Junior seller.hpp"
#include "Cashier's Supervisor.hpp"


using namespace std;

class ChainStores {
protected:
    string name;
    Stores* allStore;
    int amountAllStores;
public:
    ChainStores(string name = "none",Stores* allStore = nullptr ,int amountAllStores = 0);
    ChainStores(const ChainStores& other);
    ChainStores& operator=(const ChainStores& other);
    virtual ~ChainStores();
    virtual bool checkUniqueness (Stores);
    virtual bool findEmployee(Employee*);
    virtual int getAmountAllStores(){return amountAllStores;}
    virtual string getName(){return name;}
    virtual Stores* getAllStores(){return allStore;}
    virtual void setStores(Stores*);
    virtual void incAmountAllStores();
    virtual bool workInOnlyOneStore(int);
    void printStore();
    void print();
};

#endif /* Chain_Stores_hpp */
