#include "DFAMachine.h"
#include <string>

using std::string;

DFAMachine::DFAMachine() : machine_transition_manager(machine_state_manager.get_states(), machine_alphabet_manager.get_alphabet()) {}

bool DFAMachine::is_accepted_string(const string &str) const {
    State cur_state = machine_state_manager.get_start_state();
    for (const char& ch : str){
        if (!machine_alphabet_manager.is_valid_character(ch))
            return false;

        cur_state = machine_transition_manager.get_next_state(cur_state, ch);
    }

    return cur_state.is_accept_state();
}
