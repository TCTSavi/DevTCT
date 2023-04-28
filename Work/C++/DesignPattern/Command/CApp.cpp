#include "CApp.h"

//Receptor
class GarageDoor{
	public:
	void Up(){
		cout<<"Subindo a porta!"<<endl;
	}
	void Down(){
		cout<<"Abaixanto da porta!"<<endl;
	}
	void Stop(){
		cout<<"Parou a porta!"<<endl;
	}
};

//Receptor
class Light{
	private:
	bool State;
	public:
	Light(){
		State = false;
	}
	void On(){
		State = true;
		cout<<"Luz acessa!"<<endl;
	}
	void Off(){
		State = false;
		cout<<"Luz apagada!"<<endl;
	}
};

//Receptor
class Stereo{
	private:
	public:
	void On(){
		cout<<"Stereo ligado!"<<endl;
	}
	void Off(){
		cout<<"Stereo desligado!"<<endl;
	}
	void SetCD(){
		cout<<"Tocando CD"<<endl;
	}
	void SetRadio(){
		cout<<"Tocando CD"<<endl;
	}
	void SetVolume(int volume){
		cout<<"Ajustando volume em "<< volume <<" "<<endl;
	}
};

//Interface
class Command {
	public:
	virtual void execute()=0;
	virtual void undo()=0;
};

//Comando concreto
class LightOnCommand:public Command{
	public:
	Light *light;

	LightOnCommand(Light *light){
		this->light=light;
	}

	void execute(){
		light->On();
	}

	void undo(){
		light->Off();
	}
};

//Comando concreto
class LightOffCommand:public Command{
	public:
	Light *light;

	LightOffCommand(Light *light){
		this->light=light;
	}

	void execute(){
		light->Off();
	}

	void undo(){
		light->On();
	}

};

//Comando concreto
class GarageDoorOpenCommand:public Command{
	public:
	GarageDoor *garagedoor;

	GarageDoorOpenCommand(GarageDoor *garagedoor){
		this->garagedoor=garagedoor;
	}

	void execute(){
		garagedoor->Up();
	}

	void undo(){
		garagedoor->Down();
	}

};

//Comando concreto
class GarageDoorCloseCommand:public Command{
	public:
	GarageDoor *garagedoor;

	GarageDoorCloseCommand(GarageDoor *garagedoor){
		this->garagedoor=garagedoor;
	}

	void execute(){
		garagedoor->Down();
	}

	void undo(){
		garagedoor->Up();
	}

};

//Comando concreto
class StereoOnWithCDCommand:public Command{
	public:
	Stereo *stereo;

	StereoOnWithCDCommand(Stereo *stereo){
		this->stereo=stereo;
	}

	void execute(){
		stereo->On();
		stereo->SetCD();
		stereo->SetVolume(10);
	}

	void undo(){
		stereo->Off();
	}

};

//Comando concreto
//Nos comandos concretos poderiamos gerenciar(armazenar) estados mais complexos.
class StereoOffCommand:public Command{
	public:
	Stereo *stereo;

	StereoOffCommand(Stereo *stereo){
		this->stereo=stereo;
	}

	void execute(){
		stereo->Off();
	}

	void undo(){
		stereo->On();
		stereo->SetCD();
		stereo->SetVolume(10);
	}

};

//Comando concreto
class NoCommand:public Command{
	public:

	void execute(){
		cout<<"Comando nulo!"<< endl;
	}

	void undo(){
		cout<<"Comando nulo!"<< endl;
	}
};

class MacroCommand:public Command{
	private:
	Command **commands;

	public:
	MacroCommand(Command **commands){
		this->commands = commands;
	}

	void execute(){
		cout<<"Executando uma Macro:"<< endl;
		for (int i = 0; commands[i] ;i++){
			commands[i]->execute();
		}
	}

	void undo(){
		cout<<"Executando uma Macro:"<< endl;
		for (int i = 0; commands[i] ;i++){
			commands[i]->undo();
		}
	}
};


//Invocador
class RemoteControl{
	private:
	Command *onCommands[7];
	Command *offCommands[7];
	Command *noCommand;
	Command *undoCommand;

	public:
	RemoteControl(){
		noCommand = new NoCommand;
		undoCommand = noCommand;
		for(int i=0;i<7;i++){
			onCommands[i] = noCommand;
			offCommands[i] = noCommand;
		}
	}
	void SetCommand(int slot,Command *onCommand,Command *offCommand){
		onCommands[slot]=onCommand;
		offCommands[slot]=offCommand;
	}
	void onbuttonWasPressed(int slot){
		onCommands[slot]->execute();
		undoCommand = onCommands[slot];
	}
	void offbuttonWasPressed(int slot){
		offCommands[slot]->execute();
		undoCommand = offCommands[slot];
	}
	void undobuttonWasPressed(){
		undoCommand->undo();
	}
};

//Cliente
int main(){
	RemoteControl *remote = new RemoteControl;
	Light *light = new Light;
	GarageDoor *garageDoor = new GarageDoor;
	Stereo *stereo = new Stereo;
	
	LightOnCommand *lightOn = new LightOnCommand(light);
	LightOffCommand *lightOff = new LightOffCommand(light);
	GarageDoorOpenCommand *garageDoorOpen = new GarageDoorOpenCommand(garageDoor);
	GarageDoorCloseCommand *garageDoorClose = new GarageDoorCloseCommand(garageDoor);
	StereoOnWithCDCommand *stereoOnWithCD = new StereoOnWithCDCommand(stereo);
	StereoOffCommand *stereoOff = new StereoOffCommand(stereo);

	Command *partyOn[] = {lightOn,garageDoorOpen,stereoOnWithCD,NULL};
	Command *partyOff[] = {lightOff,garageDoorClose,stereoOff,NULL};

	MacroCommand *partyMacroOn = new MacroCommand(partyOn);
	MacroCommand *partyMacroOff = new MacroCommand(partyOff);

	//int c = 0;
	//for ( c; partyOn[c] != NULL ;c++){
	//}
	//cout << "Comandos da Macro: " << c << endl;

	remote->SetCommand(0,lightOn,lightOff);
	remote->SetCommand(1,garageDoorOpen,garageDoorClose);
	remote->SetCommand(2,stereoOnWithCD,stereoOff);
	remote->SetCommand(3,partyMacroOn,partyMacroOff);

//Testando o controle
	remote->onbuttonWasPressed(0);
	remote->undobuttonWasPressed();
	remote->offbuttonWasPressed(0);
	remote->onbuttonWasPressed(1);
	remote->offbuttonWasPressed(1);
	remote->onbuttonWasPressed(2);
	remote->undobuttonWasPressed();
	remote->offbuttonWasPressed(2);
	cout<<endl;
	remote->onbuttonWasPressed(3);
	remote->offbuttonWasPressed(3);
	remote->undobuttonWasPressed();
	return 0;
}