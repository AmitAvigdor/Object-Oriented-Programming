#ifndef Cell_hpp
#define Cell_hpp
#include <stdio.h>
#include <iostream>
using namespace std;

class Cell
{
private:
    char cell;
    bool free;
    
public:
    Cell();
    
void setter(char);

char getter(){ return cell;}

void print();
bool Is_free();


};



#endif /* Cell_hpp */
