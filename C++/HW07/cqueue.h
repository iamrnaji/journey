#pragma once

#include <iostream>
#include "clinkedlist.h"

#ifndef CQUEUE_H
#define CQUEUE_H

typedef ListItemType QueueItemType;

class CQueueException
{
public:
	CQueueException(std::string funcName, std::string msg)
		:m_msg(msg), m_funcName(funcName)
	{

	}

	std::string GetMsg() const { return m_msg; }
	std::string GetFuncName() const { return m_funcName; }

private:
	std::string m_msg;
	std::string m_funcName;
};

class CQueue
{
public:

	void DestroyQueue();
	bool Dequeue() throw (CQueueException);
	bool Enqueue(const QueueItemType& newItem);
	QueueItemType PeekFront() const throw (CQueueException);
	bool IsEmpty() const;

private:
	CLinkedList m_qList;
};














#endif
