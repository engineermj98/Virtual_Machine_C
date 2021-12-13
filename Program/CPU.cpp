#include "CPU.hpp"
#include <iostream>
#include <cstring>

CPU::CPU(){}

CPU::CPU(Program program){
}

void CPU::executeMachineCycle(Program program){
    Instruction theInstruction;
    CU cu;

    for(int pos=0; pos < 10; pos++){
        theInstruction = cu.fetch(program, pos);
        if(pos == 1){
            cu.getStatus();
        }
        int theCode = cu.decode(theInstruction);
        if(pos == 2){
            cu.getStatus();
        }
        cu.execute(theCode);
        if(pos == 3){
            cu.getStatus();
        }
    }

}