#ifndef Player_hpp
#define Player_hpp
#include <stdio.h>
#include <iostream>
using namespace std;

class Player{
    
private:
    char* name;
    char symbol;
    Player(const Player& other);
    
public:
    Player();
    Player(char,char*);
    ~Player();
    
    int make_move();
    void print();
    
    void setName(char*);
    void setSymbol(char);
    
    char* getName(){return name;}
    char getSymbol(){return symbol;}
    
};












#endif /* Player_hpp */
