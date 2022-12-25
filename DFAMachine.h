#ifndef DFAMACHINE_H
#define DFAMACHINE_H
#include <string>
#include "State.h"
#include "StateManager.h"
#include "AlphabetManager.h"
#include "TransitionManager.h"

using std::string;

class DFAMachine{
private:
    StateManager machine_state_manager;
    AlphabetManager machine_alphabet_manager;
    TransitionManager machine_transition_manager;
public:
    DFAMachine();

    bool is_accepted_string(const string& str) const;
};

#endif