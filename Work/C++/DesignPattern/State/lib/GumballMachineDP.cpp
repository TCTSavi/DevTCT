#include "../inc/GumballMachineDP.h"

GumballMachine::GumballMachine(int count){
	state = SoldOutState::instance();
	this->count = count;

	if ( count > 0 ){
		state = NoQuarterState::instance();
	}
}

void GumballMachine::insertQuarter(){
	state->insertQuarter(this);
}
void GumballMachine::ejectQuarter(){
	state->ejectQuarter(this);
}
void GumballMachine::turnCrank(){
	state->turnCrank(this);
	state->dispense(this);
}
void GumballMachine::releaseball(){
	cout << "A gumball comes rolling out the slot..." << endl;
	if (count != 0){
		count -=1;
	}
}

void GumballMachine::Status(){
	cout << " Machine status: " << endl <<"    ";
	state->print();
	cout << "count: " << count << endl << endl;
}

void GumballMachine::setState(State* state){
	this->state = state;
}
