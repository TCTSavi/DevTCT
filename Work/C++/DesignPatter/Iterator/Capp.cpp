#include "Capp.h"

int main(){
	Menu *MelsMenu = new DinerMenu;
	Menu* LousMenu = new PancakeHouseMenu;
	vector <Menu*> Menus;
	Menus.push_back(LousMenu);
	Menus.push_back(MelsMenu);
	Alice Ali01(&Menus);
	Ali01.printMenu();
	return 0;
}
