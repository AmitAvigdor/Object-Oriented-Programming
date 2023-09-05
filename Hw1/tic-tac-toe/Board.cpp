#define _CRT_SECURE_NO_WARNINGS
#include "Board.hpp"
#include <stdio.h>
#include <iostream>
using namespace std;


Board::Board(){                     // defult ctor
    board = nullptr;
    size = 0;
}

Board::Board(int new_size){         //ctor that gets size and alocates dynamic memory
    size = new_size;
    board = new Cell[size];
    
}

Board::Board(const Board& other) : size(other.size) {           //copy constractor
    board = new Cell[size];
    for (int i = 0; i < size; i++)
        board[i] = other.board[i];
}

Board::~Board(){                    // dctor
    delete board;
}

void Board::print(){                // prints the board
    int i = 0;
    while(i<9){
        cout<<"     |     |     "<<endl;
        cout<<"  " << board[i].getter() << "  |" << "  " <<board[i+1].getter() << "  |" << "  " <<board[i+2].getter() << "  "<<endl;
        if(i==6){
            cout<<"     |     |     "<<endl;
            break;
        }
        cout<<"_____|_____|_____"<<endl;
        i+=3;
    }

}


bool Board::set_symbol(int numSpot, char xo){ // gets number of cell and a char, the function checks if its ok to insert and if it is, the number of cell gets updated.returns if succeeded or not
    if (numSpot > 9 || numSpot < 1) {
        return false;
    }
    if (xo != 'X' &&  xo != 'O') {
        return false;
    }
    if (!board[numSpot -1].Is_free()) {
        return false;
    }
    board[numSpot-1].setter(xo);
    return true;
}

                                             
int Board::count_board(){       // returns the amount of empty cells
    int counter = 0;
    for(int i=0;i<9;i++){
        if(board[i].Is_free()){
            counter ++;
        }
    }
    return counter;
}


char Board::get_symbol(int selectedSpot){           //returns the symbol of the wanted cell
    return board[selectedSpot].getter();
}

