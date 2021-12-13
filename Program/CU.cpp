#include "CU.hpp"
#include "Instruction.hpp"
#include "MOV.hpp"
#include "ADD.hpp"
#include "SUSTR.hpp"
#include "MULT.hpp"
#include "DIV.hpp"
#include "STO.hpp"
#include "Memory.hpp"



CU::CU(){
    status = "idle";
}

CU::CU(string theStatus){
    status = theStatus;
}
void CU::getStatus(){
    cout << status << endl;
}
Instruction* CU:: fetch(Program* theProgram, int thePosition){
    status = "fetch";
    return theProgram.getInstruction(thePosition);
}
int CU::decode(Instruction theInstruction){
    status = "decode";
    return theInstruction.getCode();
}

void CU::execute(int theCode){
    status = "execute";
    Program theProgram;
    MOV mov1("MOVE",90,3,27,"eax","1");
    MOV mov2("MOVE",90,3,3,"ebx","2");
    ADD add("ADD",80,3,27,3,"3");
    SUSTR sub("SUB",80,3,27,3);
    MULT mult("MULT",80,3,27,3);
    DIV div("DIV",80,3,27,3);
    STO sto("STORE",91,2,6,"4");
    Instruction* instructions[8];

    Memory memory;

    instructions[1]=&mov1;
    instructions[2]=&mov2;
    instructions[3]=&add;
    instructions[4]=&sub;
    instructions[5]=&mult;
    instructions[6]=&div;
    instructions[7]=&sto;

    //theProgram.getInstruction(3);

    auto* ptr_add = static_cast<ADD*>(instructions[3]);
    auto* ptr_sub = static_cast<SUSTR*>(instructions[4]);
    auto* ptr_divi = static_cast<DIV*>(instructions[5]);
    auto* ptr_multi = static_cast<MULT*>(instructions[6]);
    MOV* mo1 = static_cast<MOV*>(instructions[1]);
    MOV* mo2 = static_cast<MOV*>(instructions[2]);


    register int total,movee,addition;
    register int d1,d2,m1,m2,a1,a2,s1,s2; 
    register int valor;

    a1 = ptr_add->getOperand1();
    a2 = ptr_add->getOperand2();
    d1 = ptr_divi->getOperand1();
    d2 = ptr_divi->getOperand2();
    m1 = ptr_multi->getOperand1();
    m2 = ptr_multi->getOperand2();
    //printf("tst= %i\n", add.getOperand1());
    //printf("mem = %i", memory.getInstructionValue(3));
    
    switch(theCode){
        case 50: 
            cout << "START" << endl;
            break;
        case 51:
            cout << "END" << endl;
            break;
        case 80: 81: 82: 83: 90: 91:
            cout << "ADD" << endl;
            asm("addl %%ebx, %%eax;"
            : "=a" (addition)
            : "a" (a1), "b" (a2)   
             "subl %%ebx, %%eax;"
             : "=a" (total)
            : "a" (ptr_sub->getOperand1()), "b" (ptr_sub->getOperand2())  
            "divl %%ebx, %%eax;"
            : "=a" (total)
            : "a" (d1), "b" (d2)  
            "imull %%ebx, %%eax;" 
            : "=a" (total)
            : "a" (m1), "b" (m2)  
            "movl %1, %%eax;"
            : "=a" (total)
            : "a" (mo1->getValue())
            "movl %1, %%ebx;"
            : "=a" (movee)
            : "a" (mo2->getValue())
            "movl %1, %%ecx;"
            : "=a" (total)
            : "a" (valor)
            );
            printf("%i\n", addition);
            printf("%i\n", total);
            valor = addition;
            //printf("store= %d\n", valor);
            break;
        default:
            break;
    }
}