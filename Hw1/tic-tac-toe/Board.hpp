#ifndef Board_hpp
#define Board_hpp
#include <stdio.h>
#include <iostream>
#include "Cell.hpp"

class Board{
    
private:
    Cell* board;
    int size;
    
public:
    Board();
    Board(int);
    Board(const Board& other);
    ~Board();
    
    void print();
    
    bool set_symbol(int,char);
    int count_board();
    
    char get_symbol(int);
    
    
    
};





#endif /* Board_hpp */
