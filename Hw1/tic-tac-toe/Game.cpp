#define _CRT_SECURE_NO_WARNINGS
#include "Game.hpp"


Game::Game(char* P1name,char* P2name){                  //ctor that resets the players and the board and randomly picks the playes that will start
    players[0] = new Player('X',P1name);
    players[1] = new Player('O',P2name);
    board = new Board(9);
    status = start;
    srand(time(nullptr));
    int pr =rand() % 2;
    if(pr == 0){
        turn = players[0]->getSymbol();
    }
    if(pr == 1){
        turn = players[1]->getSymbol();
    }
}

void Game::play(){                      //function that manages the game, clean the screen,prints the screen,moving players turns and updates the games status
    while (status == start) {
        int choosenMove;
        //system("cls");                //working on Mac 
        board->print();
        if(turn == 'X'){
            cout<<"choose your move"<<endl;
            players[0]->print();
            choosenMove = players[0]->make_move();
            while (!board->set_symbol(choosenMove, turn)) {
                cout<<"Please try again"<<endl;
                choosenMove = players[0]->make_move();
            }
            updateStatus();
            if (status == win) {
                board->print();
                cout<<"we have a winner:";
                players[0]->print();
                cout<<endl;
                break;
            }
            if(status == draw ){
                board->print();
                cout<<"It is a Draw"<<endl;
                break;
            }
            board->print();
            turn = 'O';
            
        }
        if(turn == 'O'){
            cout<<"choose your move"<<endl;
            players[1]->print();
            choosenMove = players[1]->make_move();
            while (!board->set_symbol(choosenMove, turn)) {
                cout<<"Please try again"<<endl;
                choosenMove = players[1]->make_move();

            }
            updateStatus();
            if (status == win) {
                board->print();
                cout<<"we have a winner:";
                players[1]->print();
                cout<<endl;
                break;
            }
            if(status == draw ){
                board->print();
                cout<<"It is a Draw"<<endl;
                break;
            }
            turn = 'X';
        }
    }
}

void Game::updateStatus(){              // check for win or draw 
    for (int i = 0; i<9; i+=3) {
        if (board->get_symbol(i) == board->get_symbol(i+1) && board->get_symbol(i+1) == board->get_symbol(i+2) && board->get_symbol(i+2) != ' ') {
            status = win;
        }
    }
    for (int i = 0; i < 3; i++) {
        
        if(board->get_symbol(i) == board->get_symbol(i+3) && board->get_symbol(i+3) == board->get_symbol(i+6) && board->get_symbol(i+6) != ' ')
            status = win;

    }
    if (board->get_symbol(0) == board->get_symbol(4) && board->get_symbol(4) == board->get_symbol(8) && board->get_symbol(8) != ' ') {
        status = win;
    }
    if (board->get_symbol(2) == board->get_symbol(4) && board->get_symbol(4) == board->get_symbol(6) && board->get_symbol(6) != ' ') {
        status = win;
    }
    
    if(status != win){
        int counter = board->count_board();
        if (counter == 0){
            status = draw;
        }
    }
}

