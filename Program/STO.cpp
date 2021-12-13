#include "STO.hpp"
#include <iostream>

STO::STO(){}

STO::STO(string theName, short int theCode, short int theLength, int theValue, string theAddress): Instruction(theName, theCode, theLength){
    value = theValue;
    address = theAddress;
}
int STO::getValue(){
    return value;
}
void STO::display(){
    cout << address << endl;
}
