#ifndef header_hpp
#define header_hpp
#include <iostream>
#include <cstring>
#include <random>
using namespace std;

class doubledigit{

private: //data members
    char unitsPlace;
    char tensPlace;

public: //Methods
    doubledigit(); //ctor defult
    doubledigit(int); //ctor
    doubledigit(char, char); //ctor
  
    
    void print();
    int changeToInt();
    void changeValue(int);
    
    void SetByint(int);
    void SetByTwoChar(char,char);
    
    int GetunitsPlace(){return unitsPlace;}
    int GettensPlace(){ return tensPlace;}
};





#endif /* header_hpp */
