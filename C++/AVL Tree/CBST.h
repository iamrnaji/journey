#pragma once

#ifndef CBST_HEADER
#define CBST_HEADER

#include "CBinaryTreeInterface.h"
#include "CBinaryNode.h"
#include "CBinaryNodeTree.h"

template<class ItemType>
class CBST : public CBinaryNodeTree<ItemType>
{
public:
	CBST();
	CBST(const ItemType& rootItem);
	CBST(const CBST<ItemType>& tree);
	virtual ~CBST();


	virtual bool Add(const ItemType& newEntry);
	virtual bool Remove(const ItemType& anEntry);
	CBST<ItemType>& operator=(const CBST<ItemType>& rhs);

protected:
	CBinaryNode<ItemType>* LeftRotate(CBinaryNode<ItemType>* subTreePtr);
	CBinaryNode<ItemType>* RightRotate(CBinaryNode<ItemType>* subTreePtr);
	CBinaryNode<ItemType>* LeftRightRotate(CBinaryNode<ItemType>* subTreePtr);
	CBinaryNode<ItemType>* RightLeftRotate(CBinaryNode<ItemType>* subTreePtr);


	virtual CBinaryNode<ItemType>* RemoveValue(CBinaryNode<ItemType>* subTreePtr, const ItemType& target, bool& success);

	CBinaryNode<ItemType>* PlaceNode(CBinaryNode<ItemType>* subTreePtr, CBinaryNode<ItemType>* newNode);

	virtual CBinaryNode<ItemType>* FindNode(CBinaryNode<ItemType>* treePtr, const ItemType& target, bool& success) const;

};


template<class ItemType>
CBST<ItemType>::CBST()
{
	this->SetRootPtr(nullptr);
}

template<class ItemType>
CBST<ItemType>::CBST(const ItemType& rootItem)
{
	this->Add(rootItem);
}

template<class ItemType>
CBST<ItemType>::CBST(const CBST<ItemType>& tree) 
{
	this->SetRootPtr(this->CopyTree(tree.GetRootPtr()));
}

template<class ItemType>
CBST<ItemType>::~CBST()
{
	this->DestroyTree(this->GetRootPtr());
	this->SetRootPtr(nullptr);
}

template<class ItemType>
bool CBST<ItemType>::Add(const ItemType& newEntry)
{
	CBinaryNode<ItemType>* trav = new CBinaryNode<ItemType>;;
	trav->SetItem(newEntry);
	this->SetRootPtr(PlaceNode(this->GetRootPtr(), trav));
	delete trav;
	return true;
}

template<class ItemType>
bool CBST<ItemType>::Remove(const ItemType& anEntry)
{
	bool success;
	RemoveValue(this->GetRootPtr(), anEntry, success);
	return success;
}


template<class ItemType>
CBST<ItemType>& CBST<ItemType>::operator=(const CBST<ItemType>& rhs)
{
	if (this != &rhs)
	{
		this->DestroyTree(this->GetRootPtr());
		this->SetRootPtr(this->CopyTree(rhs.GetRootPtr()));
	}
	return *this;
}

template<class ItemType>
CBinaryNode<ItemType>* CBST<ItemType>::LeftRotate(CBinaryNode<ItemType>* subTreePtr)
{
	CBinaryNode<ItemType>* first(subTreePtr);
	CBinaryNode<ItemType>* second(nullptr);
	second = first->GetLeftChildPtr();
	first->SetLeftChildPtr(second->GetRightChildPtr());
	second->SetRightChildPtr(first);

	return second;
}

template<class ItemType>
CBinaryNode<ItemType>* CBST<ItemType>::RightRotate(CBinaryNode<ItemType>* subTreePtr)
{
	CBinaryNode<ItemType>* first(subTreePtr);
	CBinaryNode<ItemType>* second(first->GetRightChildPtr());

	first->SetRightChildPtr(second->GetLeftChildPtr());
	second->SetLeftChildPtr(first);

	return second;
}

