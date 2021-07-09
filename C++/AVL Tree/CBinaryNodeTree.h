#pragma once

#ifndef CBINARYNODETREE_HEADER
#define CBINARYNODETREE_HEADER

#include "CBinaryTreeInterface.h"
#include "CBinaryNode.h"
#include "PrecondViolatedExcept.h"

template <class ItemType>
class CBinaryNodeTree : public CBinaryTreeInterface<ItemType>
{
public:
	CBinaryNodeTree();
	CBinaryNodeTree(const ItemType& rootItem);
	CBinaryNodeTree(const ItemType& rootItem, const CBinaryNodeTree<ItemType>* leftTreePtr, const CBinaryNodeTree<ItemType>* rightTreePtr);
	CBinaryNodeTree(const CBinaryNodeTree<ItemType>& tree);

	virtual ~CBinaryNodeTree();

	virtual bool IsEmpty() const;
	virtual int GetHeight() const;
	virtual int GetNumberOfNodes() const;
	virtual ItemType GetRootData() const throw(PrecondViolatedExcept);
	virtual void SetRootData(const ItemType& newData);
	virtual bool Add(const ItemType& newData) = 0;
	virtual bool Remove(const ItemType& data) = 0;
	virtual void Clear();
	virtual bool Contains(const ItemType& anEntry) const;
	virtual void PreorderTraverse(void Visit(const ItemType& item)) const;
	virtual void InorderTraverse(void Visit(const ItemType& item)) const;
	virtual void PostorderTraverse(void Visit(const ItemType& item)) const;
	virtual void LevelorderTraverse(void Visit(const ItemType& item)) const;

	CBinaryNodeTree<ItemType>& operator=(const CBinaryNodeTree<ItemType>& rhs);
	
protected:
	CBinaryNode<ItemType>* GetRootPtr() const;
	void SetRootPtr(CBinaryNode<ItemType>* rootPtr);
	CBinaryNode<ItemType>* GetParentNode(CBinaryNode<ItemType>* subTreePtr, CBinaryNode<ItemType>* nodePtr) const;
	int GetNumberOfNodesHelper(CBinaryNode<ItemType>* subTreePtr) const;
	int GetHeightHelper(CBinaryNode<ItemType>* subTreePtr) const;
	CBinaryNode<ItemType>* FindMinNode(CBinaryNode<ItemType>* subTreePtr);
	CBinaryNode<ItemType>* FindMaxNode(CBinaryNode<ItemType>* subTreePtr);

	virtual CBinaryNode<ItemType>* RemoveValue(CBinaryNode<ItemType>* subnTreePtr, const ItemType& target, bool& success) = 0;
	virtual CBinaryNode<ItemType>* FindNode(CBinaryNode<ItemType>* treePtr, const ItemType& target, bool& success) const = 0;
	CBinaryNode<ItemType>* CopyTree(const CBinaryNode<ItemType>* oldTreeRootPtr) const;
	void DestroyTree(CBinaryNode<ItemType>* subTreePtr);
	void PreOrder(void Visit(const ItemType& item), CBinaryNode<ItemType>* treePtr) const;
	void PostOrder(void Visit(const ItemType& item), CBinaryNode<ItemType>* treePtr) const;
	void InOrder(void Visit(const ItemType& item), CBinaryNode<ItemType>* treePtr) const;
	void LevelOrder(void Visit(const ItemType& item), CBinaryNode<ItemType>* treePtr, int level) const;

private:
	CBinaryNode<ItemType>* m_rootPtr;



};

template <class ItemType>
CBinaryNodeTree<ItemType>::CBinaryNodeTree()
{
	m_rootPtr = nullptr;
}

template <class ItemType>
CBinaryNodeTree<ItemType>::CBinaryNodeTree(const ItemType& rootItem)
{
	m_rootPtr = new CBinaryNode<ItemType>(rootItem);
}

template<class ItemType>
CBinaryNodeTree<ItemType>::CBinaryNodeTree(const ItemType& rootItem, const CBinaryNodeTree<ItemType>* leftTreePtr, const CBinaryNodeTree<ItemType>* rightTreePtr)
{
	m_rootPtr = new CBinaryNode<ItemType>(rootItem, leftTreePtr, rightTreePtr);
}

