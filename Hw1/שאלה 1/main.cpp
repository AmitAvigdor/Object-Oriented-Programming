/* Assignment: 1
 Author: Amit Avigdor, ID: 316178144 */
#include "header.hpp"
#include <iostream>
#include <cstring>
#include <random>

int main(){
    doubledigit num,num2(549),num3('7','4');
    num.print();
    num2.print();
    num3.print();
    int i =num3.changeToInt() ;
    cout<<i<<endl;
    num2.changeValue(68);
    num2.print();
}
