#include "MOV.hpp"
#include <iostream>

MOV::MOV(){}

MOV::MOV(string theName, short int theCode, short int theLength, int theValue, string theRegist, string theAddress): Instruction(theName, theCode, theLength){
    value = theValue;
    regist = theRegist;
    address = theAddress;
}
int MOV::getValue(){
    return value;
}

void MOV::display(){
    cout << regist << "," << address << endl;
}
