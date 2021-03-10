#include <iostream>
#include "clinkedlist.h"
#include "cqueue.h"
using namespace std;

void CQueue::DestroyQueue()
{
	
	m_qList.Clear();
	
}

bool CQueue::Dequeue() throw (CQueueException)
{
	if (m_qList.IsEmpty())
	{
		throw CQueueException("CQueue::DrestroyQueue()", "List is empty");
		return false;
	}
	
	QueueItemType holder;

	if (!m_qList.GetItem(0, holder))
	{
		throw CQueueException("CQueue::DestroyQueue()", "Could not get item");
		return false;
	}

	if (!m_qList.Remove(holder))
	{
		throw CQueueException("CQueue::DestroyQueue()", "Could not remove item");
		return false;
	}
}

bool CQueue::Enqueue(const QueueItemType& newItem)
{
	if (m_qList.Add(newItem))
	{
		return true;
	}
	else
	{
		return false;
	}
}

QueueItemType CQueue::PeekFront() const throw (CQueueException)
{
	if (m_qList.IsEmpty())
	{
		throw CQueueException("CQueue::DrestroyQueue()", "List is empty");
		return -1;
	}

	QueueItemType holder;

	if (!m_qList.GetItem(0, holder))
	{
		throw CQueueException("CQueue::DestroyQueue()", "Could not get item");
		return -1;
	}

	return holder;
}

bool CQueue::IsEmpty() const
{
	if (m_qList.IsEmpty())
	{
		return true;
	}
	else
	{
		return false;
	}
}
