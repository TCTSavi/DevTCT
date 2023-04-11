#include "Capp.h"

int main(){
	Menu* LousMenu = new PancakeHouseMenu;
	vector <Menu*> Menus;
	Menus.push_back(LousMenu);
	Menus.push_back(LousMenu);
	Menus.push_back(LousMenu);
	Alice Ali01(&Menus);
	Ali01.printMenu();
	return 0;
}
