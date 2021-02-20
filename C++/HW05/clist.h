#pragma once


#ifndef DYNAMIC_CLIST_HEADER
#define DYNAMIC_CLIST_HEADER

typedef int ListItemType;

const int MAX_ITEMS = 5;

class CList
{
public:
	CList();
	~CList();

	bool Clear();
	bool GetItem(int index, ListItemType& item) const;
	int GetCapacity() const;
	int GetCurrentSize() const;
	bool Add(const ListItemType& newItem);
	bool IsEmpty() const;
	bool IsFull() const;
	bool Remove(const ListItemType& value);
	bool SetCapacity(int num);
	bool DestroyList();
	


	CList& operator=(const CList& rhs);

private:
	int m_capacity;
	int m_numItems;
	ListItemType* m_items;

	bool CloseItemGap(int index);
	int CopyList(const CList& otherList);
	bool ItemExists(int& index, const ListItemType& item);
};

#endif
