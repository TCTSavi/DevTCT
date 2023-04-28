#ifndef _STATE_H_
#define _STATE_H_

#include <iostream>
using namespace std;

class GumballMachine;

class State{
	public:
	virtual void insertQuarter(GumballMachine* gumMach) =0;
	virtual void ejectQuarter(GumballMachine* gumMach) =0;
	virtual void turnCrank(GumballMachine* gumMach) =0;
	virtual void dispense(GumballMachine* gumMach) =0;
	virtual void print()=0;
};

class SoldState:public State{
	public:
	static State* instance();
	void insertQuarter(GumballMachine* gumMach);
	void ejectQuarter(GumballMachine* gumMach);
	void turnCrank(GumballMachine* gumMach);
	void dispense(GumballMachine* gumMach);
	void print();
};

class SoldOutState:public State{
	public:
	static State* instance();
	void insertQuarter(GumballMachine* gumMach);
	void ejectQuarter(GumballMachine* gumMach);
	void turnCrank(GumballMachine* gumMach);
	void dispense(GumballMachine* gumMach);
	void print();
};

class NoQuarterState:public State{
	public:
	static State* instance();
	void insertQuarter(GumballMachine* gumMach);
	void ejectQuarter(GumballMachine* gumMach);
	void turnCrank(GumballMachine* gumMach);
	void dispense(GumballMachine* gumMach);
	void print();
};

class HasQuarterState:public State{
	public:
	static State* instance();
	void insertQuarter(GumballMachine* gumMach);
	void ejectQuarter(GumballMachine* gumMach);
	void turnCrank(GumballMachine* gumMach);
	void dispense(GumballMachine* gumMach);
	void print();
};

class WinnerState:public State{
	public:
	static State* instance();
	void insertQuarter(GumballMachine* gumMach);
	void ejectQuarter(GumballMachine* gumMach);
	void turnCrank(GumballMachine* gumMach);
	void dispense(GumballMachine* gumMach);
	void print();
};


#endif