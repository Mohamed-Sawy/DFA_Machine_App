#include "State.h"

State::State(const string& id, const bool& is_start, const bool& is_final)
        : id(id), start_state(is_start), accept_state(is_final){}

bool State::is_start_state() const{
    return this->start_state;
}

bool State::is_accept_state() const{
    return this->accept_state;
}

string State::get_id() const
{
    return this->id;
}

bool State::operator <(const State& state2) const{
    return this->id < state2.id;
}

bool State::operator ==(const State &state2) const {
    return this->id == state2.id;
}
