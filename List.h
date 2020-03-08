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
	List();
	Element* head_;
	Element* end_;
private:
	int count_;
	bool isRing_;
	Element* bufferAdd_;
};