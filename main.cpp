#include "List.h"

int main()
{
	setlocale(0, "");
	List list;
	Element a1(1);
	list.add(a1);
	Element a2(2);
	list.add(a2);
	Element a3(3);
	list.add(a3);
	Element a4(4);
	list.add(a4,&a1);
	system("cls");
	Element* I = list.head_;
	while (I != list.end_)
	{
		std::cout << I->getDate() << "\n";
		I = I->getNext();
	}
	std::cout << I->getDate() << "\n";

	return 0;
}