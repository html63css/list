#include "Element.h"

Element::Element(int number)
{
	date_.date = number;
	next_ = nullptr;
}

//void Element::setDate(int date)
//{
//	date_ = date;
//}
//
int Element::getDate()
{
	return date_.date;
}

void Element::setNext(Element* link)
{
	next_ = link;
}
Element* Element::getNext()
{
	return next_;
}