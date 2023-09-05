#include "Food chain.hpp"

//ctor
FoodChain::FoodChain(string name,Stores* allStore,int amountAllStores,int numFoodSuppliers) :ChainStores(name,allStore,amountAllStores),numFoodSuppliers(numFoodSuppliers){}
