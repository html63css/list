#include "List.h"

List::List()
{
	count_ = 0;
	isRing_ = false;
	end_ = nullptr;
	head_ = nullptr;
	bufferAdd_ = nullptr;
}

void List::add(Element& element, Element* base) // ���������: ���������� �� ���������� ��������� �� ��������� � ��� ���������� (? = nullptr)
{

	if (isRing_ == true)
	{
		std::cout << "\n������ ���������� ���������� � ���� \n";
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
	std::cout << "\n������� ��������\t ���������� ��������� ������:" << count_ << "\n";
	std::cout << "����� ������� ��������: "<< &element << "\t �������� ������� ��������:"<< element.getDate() <<"\n";
}

void List::remove(Element* base)
{

	if (isRing_ == true)
	{
		std::cout << "\n������ ���������� �������� � ���� \n";
		return;
	}

	if (base == head_ && base != end_)
	{
		head_ = head_->getNext();
		delete base;
		std::cout << "\n�������� ������� ��������\n";
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
		std::cout << "\n�������� ���������� ��������\n";

	}
	else if (base == head_ && base == end_)
	{
		head_ = nullptr;
		end_ = nullptr;
		delete base;
		std::cout << "\n�������� ������������� ��������\n";
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
		std::cout << "\n�������� ��������\n";
	}
	--count_;
	std::cout << "\n����� ������ �����:\n" << count_;
}

void List::closure(Element* base)
{
	if (base != end_)
	{
		std::cout << "\n������. ��� ������� ����������� ������ ��� ���������� ��������\n";
	}
	if (isRing_ != false)
	{
		std::cout << "\n������. ������ ��� �������� �����\n";
	}
	if (count_ < 1)
	{
		std::cout << "\n������. ������ ������� ���� �� ������ � 1 ���������\n";
	}
	if (isRing_ == false && base == end_ && count_ > 1)
	{
		base->setNext(head_);
		isRing_ = true;
		std::cout << "\n������ ��������� � ����\n";
	}
}

void List::disjunction(Element* base)	//������ ������ �����
{
	if (isRing_ == false)
	{
		std::cout << "\n������. ������ �� �������� �����\n";
	}
	else
	{
		head_ = base->getNext();
		end_ = base;
		base->setNext(nullptr);
		isRing_ = false;
		std::cout << "\n���� ���������\n";
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
