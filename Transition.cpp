#include "Transition.h"

Transition::Transition(const State& _cur_state, const char& _cur_char, const State& _next_state)
                    : cur_state(_cur_state), cur_char(_cur_char), next_state(_next_state){}

State Transition::get_next_state() const {
    return this->next_state;
}

bool Transition::operator<(const Transition &transition2) const {
    if (this->cur_state == transition2.cur_state)
        return this->cur_char < transition2.cur_char;
    
    return this->cur_state < transition2.cur_state;
}

bool Transition::operator==(const Transition &transition2) const
{
    return this->cur_state == transition2.cur_state && this->cur_char == transition2.cur_char;
}
