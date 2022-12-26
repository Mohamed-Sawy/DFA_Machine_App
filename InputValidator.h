#ifndef INPUTVALIDATOR_H
#define INPUTVALIDATOR_H
#include <string>

using std::string;

class InputValidator {
private:
    static bool valid_input();
public:
    InputValidator() = delete;

    static int read_int();

    static string read_string();

    static char read_char();
};


#endif
