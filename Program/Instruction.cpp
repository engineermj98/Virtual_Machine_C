#include "Instruction.hpp"
#include <iostream>

Instruction::Instruction() {}

Instruction::Instruction(string theName, short int theCode, short int theLength){
    name = theName;
    code = theCode;
    length = theLength;
}
void Instruction::display(){
    cout << name << "," << code << "," << length << endl;
}
string Instruction::getName(){
    return name;
}
int Instruction::getCode(){
    return code;
}