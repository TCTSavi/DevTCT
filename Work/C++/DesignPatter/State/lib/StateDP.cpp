#include "../inc/StateDP.h"
#include "../inc/GumballMachineDP.h"

State* State::state = nullptr;

void HasQuarterState::insertQuarter(GumballMachine* gumMach){
	cout << "You cant insert another quarter" << endl;
}
void HasQuarterState::ejectQuarter(GumballMachine* gumMach){
	cout << "Quarter returned" << endl;
	gumMach->setState( NoQuarterState::instance() );
}
void HasQuarterState::turnCrank(GumballMachine* gumMach){
	cout << "You turned..." << endl;
	gumMach->setState( SoldState::instance() );
}
void HasQuarterState::dispense(GumballMachine* gumMach){
	cout << "No gumball dispensed" << endl;
	gumMach->setState( NoQuarterState::instance() ); 
}
State* HasQuarterState::instance(){
	state = new HasQuarterState();
	return state;
}
void HasQuarterState::print(){
	cout << "HasQuarterState" << endl <<"    ";
}


void SoldState::insertQuarter(GumballMachine* gumMach){
	cout << "Please wait, we are already giving you a gumball" << endl;
}
void SoldState::ejectQuarter(GumballMachine* gumMach){
	cout << "Sorry ,you already turned the crank" << endl;
}
void SoldState::turnCrank(GumballMachine* gumMach){
	cout << "Turning twice doesnt get you another gumball" << endl;
}
void SoldState::dispense(GumballMachine* gumMach){
	cout << "Here is your gumball" << endl;
	gumMach->count -=1;
	if (gumMach->count == 0){
		cout << "Oops, out of gumballs" << endl;	
		gumMach->setState( SoldOutState::instance() );
	}
	else{
		gumMach->setState( NoQuarterState::instance() );
	}
}
State* SoldState::instance(){
	state = new SoldState();
	return state;
}
void SoldState::print(){
	cout << "SoldState" << endl <<"    ";
}



void SoldOutState::insertQuarter(GumballMachine* gumMach){
	cout << "you cant insert another quarter ,the machine is sold out" << endl;
}
void SoldOutState::ejectQuarter(GumballMachine* gumMach){
	cout << "You cant eject ,you havent insert a quarter yet" << endl;
}
void SoldOutState::turnCrank(GumballMachine* gumMach){
	cout << "You turned, but there are no gumballs" << endl;
}
void SoldOutState::dispense(GumballMachine* gumMach){
	cout << "No gumball dispensed" << endl;
}
State* SoldOutState::instance(){
	state = new SoldOutState();
	return state;
}
void SoldOutState::print(){
	cout << "SoldOutState" << endl <<"    ";
}


void NoQuarterState::insertQuarter(GumballMachine* gumMach){
	cout << "You inserted a quarter" << endl;
	gumMach->setState( HasQuarterState::instance() );
}
void NoQuarterState::ejectQuarter(GumballMachine* gumMach){
	cout << "You havent inserted a quarter" << endl;
}
void NoQuarterState::turnCrank(GumballMachine* gumMach){
	cout << "You havent inserted a quarter" << endl;
}
void NoQuarterState::dispense(GumballMachine* gumMach){
	cout << "You need to pay first" << endl;
}
State* NoQuarterState::instance(){
	state = new NoQuarterState();
	return state;
}
void NoQuarterState::print(){
	cout << "NoQuarterState" << endl <<"    ";
}

/*
//Não necessariamente preciso atender toda e qualquer ação a depender do estado
//Uma ação possivel
void insertQuarter( GumballMachine *GM ){
	switch (GM->state){
		case SOLD_OUT:{
			cout << "you cant insert another quarter ,the machine is sold out" << endl;
		}	
		break;
		case NO_QUARTER:{
			GM->state = HAS_QUARTER;
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

void ejectQuarter(GumballMachine *GM){
	switch (GM->state){
		case SOLD_OUT:{
			cout << "You cant eject ,you havent insert a quarter yet" << endl;
		}	
		break;
		case NO_QUARTER:{
			cout << "You havent inserted a quarter" << endl;
		}	
		break;
		case HAS_QUARTER:{
			GM->state = NO_QUARTER;
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

void turnCrank(GumballMachine *GM){
	switch (GM->state){
		case SOLD_OUT:{
			cout << "You turned, but there are no gumballs" << endl;
		}	
		break;
		case NO_QUARTER:{
			cout << "You havent inserted a quarter" << endl;
		}	
		break;
		case HAS_QUARTER:{
			GM->state = SOLD;
			cout << "You turned..." << endl;
			dispense(GM);
		}	
		break;
		case SOLD:{
			cout << "Turning twice doesnt get you another gumball" << endl;
		}	
		break;
		default:
			cout << "Fatal error!" << endl;			
		break;
	}
}

void dispense(GumballMachine *GM){
	switch (GM->state){
		case SOLD_OUT:{
			cout << "No gumball dispensed" << endl;
		}	
		break;
		case NO_QUARTER:{
			cout << "You need to pay first" << endl;
		}	
		break;
		case HAS_QUARTER:{
			GM->state = NO_QUARTER;
			cout << "No gumball dispensed" << endl;
		}	
		break;
		case SOLD:{
			cout << "Here is your gumball" << endl;
			GM->count -=1;
			if (GM->count == 0){
				cout << "Oops, out of gumballs" << endl;	
				GM->state = SOLD_OUT;
			}
			else{
				GM->state = NO_QUARTER;
			}
		}	
		break;
		default:
			cout << "Fatal error!" << endl;			
		break;
	}
}
*/
