#pragma once
typedef union
{
	int date;
	char* std;
}int_std;

struct Element{
public:
	int getDate();
	void setNext(Element*);
	Element* getNext();
	Element(int);
private:
	int_std date_;
	Element* next_;
};