#ifndef STATE_H
#define STATE_H
#include <string>

using std::string;

class State{
private:
	string id;
	bool start_state;
	bool accept_state;
public:
	State(const string& id, const bool& is_start = false, const bool& is_final = false);
	
    bool is_start_state() const;
	
    bool is_accept_state() const;

	string get_id() const;

	bool operator <(const State& state2) const;

	bool operator ==(const State& state2) const;
};

#endif