template<class ItemType>
CBinaryNodeTree<ItemType>::CBinaryNodeTree(const CBinaryNodeTree<ItemType>& tree)
{
	CopyTree(tree);
}

template<class ItemType>
CBinaryNodeTree<ItemType>::~CBinaryNodeTree()
{
	if (m_rootPtr)
	{
		DestroyTree(m_rootPtr);
	}
	m_rootPtr = nullptr;
}

template<class ItemType>
bool CBinaryNodeTree<ItemType>::IsEmpty() const
{
	if (m_rootPtr == nullptr)
	{
		return true;
	}
	else
	{
		return false;
	}
}

template<class ItemType>
int CBinaryNodeTree<ItemType>::GetHeight() const
{
	return GetHeightHelper(m_rootPtr);
}

template<class ItemType>
int CBinaryNodeTree<ItemType>::GetNumberOfNodes() const
{
	return GetNumberOfNodesHelper(m_rootPtr);
}


template<class ItemType>
ItemType CBinaryNodeTree<ItemType>::GetRootData() const throw(PrecondViolatedExcept)
{
		if (m_rootPtr == nullptr)
		{
			throw("Root of tree is empty");
		}
		else
		{
			return m_rootPtr->GetItem();
		}
}

template<class ItemType>
void CBinaryNodeTree<ItemType>::SetRootData(const ItemType& newData)
{
	m_rootPtr->SetItem(newData);
}

template<class ItemType>
void CBinaryNodeTree<ItemType>::Clear()
{
	DestroyTree(m_rootPtr);
}

template<class ItemType>
bool CBinaryNodeTree<ItemType>::Contains(const ItemType& anEntry) const
{
	bool rami;
	FindNode(m_rootPtr, anEntry, rami);
	return rami;
}

template<class ItemType>
void CBinaryNodeTree<ItemType>::PreorderTraverse(void Visit(const ItemType& item)) const
{
	PreOrder(Visit, m_rootPtr);
}

template<class ItemType>
void CBinaryNodeTree<ItemType>::InorderTraverse(void Visit(const ItemType& item)) const
{
	InOrder(Visit, m_rootPtr);
}

template<class ItemType>
void CBinaryNodeTree<ItemType>::PostorderTraverse(void Visit(const ItemType& item)) const
{
	PostOrder(Visit, m_rootPtr);
}

template<class ItemType>
void CBinaryNodeTree<ItemType>::LevelorderTraverse(void Visit(const ItemType& item)) const
{
	for (int i = 1; i <= this->GetHeight(); i++)
	{
		cout << "Level " << i - 1 << endl;
		LevelOrder(Visit, m_rootPtr, i);
	}
	
}

template<class ItemType>
CBinaryNodeTree<ItemType>& CBinaryNodeTree<ItemType>::operator=(const CBinaryNodeTree<ItemType>& rhs)
{
	CopyTree(rhs);
}

template <class ItemType>
CBinaryNode<ItemType>* CBinaryNodeTree<ItemType>::GetRootPtr() const
{
	return m_rootPtr;
}

template <class ItemType>
void CBinaryNodeTree<ItemType>::SetRootPtr(CBinaryNode<ItemType>* rootPtr)
{
	m_rootPtr = rootPtr;
}

template <class ItemType>
CBinaryNode<ItemType>* CBinaryNodeTree<ItemType>::GetParentNode(CBinaryNode<ItemType>* subTreePtr, CBinaryNode<ItemType>* nodePtr) const
{
	if (subTreePtr == nullptr)
	{
		return nullptr;
	}

	if (subTreePtr->GetLeftChildPtr() == nodePtr || subTreePtr->GetRightChildPtr() == nodePtr)
	{
		return subTreePtr;
	}
	else
	{
		GetParentNode(subTreePtr->GetLeftChildPtr(), nodePtr);
		GetParentNode(subTreePtr->GetRightChildPtr(), nodePtr);
	}
}

template <class ItemType>
int CBinaryNodeTree<ItemType>::GetNumberOfNodesHelper(CBinaryNode<ItemType>* subTreePtr) const
{
	int count = 1;

	if (subTreePtr == nullptr)
	{
		return 0;
	}
	else
	{
		count = count + GetNumberOfNodesHelper(subTreePtr->GetLeftChildPtr());
		count = count + GetNumberOfNodesHelper(subTreePtr->GetRightChildPtr());
	}
}

