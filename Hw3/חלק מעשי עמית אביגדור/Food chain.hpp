#ifndef Food_chain_hpp
#define Food_chain_hpp
#include "Stores.hpp"
#include "Chain Stores.hpp"

using namespace std;

class FoodChain : public ChainStores{
private:
     int numFoodSuppliers;
public:
    FoodChain(string name,Stores* allStore,int amountAllStores,int numFoodSuppliers);
};


#endif /* Food_chain_hpp */
