#include "List.h"

List::List()
{
	count_ = 0;
	isRing_ = false;
	end_ = nullptr;
	head_ = nullptr;
	bufferAdd_ = nullptr;
}

List::~List()
{
	Element* Iterator = head_;
	Element* destBuffer;
	std::cout << "\nДеструктор списка";
	std::cout << "\n head = " << head_->getDate() <<" : [" << head_ << "] \t end = " << end_->getDate() << " :[" << end_ << "]";
	while (Iterator != end_)
	{
		std::cout << "\nИтерация деструктора";
		destBuffer = Iterator;
		Iterator = Iterator->getNext();
		std::cout << "\nУдаление элемента со значением: " << destBuffer->getDate() << "\n";
		delete destBuffer;
	}
	std::cout << "\nКонец работы деструктора";
	//delete Iterator;
}

void List::add(int number, Element* base) // Проверить: достаточно ли объявления параметра по умолчанию в его интерфейсе (? = nullptr)
{

	if (isRing_ == true)
	{
		std::cout << "\nНельзя производит добавление в цепи \n";
		return;
	}


	Element element(number);
	if (head_ == nullptr)
	{
		head_ = &element;
		end_ = &element;
		std::cout << "\nБудет добавлен первый элемент списка!\n";
	}
	else
	{
		if (base == end_)
		{
			end_ = &element;
			std::cout << "\nБудет добавление в конец списка\n";
		}

		if (base != nullptr)
		{
			bufferAdd_ = base->getNext();
			base->setNext(&element);
			element.setNext(bufferAdd_); // Возможна ошибка!
			bufferAdd_ = nullptr;
		}
		else
		{
			std::cout << "\nБудет добавление в начало списка\n";
			element.setNext(head_);
			head_ = &element;
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
		delete I;
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
		std::cout << "\nЦепь разорвана\n";
	}
}