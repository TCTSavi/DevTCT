#ifndef _GUMBALLMACHINE_H_
#define _GUMBALLMACHINE_H_

#include <iostream>
#include "../inc/StateDP.h"

using namespace std;

class State;

class GumballMachine{
	private:
	State *state;
	public:
	friend class State;
	GumballMachine(int count);
	int count;
	void insertQuarter();
	void ejectQuarter();
	void turnCrank();
	void setState(State* state);
	void releaseball();
	void Status();
	State* getNoQuarterState();
};

#endif