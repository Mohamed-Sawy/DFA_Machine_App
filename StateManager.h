#ifndef STATEMANAGER_H
#define STATEMANAGER_H
#include "State.h"
#include <string>
#include <set>

using std::string;
using std::set;


class StateManager {
private:
	set<State> states;
	
	void add_states();

    int menu() const;

	bool is_valid_states() const;

	bool is_valid_start() const;

	bool is_valid_accept() const;
public:
    StateManager();

	State get_start_state() const;	

	set<State> get_states() const;
};

#endif