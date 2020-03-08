#include "List.h"

int main()
{
	setlocale(0, "");
	List list;
	Element* a1;
	Element* I;
	system("cls");
	do
	{
		I = list.getHead();
		for (int i = 0; i < list.length(); ++i)
		{
			std::cout << I->getDate() << "\n";
			I = I->getNext();
		}
	} while (1);

	return 0;
}