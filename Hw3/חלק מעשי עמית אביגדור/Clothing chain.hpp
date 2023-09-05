#ifndef Clothing_chain_hpp
#define Clothing_chain_hpp
#include "Employee.hpp"
#include "Chain Stores.hpp"

using namespace std;

class ClothingChain:public ChainStores{
private:
     string ImporterName;
public:
    ClothingChain(string name,Stores* allStore,int amountAllStores,string ImporterName);
    Stores* getStores(){return allStore;}
};


#endif /* Clothing_chain_hpp */
