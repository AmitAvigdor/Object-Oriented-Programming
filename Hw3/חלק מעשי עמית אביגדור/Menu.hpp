#ifndef Menu_hpp
#define Menu_hpp
#include <iostream>
#include <string>
#include<typeinfo>
#include "Employee.hpp"
#include "Chain Stores.hpp"
#include "Clothing chain.hpp"
#include "Food chain.hpp"
#include "Branch Manager.hpp"
#include "Senior Seller.hpp"
#include "Junior seller.hpp"
#include "Cashier's Supervisor.hpp"

using namespace std;

class Menu {

    
protected:
    ChainStores* allChainStores[3];
public:
    ~Menu();
    void defaultArr();
    void PrintMenu();
    void addShope();
    void addEmployee();
    void shopping();
    void returnItem();
    void printChain();
    void sumSalariesChain();
    void sumSalariesShop();
    void printShope();
    void printEmployee();
    void exit();
    
    
};


#endif /* Menu_hpp */
