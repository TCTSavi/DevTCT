#include "Capp.h"

int main(){
	GumballMachine *gm = new GumballMachine(5);
	gm->Status();

	insertQuarter(gm);
	turnCrank(gm);

	gm->Status();

	insertQuarter(gm);
	ejectQuarter(gm);
	turnCrank(gm);
	
	gm->Status();

	insertQuarter(gm);
	turnCrank(gm);
	insertQuarter(gm);
	turnCrank(gm);
	ejectQuarter(gm);

	gm->Status();

	insertQuarter(gm);
	insertQuarter(gm);
	turnCrank(gm);
	insertQuarter(gm);
	turnCrank(gm);
	insertQuarter(gm);
	turnCrank(gm);

	gm->Status();
		
	return 0;
}
