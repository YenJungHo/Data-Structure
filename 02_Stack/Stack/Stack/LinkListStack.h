#ifndef LINKLISTSTACK_H
#define LINKLISTSTACK_H

template< class T >
class CLinkList;

template< class T >
class CLinkListStack : public IStack<T>
{
public:
	CLinkListStack(void)
	// constructor
	{
	}

	~CLinkListStack(void)
	// destructor
	{
		clear();
	}

	void clear(void)
	// clear all data in stack
	{
		m_LinkList.clear();
	}

	int size(void)
	// get number of data in stack
	{
		return m_LinkList.size();
	}

	bool isEmpty(void)
	// query if stack empty
	{
		return m_LinkList.isEmpty();
	}

	bool isFull(void)
	// query if stack full
	{
		return false;
	}

	void push(T& x)
	// push data in stack
	{
		m_LinkList.push_front(x);
	}

	T* pop(void)
	// pop top data in stack
	{
		T* pData = m_LinkList.peek_front();
		m_LinkList.remove(*pData);
		return pData;
	}

	T* peek(void)
	// peek top data in stack
	{
		return m_LinkList.peek_front();
	}

	void show(void)
	// show data in stack
	{
		return m_LinkList.show();
	}

private:
	CLinkList<T> m_LinkList;
	// data link list

};
#endif
