#ifndef DFAAPP_H
#define DFAAPP_H
#include "DFAMachine.h"

class DFAApp{
private:
    void print_instructions() const;

    void DFA_menu(const DFAMachine& dfa) const;
public:
    DFAApp() = default;

    void start();
};

#endif