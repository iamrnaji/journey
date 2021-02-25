

#include <iostream>
#include "clinkedlist.h"
using namespace std;

CLinkedList::CLinkedList()
{
	headPtr = nullptr;
	tailPtr = nullptr;
}

CLinkedList::~CLinkedList()
{
	DestroyList();
}

bool CLinkedList::DestroyList()
{
	Node* p = headPtr;
	Node* n;

	while (p != nullptr)
	{
		n = p->GetNext();

		delete p;

		p = n;
	}

	headPtr = nullptr;
	tailPtr = nullptr;

	delete headPtr;
	delete tailPtr;

	if (this->IsEmpty())
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool CLinkedList::GetItem(int index, ListItemType& item) const
{
	Node* p = headPtr;
	for (int i = 0; i < index; i++)
	{
		p = p->GetNext();
	}
	item = p->GetItem();
	
	if (item == p->GetItem())
	{
		return true;
	}
	else
	{
		return false;
	}
}


//CAREFUL!! THIS IS OUT OF ORDER!!

int CLinkedList::GetCurrentSize() const
{
	Node* p = headPtr;
	int count = 0;

	while (p != nullptr)
	{
		count++;
		p = p->GetNext();
	}

	return count;

}


bool CLinkedList::Contains(const ListItemType& item) const
{
	Node* p = headPtr;

	while (p != nullptr)
	{
		if (p->GetItem() == item)
		{
			return true;
		}

		p = p->GetNext();
		
	}

	return false;
}

bool CLinkedList::AddInFront(const ListItemType& newItem)
{
	Node* p = new Node;

	p->SetItem(newItem);
	p->SetNext(headPtr);

	if (p->GetNext() != nullptr)
	{
		Node* j = p->GetNext();
		j->SetPrev(p);
	}

	headPtr = p;

	return true;
}

bool CLinkedList::AddInEnd(const ListItemType& newItem)
{
	if (headPtr == nullptr)
	{
		AddInFront(newItem);
		return true;
	}

	Node* p = new Node;
	
	p->SetNext(headPtr);

	while (p->GetNext() != nullptr)
	{
		p = p->GetNext();
		
	}

	Node* n = new Node;

	p->SetNext(n);

	n->SetItem(newItem);

	n->SetPrev(p);

	n->SetNext(nullptr);

	tailPtr = n;

	

	return true;
}

bool CLinkedList::AddInMiddle(const ListItemType& newItem)
{
	Node* p = headPtr;

	while (p != nullptr)
	{
		if (p->GetItem() > newItem)
		{
			break;
		}

		p = p->GetNext();

		if (p == nullptr)
		{
			AddInEnd(newItem);
			return true;
		}
	}

	Node* n = new Node(newItem, p->GetNext(), p);

	p->SetNext(n);

	return true;
}

bool CLinkedList::Add(const ListItemType& newItem)
{
	if (headPtr == nullptr || newItem < headPtr->GetItem())
	{
		AddInFront(newItem);
	}
	else if (AddInMiddle(newItem))
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool CLinkedList::IsEmpty() const
{
	if (headPtr == nullptr)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool CLinkedList::Remove(const ListItemType& value)
{

	if (headPtr == nullptr)
	{
		return false;
	}

	if (headPtr->GetItem() == value)
	{
		Node* target = headPtr;

		headPtr = headPtr->GetNext();

		delete target;

		return true;
	}

	Node* p = headPtr;

	while (p->GetNext() != nullptr)
	{
		if (p->GetNext() != nullptr && p->GetNext()->GetItem() == value)
		{
			break;
		}

		if (p == tailPtr && p->GetItem() != value)
		{
			return false;
		}

		p = p->GetNext();
	}

	if (p->GetNext() != nullptr)
	{
		Node* target = p->GetNext();
		if (target == tailPtr)
		{
			tailPtr = p;
		}
		

		if (target->GetNext() != nullptr)
		{
			Node* next = target->GetNext();
			next->SetPrev(p);
		}
		
		p->SetNext(target->GetNext());

		delete target;

		return true;

	}

	return false;

	
}

void CLinkedList::DisplayListAscending()
{
	Node* p = headPtr;
	while (p != nullptr)
	{
		cout << p->GetItem() << endl;
		p = p->GetNext();
		
	}
	cout << endl << endl;
}

void CLinkedList::DisplayListDescending()
{
	Node* p = tailPtr;
	while (p != nullptr)
	{
		cout << p->GetItem() << endl;
		if (GetCurrentSize() == 1)
		{
			break;
		}

		p = p->GetPrev();
		
	}
	cout << endl << endl;
}


char CLinkedList::NewItemLocation(const ListItemType& newItem)
{
	Node* p = headPtr;

	if (headPtr == nullptr)
	{
		return 'F';
	}

	while (p->GetNext() != nullptr)
	{
		if (p->GetItem() > newItem)
		{
			if (tailPtr == p)
			{
				return 'E';
			}
			else
			{
				return 'M';
			}
		}

		p = p->GetNext();
	}
}

bool CLinkedList::Clear()
{
	Node* p = headPtr;

	Node* n;

	while (p != nullptr)
	{
		n = p->GetNext();

		delete p;

		p = n;
	}

	tailPtr = nullptr;
	headPtr = nullptr;

	return true;
}
