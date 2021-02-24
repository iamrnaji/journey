#include <iostream>
#include "node.h"
using namespace std;

Node::Node()
{
	m_next = nullptr;
	m_prev = nullptr;
	
}

Node::Node(const ListItemType& item)
{
	m_next = nullptr;
	m_prev = nullptr;
	m_item = item;
}

Node::Node(const ListItemType& item, Node* nextNodePtr, Node* prevNodePtr)
{
	m_next = nextNodePtr;
	m_prev = prevNodePtr;
	m_item = item;
}

void Node::SetItem(const ListItemType& item)
{
	m_item = item;
}

void Node::SetNext(Node* nextNodePtr)
{
	m_next = nextNodePtr;
}

void Node::SetPrev(Node* prevNodePtr)
{
	m_prev = prevNodePtr;
}

ListItemType Node::GetItem() const
{
	return m_item;
}

Node* Node::GetNext() const
{
	return m_next;
}

Node* Node::GetPrev() const
{
	return m_prev;
}
