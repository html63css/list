#include "List.h"

int main()
{
	setlocale(0, "");
	List list;
	Element* a1 = new Element(1);
	list.add(*a1);
	Element* a2 = new Element(2);
	list.add(*a2);
	Element a3(3);
	list.add(a3);
	Element a4(4);
	list.add(a4);
	return 0;
}