#pragma once
#include <iostream>
#include "Element.h"

struct List
{
public:
	void remove(Element*);
	void add(Element&, Element* = nullptr); //Добавляем элемент ПОСЛЕ указаного
	void closure(Element*);
	void disjunction(Element*);
	int length();
	Element* getHead();
	Element* getEnd();
	List();
private:
	int count_;
	bool isRing_;
	Element* head_;
	Element* end_;
	Element* bufferAdd_;
};