#include "Instruction.hpp"
#include <string>
#ifndef STO_HPP
#define STO_HPP

class STO: public Instruction{
    private:
        string address;
        int value;
    public:
        STO();
        STO(string theName, short int theCode, short int theLength, int theValue, string theAddress);
        int getValue();
        void display();
};

#endif
