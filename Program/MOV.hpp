#include "Instruction.hpp"
#include <string>
#ifndef MOV_HPP
#define MOV_HPP

class MOV: public Instruction{
    private:
        string regist;
        string address;
        int value;
    public:
        MOV();
        MOV(string theName, short int theCode, short int theLength, int theValue, string theRegist, string theAddress);
        int getValue();
        void display();
};

#endif
