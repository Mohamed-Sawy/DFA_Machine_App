#include "TransitionManager.h"
#include "InputValidator.h"
#include <iostream>
#include <set>

using std::cout;
using std::string;
using std::set;

TransitionManager::TransitionManager(const set<State> &states, const set<char> &characters) {
    this->add_transitions(states, characters);
}

void TransitionManager::add_transitions(const set<State> &states, const set<char> &characters) {
    cout<<"\n\nEnter the next state for each of the following conditions:\n";

    for (const State& state : states){
        for (const char& ch : characters){
            cout<<"\nstate "<<state.get_id()<<" and character "<<ch<<": ";
            string next_state_id = InputValidator::read_string();

            while (states.find(State(next_state_id)) == states.end()){
                cout<<"\nPlease enter a valid state for the above condition: ";
                next_state_id = InputValidator::read_string();
            }

            transition_table.insert(Transition(state, ch, *states.find(State(next_state_id))));
        }
    }
}

State TransitionManager::get_next_state(const State &cur_state, const char &cur_char) const{
    return this->transition_table.find(Transition(cur_state, cur_char))->get_next_state();
}
