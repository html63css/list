#include "Element.h"

Element::~Element()
{
	std::cout << "Удаление элемента\n"; // Для проверки корректности работы деструктора
	delete next_;
}


Element::Element(int number)
{
	date_ = number;
	next_ = nullptr;
}

void Element::setDate(int date)
{
	date_ = date;
}

int Element::getDate()
{
	return date_;
}

void Element::setNext(Element* link)
{
	next_ = link;
}
Element* Element::getNext()
{
	return next_;
}