template<class ItemType>
CBinaryNode<ItemType>* CBST<ItemType>::LeftRightRotate(CBinaryNode<ItemType>* subTreePtr)
{
	CBinaryNode<ItemType>* first(subTreePtr);
	CBinaryNode<ItemType>* second(nullptr);
	CBinaryNode<ItemType>* third(nullptr);

	second = first->GetLeftChildPtr();
	third = second->GetRightChildPtr();

	first->SetLeftChildPtr(third->GetRightChildPtr());
	second->SetRightChildPtr(third->GetLeftChildPtr());
	third->SetRightChildPtr(first);
	third->SetLeftChildPtr(second);

	return third;
}

template<class ItemType>
CBinaryNode<ItemType>* CBST<ItemType>::RightLeftRotate(CBinaryNode<ItemType>* subTreePtr)
{
	CBinaryNode<ItemType>* first(subTreePtr);
	CBinaryNode<ItemType>* second(nullptr);
	CBinaryNode<ItemType>* third(nullptr);

	second = first->GetRightChildPtr();
	third = second->GetLeftChildPtr();

	first->SetRightChildPtr(third->GetLeftChildPtr());
	second->SetLeftChildPtr(third->GetRightChildPtr());
	third->SetLeftChildPtr(first);
	third->SetRightChildPtr(second);

	return third;
}


template<class ItemType>
CBinaryNode<ItemType>* CBST<ItemType>::RemoveValue(CBinaryNode<ItemType>* subTreePtr, const ItemType& target, bool& success)
{

	if (subTreePtr == nullptr)
	{
		return nullptr;
	}


	if (subTreePtr->GetItem() < target)
	{
		subTreePtr->SetRightChildPtr(RemoveValue(subTreePtr->GetRightChildPtr(), target, success));
	}

	else if (subTreePtr->GetItem() > target)
	{
		subTreePtr->SetLeftChildPtr(RemoveValue(subTreePtr->GetLeftChildPtr(), target, success));
	}

	else if (subTreePtr->GetItem() == target)
	{
		if (subTreePtr->GetLeftChildPtr() == nullptr && subTreePtr->GetRightChildPtr() != nullptr)
		{
			CBinaryNode<ItemType>* holder = subTreePtr->GetRightChildPtr();
			subTreePtr->SetRightChildPtr(nullptr);
			subTreePtr->SetItem(holder->GetItem());
			delete holder;
			
		}
		else if (subTreePtr->GetLeftChildPtr() != nullptr && subTreePtr->GetRightChildPtr() == nullptr)
		{
			CBinaryNode<ItemType>* holder = subTreePtr->GetLeftChildPtr();
			subTreePtr->SetLeftChildPtr(nullptr);
			subTreePtr->SetItem(holder->GetItem());
			delete holder;
		}
		else if (subTreePtr->GetLeftChildPtr() == nullptr && subTreePtr->GetRightChildPtr() == nullptr)
		{
			CBinaryNode<ItemType>* holder = subTreePtr;
			subTreePtr = nullptr;
			delete holder;
		}
		else if (subTreePtr->GetLeftChildPtr() != nullptr && subTreePtr->GetRightChildPtr() != nullptr)
		{
			CBinaryNode<ItemType>* holder = this->FindMinNode(subTreePtr->GetRightChildPtr());

			subTreePtr->SetItem(holder->GetItem());

			subTreePtr->SetRightChildPtr(RemoveValue(subTreePtr->GetRightChildPtr(), holder->GetItem(), success));
		}
	}
	
	if (subTreePtr == nullptr)
	{
		return nullptr;
	}
	int leftHeight = this->GetHeightHelper(subTreePtr->GetLeftChildPtr());
	int rightHeight = this->GetHeightHelper(subTreePtr->GetRightChildPtr());

	int balance = leftHeight - rightHeight;

	int leftCHeight = 0, rightCHeight = 0, LBalance = 0, leftDHeight = 0, rightDHeight = 0, RBalance = 0;
	if (subTreePtr->GetLeftChildPtr() != nullptr)
	{
		leftCHeight = this->GetHeightHelper(subTreePtr->GetLeftChildPtr()->GetLeftChildPtr());
		rightCHeight = this->GetHeightHelper(subTreePtr->GetLeftChildPtr()->GetRightChildPtr());

		LBalance = leftCHeight - rightCHeight;
	}
	
	if (subTreePtr->GetRightChildPtr() != nullptr)
	{
		leftDHeight = this->GetHeightHelper(subTreePtr->GetRightChildPtr()->GetLeftChildPtr());
		rightDHeight = this->GetHeightHelper(subTreePtr->GetRightChildPtr()->GetRightChildPtr());

		RBalance = leftDHeight - rightDHeight;
	}
	

	if (balance > 1 && LBalance >= 0)
	{
		return LeftRightRotate(subTreePtr);
	}

	else if (balance > 1 && LBalance < 0)
	{
		return LeftRotate(subTreePtr);
	}

	else if (balance < -1 && RBalance <= 0)
	{
		return RightRotate(subTreePtr);
	}

	else if (balance < -1 && RBalance > 0)
	{
		return RightLeftRotate(subTreePtr);
	}

	success = true;
	return subTreePtr;

}

