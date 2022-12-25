#include "DFAApp.h"
#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::string;

void DFAApp::print_instructions() const {
    cout<<"\nTo construct a DFA machine you must specify:";
    cout<<"\n1.the set of states including the start state and final state(s).";
    cout<<"\n2.the complete alphabet.";
    cout<<"\n3.the complete transition function.\n";
}

void DFAApp::DFA_menu(const DFAMachine &dfa) const {
    while (true){
        cout << "\n\n- To process a new string enter 1, To quit enter 2: ";
        
        int option;
        cin >> option;

        if (option == 2)
            return;

        cout<<"\nEnter the string to be processed: ";
        string str;
        cin>>str;

        if (dfa.is_accepted_string(str))
            cout<<"\nThis string is Accepted\n";
        else
            cout<<"\nThis string is Rejected\n";
    }
}

void DFAApp::start() {
    while (true){
        cout << "\n\n- To create a new DFA machine enter 1, To end the program enter 2: ";
		
        int option;
        cin >> option;
		
        if (option == 2)
            return;

        print_instructions();

        DFAMachine dfa = DFAMachine();
        DFA_menu(dfa);
    }
}
