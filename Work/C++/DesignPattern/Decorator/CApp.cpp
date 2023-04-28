#include "CApp.h"

class Bebida{
	public:
		static vector<Bebida*> ListBeb;
		Bebida(){
			ListBeb.push_back(this);
		}

		virtual string getDescription(){
			return "Bebida indefinida";
		}
		virtual float getCost(){
			return 0;
		}	
};
vector<Bebida*> Bebida::ListBeb;

class Chocolate:public Bebida{
	public:
		string getDescription(){
			return "Chocolate";
		}
		float getCost(){
			return 1.5;
		}	
};

class Cafe:public Bebida{
	public:
		string getDescription(){
			return "Cafe";
		}
		float getCost(){
			return 1.2;
		}	
};

class Capuccino:public Bebida{
	public:
		string getDescription(){
			return "Capuccino";
		}
		float getCost(){
			return 1.7;
		}	
};

class Mocha:public Bebida{
	public:
		string getDescription(){
			return "Mocha";
		}
		float getCost(){
			return 2.3;
		}	
};

class Decorator:public Bebida{
	protected:
		Bebida *Beb_;
	public:
		Decorator(Bebida *Beb):Beb_(Beb){
		}

		virtual string getDescription(){
			return Beb_->getDescription();
		}

		virtual float getCost(){
			return Beb_->getCost();
		}

};

class Leite:public Decorator{
	public:
		Leite(Bebida *Beb):Decorator(Beb){
		}

		virtual string getDescription(){
			return (Beb_->getDescription())+", Leite";
		}

		virtual float getCost(){
			return (Beb_->getCost())+ 1.15;
		}
};

class Creme:public Decorator{
	public:
		Creme(Bebida *Beb):Decorator(Beb){
		}

		virtual string getDescription(){
			return (Beb_->getDescription())+", Creme";
		}

		virtual float getCost(){
			return (Beb_->getCost())+ 0.5;
		}
};

class Doce:public Decorator{
	public:
		Doce(Bebida *Beb):Decorator(Beb){
		}

		virtual string getDescription(){
			return (Beb_->getDescription())+", Doce de leite";
		}

		virtual float getCost(){
			return (Beb_->getCost())+ 2;
		}
};


int main(){
	Bebida *Beb1 = new Chocolate;
	Bebida *Beb2 = new Capuccino;
	Bebida *Beb3 = new Mocha;
	Bebida *Beb4 = new Cafe;
	Beb4 = new Leite(Beb4);
	Beb4 = new Doce(Beb4);
	Beb3 = new Leite(Beb3);
	Beb3 = new Leite(Beb3);
	Beb1 = new Creme(Beb1);

	for (int i = 0;i < Bebida::ListBeb.size();i++){
		cout<<"Suas bebibas são:"<< Bebida::ListBeb[i]->getDescription() << " Custando:" << Bebida::ListBeb[i]->getCost() << endl;
	}
	return 0;
}