#include "SUSTR.hpp"

SUSTR::SUSTR(){}

SUSTR::SUSTR(string theName, int theCode, int theLength, int theOperand1, int theOperand2): Instruction(theName, theCode, theLength){
    operand1 = theOperand1;
    operand2 = theOperand2;
}
int SUSTR::getOperand1(){
    return operand1;
}
int SUSTR::getOperand2(){
    return operand2;
}