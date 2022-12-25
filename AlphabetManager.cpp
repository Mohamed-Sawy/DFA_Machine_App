#include "AlphabetManager.h"
#include <iostream>

using std::cout;
using std::cin;

AlphabetManager::AlphabetManager() {
    this->add_alphabet();
}

void AlphabetManager::add_alphabet() {
    	while (true) {
        int option = this->menu();
		if (option == 2)
            break;

        char character;

		cout << "\nEnter a valid character of the DFA machine: ";
		cin >> character;

		this->characters.insert(character);
	}
}

int AlphabetManager::menu() const {
    cout << "\n\nTo add a character enter 1, To end enter 2: ";

    int option;
    cin >> option;

    return option;
}

bool AlphabetManager::is_valid_character(const char &ch) const {
    return this->characters.find(ch) != this->characters.end();
}

set<char> AlphabetManager::get_alphabet() const {
    return this->characters;
}
