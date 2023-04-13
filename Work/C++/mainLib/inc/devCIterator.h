#ifndef	_DEVCITERATOR_H_
#define	_DEVCITERATOR_H_

#include <vector>
#include <list>
#include <map>

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
		it = Container->begin();
	}
	void First(){
		it = Container->begin();
	}
	void Next(){
		it++;
	}
	bool IsDone(){
		return it == Container->end();
	}
	item GetCurrent(){
		if (IsDone()){
		}
		return	*it;
	}
private:
	std::vector<item>* Container;
	typename std::vector<item>::iterator it;
	long Current;		
};

template <class item>
class ListIterator:public Iterator<item>{
public:
	ListIterator( std::list<item>* Container ){
		this->Container = Container;
		it = Container->begin();
	}
	void First(){
		it = Container->begin();
	}
	void Next(){
		it++;
	}
	bool IsDone(){
		return it == Container->end();
	}
	item GetCurrent(){
		if (IsDone()){
		}
		return	*it;
	}
private:
	std::list<item>* Container;
	typename std::list<item>::iterator it;
	long Current;		
};

template <class key,class item>
class MapIterator:public Iterator<item>{
public:
	MapIterator( std::map<key,item>* Container ){
		this->Container = Container;
		it = Container->begin();
	}
	void First(){
		it = Container->begin();
	}
	void Next(){
		it++;
	}
	bool IsDone(){
		return it == Container->end();
	}
	item GetCurrent(){
		if (IsDone()){
		}
		return	(*it).second;
	}
private:
	std::map<key,item>* Container;
	typename std::map<key,item>::iterator it;
	long Current;		
};

template <class item>
class ArrayIterator:public Iterator<item>{
public:
	ArrayIterator( item* Container ){
		this->Container = Container;
		it = 0;
	}
	void First(){
		it = 0;
	}
	void Next(){
		it++;
	}
	bool IsDone(){
		if (!Container[it]){
			return true;
		}
		else{
			return false;
		}
	}
	item GetCurrent(){
		if (IsDone()){
		}
		return	Container[it];
	}
private:
	item* Container;
	int it;
	long Current;		
};

template <class item>
class Container{
public:
	virtual Iterator<item>* CreateIterator() =0;
};

#endif
