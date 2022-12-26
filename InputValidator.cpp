#include "InputValidator.h"
#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::string;

int InputValidator::read_int() {
    int num;
    do{
        cin>>num;
    }while(!valid_input());

    return num;
}

string InputValidator::read_string() {
    string str;
    do{
        cin>>str;
    }while(!valid_input());

    return str;
}

char InputValidator::read_char() {
    char ch;
    do{
        cin>>ch;
    }while(!valid_input());

    cin.ignore(10000, '\n');
    return ch;
}

bool InputValidator::valid_input() {
    if (cin.fail()){
        cin.clear();
        cin.ignore(10000, '\n');
        cout<<"\n**Invalid input please try again: ";
        return false;
    }

    return true;
}
