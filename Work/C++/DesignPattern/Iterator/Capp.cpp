#include "Capp.h"

int main(){
	Menu *MelsMenu = new DinerMenu;
	Menu* LousMenu = new PancakeHouseMenu;
	Menu *cafeMenu = new CafeMenu;
	vector <Menu*> Menus;
	Menus.push_back(LousMenu);
	Menus.push_back(MelsMenu);
	Menus.push_back(cafeMenu);	
	Alice Ali01(&Menus);
	Ali01.printMenu();
	return 0;
}
