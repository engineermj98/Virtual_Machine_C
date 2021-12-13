#ifndef ADD_HPP
#define ADD_HPP
#include "Instruction.hpp"
#include <string>


using namespace std;
class ADD: public Instruction{
    private:
        int operand1;
        int operand2;
        string address;
    public:
        ADD();
        ADD(string theName, int theCode, int theLength, int theOperand1, int theOperand2, string theAddress);
        int getOperand1();
        int getOperand2();
        void display();
};

#endif