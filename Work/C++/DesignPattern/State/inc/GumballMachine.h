#ifndef _GUMBALLMACHINE_H_
#define _GUMBALLMACHINE_H_

#include <iostream>
#include "../inc/State.h"

using namespace std;

//Estados possiveis 
enum {
	SOLD_OUT = 0,
	NO_QUARTER,
	HAS_QUARTER,
	SOLD,
};

class GumballMachine{
	public:
	int count;
	int state;
	GumballMachine(int count);
	void Status();
};

#endif