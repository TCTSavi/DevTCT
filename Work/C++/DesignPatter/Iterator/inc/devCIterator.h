#ifndef	_DEVCITERATOR_H_
#define	_DEVCITERATOR_H_

#include <vector>
#include <list>
#include <map>
#include <iostream>

template <class item>
class Iterator{
public:
	virtual void First() =0;
	virtual void Next() =0;
	virtual bool IsDone() =0;
	virtual item GetCurrent() = 0;
};

template <class item>
class VectorIterator:public Iterator<item>{
public:
	VectorIterator( std::vector<item>* Container ){
		this->Container = Container;
		Current = 0;
	}
	void First(){
		Current = 0;
	}
	void Next(){
		Current++;
	}
	bool IsDone(){
		return Current >= Container->size();
	}
	item GetCurrent(){
		if (IsDone()){
		}
		return	(*Container)[Current];
	}
private:
	std::vector<item>* Container;
	long Current;		
};

template <class item>
class Container{
public:
	virtual Iterator<item>* CreateIterator() =0;
};

#endif
