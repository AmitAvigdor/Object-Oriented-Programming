#define _CRT_SECURE_NO_WARNINGS
#include "Cell.hpp"


Cell::Cell(){                   //defult ctor
    cell = ' ';
    free = true;
}

void Cell::print(){             //method that print
    cout<<cell<<endl;
    cout<<free<<endl;
}

void Cell::setter(char new_cell){       //changes the cell and updates if free or not
    cell = new_cell;
    if (cell == ' ') {
        free = true;
    }
    else
        free = false;
}

bool Cell::Is_free(){           // return status if free or not
    return free;
}
