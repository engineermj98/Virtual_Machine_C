//MAIN-ProgramUML
#include <stdlib.h>
#include <iostream>
#include "Instruction.hpp"
#include "Program.hpp"
#include "CU.hpp"
#include "ADD.hpp"
#include "SUSTR.hpp"
#include "DIV.hpp"
#include "MULT.hpp"
#include "MOV.hpp"
#include "STO.hpp"
#include "CPU.hpp"
#include "Memory.hpp"

using namespace std;
int main(void){
    Instruction start("START",50,1);
    MOV mov1("MOVE",90,3,5,"eax","1");
    MOV mov2("MOVE",90,3,3,"ebx","2");
    ADD add("ADD",80,3,27,3,"3");
    STO sto("STORE",91,2,6,"4");
    Instruction stop("STOP",51,1);

    Program program;
    
    program.addInstruction(start,0);
    program.addInstruction(mov1,1);
    program.addInstruction(mov2,2);
    program.addInstruction(add,3);
    program.addInstruction(sto,4);
    program.addInstruction(stop,5);
    CPU cpu;
    cpu.executeMachineCycle(program);
/*
    cout << program.getInstruction(0).getName() <<endl;
    cout << program.getInstruction(1).getName() <<endl;
    cout << program.getInstruction(2).getName() <<endl;
    cout << program.getInstruction(3).getName() <<endl;
    cout << program.getInstruction(4).getName() <<endl;
    cout << program.getInstruction(5).getName() <<endl;
    */
    /*
    cout << program.getInstruction(6).getName() <<endl;
    cout << program.getInstruction(7).getName() <<endl;
     */
   
   /*
    cout << endl;
    CU cu("fetch");
    Instruction theInstruction;
    for(int pos=0; pos < 8; pos++){
        theInstruction = cu.fetch(program, pos);
        int theCode = cu.decode(theInstruction);
        cu.execute(theCode);
    }
    */
  
    cout << endl;
    Memory memory;
//////////////////////////////////////////////////////////////////////////////////////////////////////// cpu: reutiliza CU, memoria tipo instruccion
    Instruction* instructions[5];
    instructions[0]=&start;
    instructions[1]=&mov1;
    instructions[2]=&mov2;
    instructions[3]=&add;
    instructions[4]=&sto;
    instructions[5]=&stop;


    MOV* mo1 = static_cast<MOV*>(instructions[1]);
    MOV* mo2 = static_cast<MOV*>(instructions[2]);
    auto* ptr_add = static_cast<ADD*>(instructions[3]);
    auto* ptr_sub = static_cast<SUSTR*>(instructions[4]);
    auto* ptr_divi = static_cast<DIV*>(instructions[5]);
    auto* ptr_multi = static_cast<MULT*>(instructions[6]);
    
    printf("ins1= %i\n", ptr_add->getOperand1());
    //memory.addInstruction(mov1,mo1->getValue(),1);
    //memory.addInstruction(mov2,mo2->getValue(),2);
    //memory.addInstruction(add,ptr_add->getOperand1(),3);
    //printf("ins1= %i\n", memory.getInstructionValue(1));
    //printf("ins1= %i\n", memory.getInstructionValue(2));


///////////////////////////////////////////////////////////////////////////////////////////////////
/*
    MOV* mo1 = static_cast<MOV*>(instructions[1]);
    MOV* mo2 = static_cast<MOV*>(instructions[2]);
    auto* ptr_add = static_cast<ADD*>(instructions[3]);
    auto* ptr_sub = static_cast<SUSTR*>(instructions[4]);
    auto* ptr_divi = static_cast<DIV*>(instructions[5]);
    auto* ptr_multi = static_cast<MULT*>(instructions[6]);

    register int d1,d2,m1,m2; 
    register int addition,substraction,divition,multiplication;

    //cout << "MOV test values" << endl;
    cout << mov1.getValue() << endl;
    cout << mov2.getValue() << endl;

    d1 = mo1->getValue();
    d2 = mo2->getValue();
    m1 = mo1->getValue();
    m2 = mo2->getValue();

    asm("movl %1, %%eax;"
        "movl %2, %%ebx;"
        "addl %%ebx, %%eax;"
        : "=a" (addition)
        : "a" (mo1->getValue()), "b" (mo2->getValue())
    );
    printf("sum= %i\n", addition);

    asm("movl %1, %%eax;"
        "movl %2, %%ebx;"
        "subl %%ebx, %%eax;"
        : "=a" (substraction)
        : "a" (mo1->getValue()), "b" (mo2->getValue())
    
    );
    printf("res= %i\n", substraction);

    asm("movl %1, %%eax;"
        "movl %2, %%ebx;"
        "divl %%ebx, %%eax;"
        : "=a" (divition)
        : "a" (d1), "b" (d2)
    
    );
    printf("div= %i\n", divition);

    asm("movl %1, %%eax;"
        "movl %2, %%ebx;"
        "imull %%ebx, %%eax;"
        : "=a" (multiplication)
        : "a" (m1), "b" (m2)
    
    );
    printf("mult= %i\n", multiplication);

    // Arithmetic operations realized operating directly with values
/*
    //cout << ptr_divi->getOperand1() << endl;
    //cout << ptr_divi->getOperand2() << endl;
    //d1 = ptr_divi->getOperand1();
    //d2 = ptr_divi->getOperand2();
    //m1 = ptr_multi->getOperand1();
    //m2 = ptr_multi->getOperand2();
    asm("addl %%ebx, %%eax;"
        : "=a" (addition)
        : "a" (ptr_add->getOperand1()), "b" (ptr_add->getOperand2())    
    );
    printf("sum= %i\n", addition);

    asm("subl %%ebx, %%eax;"
        : "=a" (substraction)
        : "a" (ptr_sub->getOperand1()), "b" (ptr_sub->getOperand2())    
    );
    printf("res= %i\n", substraction);

    asm("divl %%ebx, %%eax;"
        : "=a" (divition)
        : "a" (d1), "b" (d2)    
    );
    printf("div= %i\n", divition);

    asm("imull %%ebx, %%eax;"
        : "=a" (multiplication)
        : "a" (m1), "b" (m2)    
    );
    printf("mul= %i", multiplication);

    // Arithmetic operations realized moving values between registers

*/
    
    return EXIT_SUCCESS;
}
