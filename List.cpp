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

	//if (isRing_ == true)
	//{
	//	std::cout << "\nНельзя производит добавление в цепи \n";
	//	return;
	//}
	if (count_ == 0)
	{
		head_ = &element;
		end_ = &element;
	}
	else if (base == nullptr)
	{
		element.setNext(head_);
		head_ = &element;
		end_->setNext(&element);
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
			end_->setNext(head_);
		}
	}
	++count_;
	std::cout << "\nЭлемент добавлен\t Количество элементов списка:" << count_ << "\n";
}

void List::remove(Element* base)
{

	if (isRing_ == true && count_ == 2 )
	{
		std::cout << "\nОшибка удаления в цепи \n";
		return;
	}

	if (base == head_ && base != end_)
	{
		head_ = head_->getNext();
		if (isRing_ == true)
		{
			end_->setNext(head_);
			std::cout << "\nЦЕПЬ\n";
		}
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
		if (isRing_ == true)
		{
			I->setNext(head_);
			std::cout << "\nЦЕПЬ\n";
		}
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

void List::closure()
{
	if (isRing_ != false)
	{
		std::cout << "\nОшибка. Список уже является цепью\n";
	}
	if (count_ <= 1)
	{
		std::cout << "\nОшибка. Нельзя сделать цепь из списка с 1 или 0 элементом\n";
	}
	if (isRing_ == false && count_ > 1)
	{
		end_->setNext(head_);
		isRing_ = true;
		//end_ = head_ = nullptr;
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
