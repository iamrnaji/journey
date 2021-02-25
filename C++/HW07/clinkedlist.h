#pragma once

#include "node.h"

#ifndef CLinkedLIST_HEADER
#define CLinkedLIST_HEADER

class CLinkedList
{
public:
	CLinkedList();
	~CLinkedList();

	bool DestroyList();
	bool GetItem(int index, ListItemType& item) const;
	int GetCurrentSize() const;
	bool Add(const ListItemType& newItem);
	bool IsEmpty() const;
	bool Remove(const ListItemType& value);
	bool Clear();
	bool Contains(const ListItemType& item) const;
	void DisplayListAscending();
	void DisplayListDescending();

private:
	Node* headPtr;
	Node* tailPtr;

	char NewItemLocation(const ListItemType& newItem);
	bool AddInFront(const ListItemType& newItem);
	bool AddInEnd(const ListItemType& newItem);
	bool AddInMiddle(const ListItemType& newItem);

};

#endif
