#ifndef Game_hpp
#define Game_hpp
#include <stdio.h>
#include <iostream>
#include "Board.hpp"
#include "Player.hpp"
#include <random>



class Game{
private:
    
    
    enum statuses {win,draw,start};
    statuses status;
    char turn;
    Board *board;
    Player *players[2];

public:
    Game(char*,char*);
    
    void play();
    void updateStatus();
    
    
};








#endif /* Game_hpp */
