#ifndef _STATE_H_
#define _STATE_H_

#include <iostream>
using namespace std;

class GumballMachine;

void insertQuarter( GumballMachine *GM );
void ejectQuarter(GumballMachine *GM);
void turnCrank(GumballMachine *GM);
void dispense(GumballMachine *GM);

/*
class State{
	public:

	virtual void insertQuarter() =0;
	virtual void ejectQuarter() =0;
	virtual void turnCrank() =0;
	virtual void dispense() =0;
};

class SoldState:public State{
	public:
	void insertQuarter();
	void ejectQuarter();
	void turnCrank();
	void dispense();
};

class SoldOutState:public State{
	public:
	void insertQuarter();
	void ejectQuarter();
	void turnCrank();
	void dispense();
};

class NoQuarterState:public State{
	public:
	void insertQuarter() =0;
	void ejectQuarter() =0;
	void turnCrank() =0;
	void dispense() =0;
};

class HasQuarterState:public State{
	public:
	void insertQuarter() =0;
	void ejectQuarter() =0;
	void turnCrank() =0;
	void dispense() =0;
};

class WinnerState:public State{
	public:
	void insertQuarter() =0;
	void ejectQuarter() =0;
	void turnCrank() =0;
	void dispense() =0;
};
*/

#endif