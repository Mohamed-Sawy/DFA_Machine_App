#ifndef TRANSITIONMANAGER_H
#define TRANSITIONMANAGER_H
#include "Transition.h"
#include <set>

using std::set;

class TransitionManager{
private:
    set<Transition> transition_table;

    void add_transitions(const set<State>& states, const set<char>& characters);
public:
    TransitionManager(const set<State>& states, const set<char>& characters);

    State get_next_state(const State& cur_state, const char& cur_char) const;
};


#endif