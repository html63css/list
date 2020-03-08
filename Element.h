#pragma once
#include <iostream>

struct Element{
public:
	void setDate(int);
	int getDate();
	void setNext(Element*);
	Element* getNext();
	Element(int);
	~Element();
private:
	int date_;
	Element* next_;
};