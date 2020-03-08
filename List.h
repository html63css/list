#pragma once
#include <iostream>
#include "Element.h"
extern struct List
{
public:
	void remove(Element*);
	void add(int, Element* = nullptr); //Добавляем элемент ПОСЛЕ указаного
	void closure(Element*);
	void disjunction(Element*);
	List();
private:
	int count_;
	bool isRing_;
	Element* head_;
	Element* end_;
	Element* bufferAdd_;
};