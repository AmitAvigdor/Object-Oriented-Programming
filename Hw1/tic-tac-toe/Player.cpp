#define _CRT_SECURE_NO_WARNINGS
#include "Player.hpp"


Player::Player(){               //defult ctor
    name = nullptr;
    symbol = ' ';
}

Player::Player(char symbol,char* name){         //ctor that updates values
    setSymbol(symbol);
    setName(name);
}

Player::~Player(){              //dtor
    delete [] name;
}

int Player::make_move(){        //gets wanted move from the user
    int moveP = 0;
    cin>>moveP;
    return moveP;
}

void Player::print(){           //prints players details
    cout<<"Player name: "<<getName()<<" with symbol: "<<getSymbol()<<endl;
    
}

void Player::setName(char* Nname){              //set for the name
    name = new char[strlen(Nname)];
    strcpy(name, Nname);
}

void Player::setSymbol(char Nsymbol){           //set for the symbol
    symbol = Nsymbol;
}

