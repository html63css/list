#include "List.h"

List::List()
{
	count_ = 0;
	isRing_ = false;
	end_ = nullptr;
	head_ = nullptr;
	bufferAdd_ = nullptr;
}

void List::add(int number, Element* base) // Проверить: достаточно ли объявления параметра по умолчанию в его интерфейсе (? = nullptr)
{

	if (isRing_ == true)
	{
		std::cout << "Нельзя производит добавление в цепи \n";
		return;
	}


	Element element(number);
	if (head_ == nullptr)
	{
		head_ = &element;
		end_ = &element;
		std::cout << "Добавлен первый элемент списка!\n";
	}
	else
	{
		if (base == nullptr)
		{
			head_ = &element;
			std::cout << "Добавление в начало списка\n";
		}
		if (end_ == base)
		{
			end_ = &element;
			std::cout << "Добавление в конец списка\n";

		}
		bufferAdd_ = base->getNext();
		base->setNext(&element);
		element.setNext(bufferAdd_); // Возможна ошибка!
		bufferAdd_ = nullptr;
	}
	++count_;
	std::cout << "Элемент добавлен\t Количество элементов списка:" << count_ ;
}

void List::remove(Element* base)
{

	if (isRing_ == true)
	{
		std::cout << "Нельзя производит удаление в цепи \n";
		return;
	}

	if (base == head_ && base != end_)
	{
		head_ = head_->getNext();
		delete base;
		std::cout << "Удаление первого элемента\n";
	}
	else if (base != head_ && base == end_)
	{
		Element* I = head_;
		while (I->getNext() != end_)
		{
			I = I->getNext();
		}
		end_ = I;
		delete I;
		delete base;
		std::cout << "Удаление последнего элемента\n";

	}
	else if (base == head_ && base == end_)
	{
		head_ = nullptr;
		end_ = nullptr;
		delete base;
		std::cout << "Удаление единственного элемента\n";
	}
	else
	{
		Element* I = head_;
		while (I->getNext() != base)
		{
			I = I->getNext();
		}
		I->setNext(base->getNext());
		delete base;
		std::cout << "Удаление элемента\n";
	}
	--count_;
	std::cout << "Новый размер спика:\n" << count_;
}

void List::closure(Element* base)
{
	if (base != end_)
	{
		std::cout << "Ошибка. Эта функция выполняется только для последнего элемента";
	}
	if (isRing_ != false)
	{
		std::cout << "Ошибка. Список уже является цепью\n";
	}
	if (count_ < 1)
	{
		std::cout << "Ошибка. Нельзя сделать цепь из списка с 1 элементом\n";
	}
	if (isRing_ == false && base == end_ && count_ > 1)
	{
		base->setNext(head_);
		isRing_ = true;
		std::cout << "Список превращён в цепь\n";
	}
}

void List::disjunction(Element* base)	//Разрыв правой связи
{
	if (isRing_ == false)
	{
		std::cout << "Ошибка. Список не является цепью\n";
	}
	else
	{
		head_ = base->getNext();
		end_ = base;
		base->setNext(nullptr);
		std::cout << "Цепь разорвана\n";
	}
}