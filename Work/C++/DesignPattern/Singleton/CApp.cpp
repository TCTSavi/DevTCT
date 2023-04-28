#include "CApp.h"

class Singleton{
	private:
	static Singleton *uniqueInstance;
	private:
	Singleton(){}
	public:
	static Singleton* getInstance(){
		if (uniqueInstance == NULL){
			uniqueInstance = new Singleton;
		}
	return	uniqueInstance;		
	}
};
Singleton* Singleton::uniqueInstance =0;

int main(){
	return 0;
}