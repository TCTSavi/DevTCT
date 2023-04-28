#include "CApp.h"

enum {
	CHEESE = 0,
	GREEK,
	PEPPERONI,
};

class Pizza{
	public:
		virtual void prepare()=0;
		virtual void bake()=0;
		virtual void cut()=0;
		virtual void box()=0;
};

class NYStyleCheesePizza:public Pizza{
		void prepare(){
			cout <<"Prepara NYStyle CheesePizza"<<endl;
		}
		void bake(){
			cout <<"Cozinha NYStyle CheesePizza"<<endl;
		}
		void cut(){
			cout <<"Corta NYStyle CheesePizza"<<endl;
		}
		void box(){
			cout <<"Embala NYStyle CheesePizza"<<endl;
		}
};

class NYStyleGreekPizza:public Pizza{
		void prepare(){
			cout <<"Prepara NYStyle GreekPizza"<<endl;
		}
		void bake(){
			cout <<"Cozinha NYStyle GreekPizza"<<endl;
		}
		void cut(){
			cout <<"Corta NYStyle GreekPizza"<<endl;
		}
		void box(){
			cout <<"Embala NYStyle GreekPizza"<<endl;
		}
};

class NYStylePepperoniPizza:public Pizza{
		void prepare(){
			cout <<"Prepara NYStyle PepperoniPizza"<<endl;
		}
		void bake(){
			cout <<"Cozinha NYStyle PepperoniPizza"<<endl;
		}
		void cut(){
			cout <<"Corta NYStyle PepperoniPizza"<<endl;
		}
		void box(){
			cout <<"Embala NYStyle PepperoniPizza"<<endl;
		}
};

class ChicagoStyleCheesePizza:public Pizza{
		void prepare(){
			cout <<"Prepara Chicago CheesePizza"<<endl;
		}
		void bake(){
			cout <<"Cozinha Chicago CheesePizza"<<endl;
		}
		void cut(){
			cout <<"Corta Chicago CheesePizza"<<endl;
		}
		void box(){
			cout <<"Embala Chicago CheesePizza"<<endl;
		}
};

class ChicagoStyleGreekPizza:public Pizza{
		void prepare(){
			cout <<"Prepara Chicago GreekPizza"<<endl;
		}
		void bake(){
			cout <<"Cozinha Chicago GreekPizza"<<endl;
		}
		void cut(){
			cout <<"Corta Chicago GreekPizza"<<endl;
		}
		void box(){
			cout <<"Embala Chicago GreekPizza"<<endl;
		}
};

class ChicagoStylePepperoniPizza:public Pizza{
		void prepare(){
			cout <<"Prepara Chicago PepperoniPizza"<<endl;
		}
		void bake(){
			cout <<"Cozinha Chicago PepperoniPizza"<<endl;
		}
		void cut(){
			cout <<"Corta Chicago PepperoniPizza"<<endl;
		}
		void box(){
			cout <<"Embala Chicago PepperoniPizza"<<endl;
		}
};

class PizzaStore{
	public:
		virtual Pizza* CreatePizza(int type) =0;
	public:
		Pizza* OrderPizza(int type){
			Pizza *pizza = NULL;
			pizza = CreatePizza(type);
			pizza->prepare();
			pizza->bake();
			pizza->cut();
			pizza->box();
			return pizza;
		}
};

class ChicagoStyle:public PizzaStore{
	public:
	Pizza* CreatePizza(int type){
		Pizza *pizza =NULL;
		switch (type){
			case CHEESE:
				pizza = new ChicagoStyleCheesePizza();
			break;
			case GREEK:
				pizza = new ChicagoStyleGreekPizza();
			break;
			case PEPPERONI:
				pizza = new ChicagoStylePepperoniPizza();
			break;
			default:
			break;
		}
		return pizza;
	}	
};

class NyStoreStyle:public PizzaStore{
	public:
	Pizza* CreatePizza(int type){
		Pizza *pizza =NULL;
		switch (type){
			case CHEESE:
				pizza = new NYStyleCheesePizza();
			break;
			case GREEK:
				pizza = new NYStyleGreekPizza();
			break;
			case PEPPERONI:
				pizza = new NYStylePepperoniPizza();
			break;
			default:
			break;
		}
	return pizza;
	}
};

int main(){
	PizzaStore *Store = new ChicagoStyle;
	Pizza *pizza = NULL;
	pizza = Store->OrderPizza(CHEESE);
	return 0;
}