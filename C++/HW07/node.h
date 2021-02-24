#pragma once

#ifndef NODE_HEADER
#define NODE_HEADER

typedef int ListItemType;

class Node
{
public:
	Node();
	Node(const ListItemType& item);
	Node(const ListItemType& item, Node* nextNodePtr, Node* prevNodePtr);

	void SetItem(const ListItemType& item);
	void SetNext(Node* nextNodePtr);
	void SetPrev(Node* prevNodePtr);
	ListItemType GetItem() const;
	Node* GetNext() const;
	Node* GetPrev() const;

private:
	ListItemType m_item;
	Node* m_next;
	Node* m_prev;
};

#endif
