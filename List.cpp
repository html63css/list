#include "List.h"

List::List()
{
	count_ = 0;
	isRing_ = false;
	end_ = nullptr;
	head_ = nullptr;
	bufferAdd_ = nullptr;
}

void List::add(Element& element, Element* base) // Проверить: достаточно ли объявления параметра по умолчанию в его интерфейсе (? = nullptr)
{

	if (isRing_ == true)
	{
		std::cout << "\nНельзя производит добавление в цепи \n";
		return;
	}
	if (count_ == 0)
	{
		head_ = &element;
		end_ = &element;
	}
	else if (base == nullptr)
	{
		element.setNext(head_);
		head_ = &element;
	}
	else
	{
		bufferAdd_ = base->getNext();
		base->setNext(&element);
		element.setNext(bufferAdd_);
		bufferAdd_ = nullptr;
		if (base == end_)
		{
			end_ = &element;
		}
	}
	++count_;
	std::cout << "\nЭлемент добавлен\t Количество элементов списка:" << count_ << "\n";
	std::cout << "Адрес данного элемента: "<< &element << "\t Значение данного элемента:"<< element.getDate() <<"\n";
}

void List::remove(Element* base)
{

	if (isRing_ == true)
	{
		std::cout << "\nНельзя производит удаление в цепи \n";
		return;
	}

	if (base == head_ && base != end_)
	{
		head_ = head_->getNext();
		delete base;
		std::cout << "\nУдаление первого элемента\n";
	}
	else if (base != head_ && base == end_)
	{
		Element* I = head_;
		while (I->getNext() != end_)
		{
			I = I->getNext();
		}
		end_ = I;
		delete base;
		std::cout << "\nУдаление последнего элемента\n";

	}
	else if (base == head_ && base == end_)
	{
		head_ = nullptr;
		end_ = nullptr;
		delete base;
		std::cout << "\nУдаление единственного элемента\n";
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
		std::cout << "\nУдаление элемента\n";
	}
	--count_;
	std::cout << "\nНовый размер спика:\n" << count_;
}

void List::closure(Element* base)
{
	if (base != end_)
	{
		std::cout << "\nОшибка. Эта функция выполняется только для последнего элемента\n";
	}
	if (isRing_ != false)
	{
		std::cout << "\nОшибка. Список уже является цепью\n";
	}
	if (count_ < 1)
	{
		std::cout << "\nОшибка. Нельзя сделать цепь из списка с 1 элементом\n";
	}
	if (isRing_ == false && base == end_ && count_ > 1)
	{
		base->setNext(head_);
		isRing_ = true;
		std::cout << "\nСписок превращён в цепь\n";
	}
}

void List::disjunction(Element* base)	//Разрыв правой связи
{
	if (isRing_ == false)
	{
		std::cout << "\nОшибка. Список не является цепью\n";
	}
	else
	{
		head_ = base->getNext();
		end_ = base;
		base->setNext(nullptr);
		isRing_ = false;
		std::cout << "\nЦепь разорвана\n";
	}
}

int List::length()
{
	return count_;
}

Element* List::getHead()
{
	return head_;
}

Element* List::getEnd()
{
	return end_;
}