template<class ItemType>
CBinaryNode<ItemType>* CBST<ItemType>::PlaceNode(CBinaryNode<ItemType>* subTreePtr, CBinaryNode<ItemType>* newNode)
{
	if (subTreePtr == nullptr)
	{
		CBinaryNode<ItemType>* node = new CBinaryNode<ItemType>;
		node->SetItem(newNode->GetItem());
		subTreePtr = node;


		return subTreePtr;
	}
	else
	{
		if (subTreePtr->GetItem() > newNode->GetItem())
		{
			subTreePtr->SetLeftChildPtr(PlaceNode(subTreePtr->GetLeftChildPtr(), newNode));
		}
		else if (subTreePtr->GetItem() < newNode->GetItem())
		{
			subTreePtr->SetRightChildPtr(PlaceNode(subTreePtr->GetRightChildPtr(), newNode));
		}
	}



	int leftHeight = this->GetHeightHelper(subTreePtr->GetLeftChildPtr());
	int rightHeight = this->GetHeightHelper(subTreePtr->GetRightChildPtr());

	int balance = leftHeight - rightHeight;


	if (balance > 1 && subTreePtr->GetLeftChildPtr()->GetItem() < newNode->GetItem())
	{
		return LeftRightRotate(subTreePtr);
	}

	else if (balance > 1 && subTreePtr->GetLeftChildPtr()->GetItem() > newNode->GetItem())
	{
		return LeftRotate(subTreePtr);
	}

	else if (balance < -1 && subTreePtr->GetRightChildPtr()->GetItem() < newNode->GetItem())
	{
		return RightRotate(subTreePtr);
	}

	else if (balance < -1 && subTreePtr->GetRightChildPtr()->GetItem() > newNode->GetItem())
	{
		return RightLeftRotate(subTreePtr);
	}

	return subTreePtr;
}

template<class ItemType>
CBinaryNode<ItemType>* CBST<ItemType>::FindNode(CBinaryNode<ItemType>* treePtr, const ItemType& target, bool& success) const
{
	if (treePtr == nullptr)
	{
		success = false;
		return nullptr;
	}
	if (treePtr->GetItem() == target)
	{
		return treePtr;
		success = true;
	}
	else
	{
		if (treePtr->GetItem() > target)
		{
			return FindNode(treePtr->GetRightChildPtr(), target, success);
			
		}
		else
		{
			return FindNode(treePtr->GetLeftChildPtr(), target, success);
		}
	}
	success = false;
}



#endif
