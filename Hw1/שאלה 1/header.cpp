#include "header.hpp"

//ctor defult
doubledigit::doubledigit(){
    unitsPlace = '0';
    tensPlace = '0';
}
//ctor
doubledigit::doubledigit(int number){
    SetByint(number);

}
//ctor
doubledigit::doubledigit(char first,char second){
    SetByTwoChar(first,second);
}

//print
void doubledigit::print(){
    cout<<tensPlace<<unitsPlace<<endl;
}
//function that get int and insert it to the data members
void doubledigit::SetByint(int number){
    unitsPlace = (number % 10) + '0';
    tensPlace = (number % 100)/10 + '0';
}
//function that get two chars and insert it to the data members
void doubledigit::SetByTwoChar(char first, char second){
    unitsPlace = second;
    tensPlace = first;
}
//function that take the data from the data members and change it to int
int doubledigit::changeToInt(){
    char first = GetunitsPlace();
    char sec = GettensPlace();
    int complete = ((sec - '0')*10) + (first - '0');
    return complete;
}
//function that get int and insert it to the data members
void doubledigit::changeValue(int value){
    SetByint(value);
}