template <class ItemType>
int CBinaryNodeTree<ItemType>::GetHeightHelper(CBinaryNode<ItemType>* subTreePtr) const
{
	if (subTreePtr == nullptr)
	{
		return 0;
	}
	else
	{
		int left = GetHeightHelper(subTreePtr->GetLeftChildPtr());
		int right = GetHeightHelper(subTreePtr->GetRightChildPtr());
		if (left >= right)
		{
			return left + 1;
		}
		else
		{
			return right + 1;
		}
	}
}

template <class ItemType>
CBinaryNode<ItemType>* CBinaryNodeTree<ItemType>::FindMinNode(CBinaryNode<ItemType>* subTreePtr)
{
	CBinaryNode<ItemType>* trav = subTreePtr;
	while (trav->GetLeftChildPtr() != nullptr)
	{
		trav = trav->GetLeftChildPtr();
	}

	return trav;
}

template <class ItemType>
CBinaryNode<ItemType>* CBinaryNodeTree<ItemType>::FindMaxNode(CBinaryNode<ItemType>* subTreePtr)
{
	CBinaryNode<ItemType>* trav = subTreePtr;
	while (trav->GetRightChildPtr() != nullptr)
	{
		trav = trav->GetRightChildPtr();
	}

	return trav;
}


template <class ItemType>
CBinaryNode<ItemType>* CBinaryNodeTree<ItemType>::CopyTree(const CBinaryNode<ItemType>* oldTreeRootPtr) const
{
	if (oldTreeRootPtr == nullptr)
	{
		return nullptr;
	}
	CBinaryNode<ItemType>* newTree = new CBinaryNode<ItemType>;
	newTree->SetItem(oldTreeRootPtr->GetItem());
	newTree->SetLeftChildPtr(CopyTree(oldTreeRootPtr->GetLeftChildPtr()));
	newTree->SetRightChildPtr(CopyTree(oldTreeRootPtr->GetRightChildPtr()));
	return newTree;

}

template <class ItemType>
void CBinaryNodeTree<ItemType>::DestroyTree(CBinaryNode<ItemType>* subTreePtr)
{
	if (subTreePtr != nullptr)
	{
		DestroyTree(subTreePtr->GetLeftChildPtr());
		DestroyTree(subTreePtr->GetRightChildPtr());
		delete subTreePtr;
	}
}

template <class ItemType>
void CBinaryNodeTree<ItemType>::PreOrder(void Visit(const ItemType& item), CBinaryNode<ItemType>* treePtr) const
{
	if (treePtr == nullptr)
	{
		return;
	}

	Visit(treePtr->GetItem());
	PreOrder(Visit, treePtr->GetLeftChildPtr());
	PreOrder(Visit, treePtr->GetRightChildPtr());
}

template <class ItemType>
void CBinaryNodeTree<ItemType>::PostOrder(void Visit(const ItemType& item), CBinaryNode<ItemType>* treePtr) const
{
	if (treePtr == nullptr)
	{
		return;
	}

	PostOrder(Visit, treePtr->GetLeftChildPtr());
	PostOrder(Visit, treePtr->GetRightChildPtr());
	Visit(treePtr->GetItem());
}

template <class ItemType>
void CBinaryNodeTree<ItemType>::InOrder(void Visit(const ItemType& item), CBinaryNode<ItemType>* treePtr) const
{
	if (treePtr == nullptr)
	{
		return;
	}

	InOrder(Visit, treePtr->GetLeftChildPtr());
	Visit(treePtr->GetItem());
	InOrder(Visit, treePtr->GetRightChildPtr());

}

template <class ItemType>
void CBinaryNodeTree<ItemType>::LevelOrder(void Visit(const ItemType& item), CBinaryNode<ItemType>* treePtr, int level) const
{
	if (treePtr == nullptr)
	{
		return;
	}

	if (level == 1)
	{
		Visit(treePtr->GetItem());
	}
	else if (level > 1)
	{
		LevelOrder(Visit, treePtr->GetLeftChildPtr(), level - 1);
		LevelOrder(Visit, treePtr->GetRightChildPtr(), level - 1);
	}

}


#endif
