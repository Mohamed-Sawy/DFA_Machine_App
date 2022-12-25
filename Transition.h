#ifndef TRANSITION_H
#define TRANSITION_H
#include "State.h"

class Transition{
private:
    State cur_state;
    char cur_char;
    State next_state;
public:
    Transition(const State& _cur_state, const char& _cur_char, const State& _next_state = State(""));

    State get_next_state() const;

    bool operator <(const Transition& transition2) const;
    
    bool operator ==(const Transition& transition2) const;
};

#endif