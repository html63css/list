#include "List.h"

List::List()
{
	count_ = 0;
	isRing_ = false;
	end_ = nullptr;
	head_ = nullptr;
	bufferAdd_ = nullptr;
}

void List::add(int number, Element* base) // ���������: ���������� �� ���������� ��������� �� ��������� � ��� ���������� (? = nullptr)
{

	if (isRing_ == true)
	{
		std::cout << "������ ���������� ���������� � ���� \n";
		return;
	}


	Element element(number);
	if (head_ == nullptr)
	{
		head_ = &element;
		end_ = &element;
		std::cout << "�������� ������ ������� ������!\n";
	}
	else
	{
		if (base == nullptr)
		{
			head_ = &element;
			std::cout << "���������� � ������ ������\n";
		}
		if (end_ == base)
		{
			end_ = &element;
			std::cout << "���������� � ����� ������\n";

		}
		bufferAdd_ = base->getNext();
		base->setNext(&element);
		element.setNext(bufferAdd_); // �������� ������!
		bufferAdd_ = nullptr;
	}
	++count_;
	std::cout << "������� ��������\t ���������� ��������� ������:" << count_ ;
}

void List::remove(Element* base)
{

	if (isRing_ == true)
	{
		std::cout << "������ ���������� �������� � ���� \n";
		return;
	}

	if (base == head_ && base != end_)
	{
		head_ = head_->getNext();
		delete base;
		std::cout << "�������� ������� ��������\n";
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
		std::cout << "�������� ���������� ��������\n";

	}
	else if (base == head_ && base == end_)
	{
		head_ = nullptr;
		end_ = nullptr;
		delete base;
		std::cout << "�������� ������������� ��������\n";
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
		std::cout << "�������� ��������\n";
	}
	--count_;
	std::cout << "����� ������ �����:\n" << count_;
}

void List::closure(Element* base)
{
	if (base != end_)
	{
		std::cout << "������. ��� ������� ����������� ������ ��� ���������� ��������";
	}
	if (isRing_ != false)
	{
		std::cout << "������. ������ ��� �������� �����\n";
	}
	if (count_ < 1)
	{
		std::cout << "������. ������ ������� ���� �� ������ � 1 ���������\n";
	}
	if (isRing_ == false && base == end_ && count_ > 1)
	{
		base->setNext(head_);
		isRing_ = true;
		std::cout << "������ ��������� � ����\n";
	}
}

void List::disjunction(Element* base)	//������ ������ �����
{
	if (isRing_ == false)
	{
		std::cout << "������. ������ �� �������� �����\n";
	}
	else
	{
		head_ = base->getNext();
		end_ = base;
		base->setNext(nullptr);
		std::cout << "���� ���������\n";
	}
}