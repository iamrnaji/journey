#pragma once

#ifndef CBINARY_NODE_HEADER
#define CBINARY_NODE_HEADER

template<class ItemType>
class CBinaryNode
{
public:
	CBinaryNode();
	CBinaryNode(const ItemType& item);
	CBinaryNode(const ItemType& item, CBinaryNode<ItemType>* leftChildPtr, CBinaryNode<ItemType>* rightChildPtr);
	void SetItem(const ItemType& item);
	ItemType GetItem() const;
	bool IsLeaf() const;
	CBinaryNode<ItemType>* GetLeftChildPtr() const;
	CBinaryNode<ItemType>* GetRightChildPtr() const;
	void SetLeftChildPtr(CBinaryNode<ItemType>* leftChildPtr);
	void SetRightChildPtr(CBinaryNode<ItemType>* rightChildPtr);

private:

	ItemType m_item;
	CBinaryNode<ItemType>* m_leftChildPtr;
	CBinaryNode<ItemType>* m_rightChildPtr;
};


template <class ItemType>
CBinaryNode<ItemType>::CBinaryNode()
{
	m_leftChildPtr = nullptr;
	m_rightChildPtr = nullptr;
}

template <class ItemType>
CBinaryNode<ItemType>::CBinaryNode(const ItemType& item)
{
	m_leftChildPtr = nullptr;
	m_rightChildPtr = nullptr;
	m_item = item;
}

template <class ItemType>
CBinaryNode<ItemType>::CBinaryNode(const ItemType& item, CBinaryNode<ItemType>* leftChildPtr, CBinaryNode<ItemType>* rightChildPtr)
{
	m_leftChildPtr = leftChildPtr;
	m_rightChildPtr = rightChildPtr;
	m_item = item;
}

template <class ItemType>
void CBinaryNode<ItemType>::SetItem(const ItemType& item)
{
	m_item = item;
}

template <class ItemType>
ItemType CBinaryNode<ItemType>::GetItem() const
{
	return m_item;
}

template <class ItemType>
bool CBinaryNode<ItemType>::IsLeaf() const
{
	if (m_leftChildPtr == nullptr && m_rightChildPtr == nullptr)
	{
		return true;
	}
	else
	{
		return false;
	}
}

template <class ItemType>
CBinaryNode<ItemType>* CBinaryNode<ItemType>::GetLeftChildPtr() const
{
	return m_leftChildPtr;
}

template <class ItemType>
CBinaryNode<ItemType>* CBinaryNode<ItemType>::GetRightChildPtr() const
{
	return m_rightChildPtr;
}

template <class ItemType>
void CBinaryNode<ItemType>::SetLeftChildPtr(CBinaryNode<ItemType>* leftChildPtr)
{
	m_leftChildPtr = leftChildPtr;
}

template <class ItemType>
void CBinaryNode<ItemType>::SetRightChildPtr(CBinaryNode<ItemType>* rightChildPtr)
{
	m_rightChildPtr = rightChildPtr;
}

#endif
