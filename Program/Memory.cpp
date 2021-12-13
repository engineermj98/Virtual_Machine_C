#include "Memory.hpp"


Memory::Memory(){}

void Memory::addInstruction(Instruction theInstruction,int theInstructionValue, int thePosition){
    instructionsValue[thePosition] = theInstructionValue;
    instructions[thePosition] = theInstruction;
}

int Memory::getInstructionValue(int thePosition){
    return instructionsValue[thePosition];
}

Instruction Memory::getInstruction(int thePosition){
    return instructions[thePosition];
}
