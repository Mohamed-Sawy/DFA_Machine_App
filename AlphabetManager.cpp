#include "AlphabetManager.h"
#include <iostream>
#include "InputValidator.h"

using std::cout;

AlphabetManager::AlphabetManager() {
    this->add_alphabet();
}

void AlphabetManager::add_alphabet() {
    	while (true) {
        int option = this->menu();
		if (option == 2)
            break;

		cout << "\nEnter a valid character of the DFA machine: ";
        char character = InputValidator::read_char();

		this->characters.insert(character);
	}
}

int AlphabetManager::menu() const {
    cout << "\n\nTo add a character enter 1, To end enter 2: ";

    int option = InputValidator::read_int();
    while (option != 1 && option != 2){
        cout<<"\nPlease enter a valid option [1, 2]: ";
        option = InputValidator::read_int();
    }

    return option;
}

bool AlphabetManager::is_valid_character(const char &ch) const {
    return this->characters.find(ch) != this->characters.end();
}

set<char> AlphabetManager::get_alphabet() const {
    return this->characters;
}
