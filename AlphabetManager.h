#ifndef ALPHABETMANAGER_H
#define ALPHABETMANAGER_H
#include <set>

using std::set;

class AlphabetManager{
private:
    set<char> characters;

    void add_alphabet();

    int menu() const;
public:
    AlphabetManager();

    bool is_valid_character(const char& ch) const;

    set<char> get_alphabet() const;
};

#endif