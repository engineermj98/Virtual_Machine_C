#ifndef MEMORY_HPP
#define MEMORY_HPP

#include "Instruction.hpp"
#include <string>

class Memory{
    public:
        int instructionsValue[10];
        Instruction instructions[10];
        Memory();
        void addInstruction(Instruction theInstruction,int theInstructionValue, int position);
        int getInstructionValue(int position);
        Instruction getInstruction(int position);
};

#endif