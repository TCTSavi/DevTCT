#include "../inc/State.h"

class GumballMachine;

//Estados possiveis 
enum {
	SOLD_OUT = 0,
	NO_QUARTER,
	HAS_QUARTER,
	SOLD,
};

int state = SOLD_OUT;

//Não necessariamente preciso atender toda e qualquer ação a depender do estado
//Uma ação possivel
void insertQuarter(int 	state){
	switch (state){
		case SOLD_OUT:{
			cout << "you cant insert another quarter ,the machine is sold out" << endl;
		}	
		break;
		case NO_QUARTER:{
			state = HAS_QUARTER;
			cout << "You inserted a quarter" << endl;
		}	
		break;
		case HAS_QUARTER:{
			cout << "You cant insert another quarter" << endl;
		}	
		break;
		case SOLD:{
			cout << "Please wait, we are already giving you a gumball" << endl;
		}	
		break;
		default:
			cout << "Fatal error!" << endl;			
		break;
	}
}

void ejectQuarter(int state){
	switch (state){
		case SOLD_OUT:{
			cout << "You cant eject ,you havent insert a quarter yet" << endl;
		}	
		break;
		case NO_QUARTER:{
			cout << "You havent inserted a quarter" << endl;
		}	
		break;
		case HAS_QUARTER:{
			state = NO_QUARTER;
			cout << "Quarter returned" << endl;
		}	
		break;
		case SOLD:{
			cout << "Sorry ,you already turned the crank" << endl;
		}	
		break;
		default:
			cout << "Fatal error!" << endl;			
		break;
	}
}

void turnCrank(int state){
	switch (state){
		case SOLD_OUT:{
			cout << "You cant eject ,you havent insert a quarter yet" << endl;
		}	
		break;
		case NO_QUARTER:{
			cout << "You havent inserted a quarter" << endl;
		}	
		break;
		case HAS_QUARTER:{
			state = NO_QUARTER;
			cout << "Quarter returned" << endl;
		}	
		break;
		case SOLD:{
			cout << "Sorry ,you already turned the crank" << endl;
		}	
		break;
		default:
			cout << "Fatal error!" << endl;			
		break;
	}
}

void dispense(int state){
	switch (state){
		case SOLD_OUT:{
			cout << "No gumball dispensed" << endl;
		}	
		break;
		case NO_QUARTER:{
			cout << "Plese insert a quarter" << endl;
		}	
		break;
		case HAS_QUARTER:{
			state = NO_QUARTER;
			cout << "No gumball dispensed" << endl;
		}	
		break;
		case SOLD:{
			cout << "Here is your gumball" << endl;
		}	
		break;
		default:
			cout << "Fatal error!" << endl;			
		break;
	}
}