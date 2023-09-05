#include "Clothing chain.hpp"
//ctor
ClothingChain::ClothingChain(string name,Stores* allStore,int amountAllStores,string ImporterName) : ChainStores(name,allStore,amountAllStores), ImporterName(ImporterName){}

