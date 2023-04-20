#ifndef	_COMPOSITEITERATOR_H_
#define	_COMPOSITEITERATOR_H_

//Extern library
#include <iostream>
#include <stack>
//Main library
#include "../../../mainLib/inc/devCIterator.h"
//#include "MenuItem.h"
//Work library

using namespace std;

template <class item>
class CompositeIterator:public Iterator<item>{
	private:
	stack<Iterator<item>*> *cstack;
	Iterator<item>* it;
	Iterator<item>* first;
	public:
	CompositeIterator(Iterator<item>* it){
		cstack = new stack<Iterator<item>*>;
		cstack->push(it);
		Iterator<item>* first = it;;
	}
	void First(){
		delete cstack;
		cstack->push(first);
	}
	void Next(){
		if( IsDone() ){
		}
		else{
			Iterator<item> *it = cstack->top();
			item _item = it->GetCurrent();
			if ( _item->getComponent() ){
				cstack->push( _item->CreateIterator() );
			}
			it->Next();
		} 	
	}
	bool IsDone(){
		if (cstack->empty()){
			return	true;
		}
		else{
			Iterator<item> *it = cstack->top();
			if( it->IsDone() ){
				cstack->pop();
				return	IsDone();
			}
			else{
				return false;
			}
		}
	}
	item GetCurrent(){
		if (IsDone()){
			return NULL;
		}
		else{
			Iterator<item> *it = cstack->top();
			return	it->GetCurrent();
		}
	}
};

#endif