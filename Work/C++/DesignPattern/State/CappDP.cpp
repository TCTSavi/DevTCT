#include "CappDP.h"

int main(){
	
	GumballMachine *gm = new GumballMachine(5);

	gm->Status();
	gm->insertQuarter();
	gm->turnCrank();

	gm->Status();

	gm->insertQuarter();
	gm->ejectQuarter();
	gm->turnCrank();
	
	gm->Status();

	gm->insertQuarter();
	gm->turnCrank();
	gm->insertQuarter();
	gm->turnCrank();
	gm->ejectQuarter();

	gm->Status();

	gm->insertQuarter();
	gm->insertQuarter();
	gm->turnCrank();
	gm->insertQuarter();
	gm->turnCrank();
	gm->insertQuarter();
	gm->turnCrank();

	gm->Status();

	return 0;
}
