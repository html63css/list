#include "List.h"
#include <conio.h>
#define KEY_DOWN 80
#define KEY_REMOVE 8
#define KEY_ADD 13
#define KEY_END 27
#define KEY_CLOSURE 9
#define KEY_DISJUNCTION 32
#pragma warning (default : 4996)

int main()
{
	setlocale(0, "");
	List list;
	Element* element;
	Element* I;
	Element* positionElement = nullptr;
	Element* bufferDel = nullptr;
	char ch(0);
	int position(0);
	int buff(0);
	int size(0);
	std::cout << "Ââåäèòå íà÷àëüíûé ðàçìåð ñïèñêà\n";
	std::cin >> size;
	if (size <= 0) exit(0);
	for (int i = 0 ; i < size ; ++i)
	{
		std::cout << "\nÂâåäèòå ÷èñëî\n";
		std::cin >> buff;
		element = new Element(buff);
		list.add(*element);
	}
	do
	{
		system("cls");
		std::cout << "ÑÒÐÅËÊÀ ÂÍÈÇ - ÄÂÈÆÅÍÈÅ ÏÎ ÑÏÈÑÊÓ ÂÍÈÇ(ÄÂÈÆÅÍÈÅ ÂÂÅÐÕ ÍÅÂÎÇÌÎÆÍÎ, Ò.Ê. ÑÏÈÑÎÊ ÎÄÍÎÑÂßÇÍÛÉ)\n";
		std::cout << "ÄÎÁÀÂÈÒÜ ÝËÅÌÅÍÒ ÏÎÑËÅ ÓÊÀÇÀÒÅËß - ENTER\n";
		std::cout << "ÓÄÀËÈÒÜ ÝËÅÌÅÍÒ ÝËÅÌÅÍÒ, ÍÀ ÊÎÒÎÐÎÌ ÑÒÎÈÒ ÓÊÀÇÀÒÅËÜ - BACKSPACE\n";
		std::cout << "ÏÐÅÂÐÀÒÈÒÜ ÑÏÈÑÎÊ Â ÖÅÏÜ - TAB\n";
		std::cout << "(ÏÐÅÂÐÀÒÈÒÜ Â ÖÅÏÜ ÌÎÆÍÎ ÒÎËÜÊÎ ÑÏÈÑÎÊ Ñ ÍÀÁÎÐÎÌ ÈÇ 2-Õ È ÁÎËÅÅ ÝËÅÌÅÍÒÎÂ)\n";
		std::cout << "ÐÀÇÎÐÂÀÒÜ ÖÅÏÜ - SPACE\n";
		std::cout << "(ÏÐÈ ÐÀÇÐÛÂÅ ÖÅÏÈ ÝËÅÌÅÍÒ ÐÀÇÐÛÂÀ ÑÒÀÍÎÂÈÒÑß ÏÎÑËÅÄÍÈÌ Â ÑÏÈÑÊÅ)\n";
		std::cout << "ÂÛÉÒÈ ÈÇ ÏÐÎÃÐÀÌÌÛ - ESC\n";
		if (ch >= 0)
		{
			I = list.getHead();
			if (position == 0) std::cout << "\t\t<--";
			std::cout << "\n";
			for (int i = 1; i <= list.length(); ++i)
			{
				std::cout << "\t" << I->getDate();
				if (position == i) std::cout << "\t<--";
				std::cout << "\n";
				I = I->getNext();
			}
		}
		do
		{
			ch = getch();
		} while (ch != KEY_DOWN && ch != KEY_ADD && ch != KEY_REMOVE && ch != KEY_DISJUNCTION && ch != KEY_CLOSURE && ch != KEY_END);
		switch (ch)
		{
		case (KEY_DOWN):
			if (position == list.length())
			{
				position = 0;
				positionElement = nullptr;
			}
			else
			{
				++position;
				if (position == 1)
				{
					positionElement = list.getHead();
				}
				else
				{
					positionElement = positionElement->getNext();
				}
			}
			break;
		case(KEY_ADD):
			system("cls");
			std::cout << "Ââåäèòå ÷èñëî \n";
			std::cin >> buff;
			element = new Element(buff);
			list.add(*element,positionElement);
			break;
		case(KEY_REMOVE):
 			if (position != 0)
			{
				if (position == list.length())
				{
					position = 0;
					list.remove(positionElement);
					positionElement = nullptr;
				}
				else
				{
					bufferDel = positionElement->getNext();
					list.remove(positionElement);
					positionElement = bufferDel;
				}
			}
			break;
		case(KEY_CLOSURE):
			list.closure();
			getch();
			break;
		case(KEY_DISJUNCTION):
			if (positionElement != nullptr)
			{
				list.disjunction(positionElement);
				position = 0;
				positionElement = nullptr;
			}
			getch();
			break;
		}
	} while (ch != KEY_END);

	return 0;
}