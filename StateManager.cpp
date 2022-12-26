#include "StateManager.h"
#include "InputValidator.h"
#include <iostream>
#include <string>

using std::cout;
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

		cout << "\nEnter state id (Note: state id must be unique): ";
        string id = InputValidator::read_string();

		cout << "\nIf it's a start state enter 1 else enter 0: ";
        bool is_start = InputValidator::read_int();

		cout << "\nIf it's an accept state enter 1 else enter 0: ";
        bool is_accept = InputValidator::read_int();

		this->states.insert(State(id, is_start, is_accept));
	}
}

int StateManager::menu() const {
	cout << "\n\n- To add a state enter 1, To end enter 2: ";

    int option = InputValidator::read_int();
    while (option != 1 && option != 2){
        cout<<"\nPlease enter a valid option [1, 2]: ";
        option = InputValidator::read_int();
    }
		
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
