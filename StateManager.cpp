#include "StateManager.h"
#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::string;

StateManager::StateManager(){
    this->add_states();
}

void StateManager::add_states() {
	while (true) {
        int option = this->menu();
		if (option == 2){
            if (this->is_valid_states())
                break;
            else{
                cout<<"\nYou must have no more than 1 start state and at least 1 final state.\nEnter the states again.\n\n";
                this->states.clear();
                continue;
            }
        }

        string id;
        bool is_start;
        bool is_accept;

		cout << "\nEnter state id (Note: state id must be unique): ";
		cin >> id;
		cout << "\nIf it's a start state enter 1 else enter 0: ";
		cin >> is_start;
		cout << "\nIf it's an accept state enter 1 else enter 0: ";
		cin >> is_accept;

		this->states.insert(State(id, is_start, is_accept));
	}
}

int StateManager::menu() const {
	cout << "\n\n- To add a state enter 1, To end enter 2: ";
		
    int option;
    cin >> option;
		
    return option;
}
    
bool StateManager::is_valid_states() const{
    return this->is_valid_start() && this->is_valid_accept();
}

bool StateManager::is_valid_start() const{
	int num_of_start_state = 0;
    for (const State& state : this->states)
        if (state.is_start_state())
            num_of_start_state++;

    return num_of_start_state == 1;
}

bool StateManager::is_valid_accept() const{
	int num_of_accept_state = 0;
    for (const State& state : this->states)
        if (state.is_accept_state())
            num_of_accept_state++;
            
    return num_of_accept_state > 0;
}

State StateManager::get_start_state() const{
	for (const State& state : this->states)
        if (state.is_start_state())
            return state;
}

set<State> StateManager::get_states() const{
    return this->states;
}
