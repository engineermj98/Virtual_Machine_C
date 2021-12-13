#include "ADD.hpp"
#include <iostream>

ADD::ADD(){}

ADD::ADD(string theName, int theCode, int theLength, int theOperand1, int theOperand2, string theAddress): Instruction(theName, theCode, theLength){
    operand1 = theOperand1;
    operand2 = theOperand2;
    address = theAddress;
}
int ADD::getOperand1(){
    return operand1;
}
int ADD::getOperand2(){
    return operand2;
}
void ADD::display(){
    cout << address << endl;
}