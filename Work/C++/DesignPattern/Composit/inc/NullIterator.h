#ifndef	_NULLITERATOR_H_
#define	_NULLITERATOR_H_

//Extern library
#include <iostream>
//Main library
#include "../../../mainLib/inc/devCIterator.h"
//Work library

using namespace std;

template <class item>
class NullIterator:public Iterator<item>{
	public:
	void First(){
	}
	void Next(){
	}
	bool IsDone(){
		return true;
	}
	item GetCurrent(){
		return NULL;
	}
};

#endif
