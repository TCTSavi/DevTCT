#include "../inc/GumballMachine.h"

GumballMachine::GumballMachine(int count){
	this->count = count;
	state = SOLD_OUT;
	if ( count > 0 ){
		state = NO_QUARTER;
	}
}

void GumballMachine::Status(){
	cout << " Machine status: " << endl <<"    ";
	switch (state){
		case SOLD_OUT:cout << "SOLD_OUT";break;
		case NO_QUARTER:cout << "NO_QUARTER";break;
		case HAS_QUARTER:cout << "HAS_QUARTER";break;
		case SOLD:cout << "SOLD";break;
		default:break;
	}
	cout << endl <<"    ";
	cout << "count: " << count << endl << endl;
}