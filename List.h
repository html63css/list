#pragma once
#include "Element.h"
#include <iostream>

struct List
{
public:
	void remove(Element*);
	void add(Element&, Element* = nullptr);
	void closure();
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