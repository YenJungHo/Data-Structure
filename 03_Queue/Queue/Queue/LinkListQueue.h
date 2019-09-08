#ifndef LINKLISTQUEUE
#define LINKLISTQUEUE

template<class T>
class CLinkListQueue :public IQueue<T>
{
public:
	CLinkListQueue()
	// consturctor
	{
		// nothing
	}

	~CLinkListQueue()
	// desturctor
	{
		clear();
	}

	void clear(void)
	// clear all data in queue
	{
		m_LinkList.clear();
	}

	int size(void)
	// get number of data in queue
	{
		return m_LinkList.size();
	}

	bool isEmpty(void)
	// query if queue empty
	{
		return m_LinkList.isEmpty();
	}

	bool isFull(void)
	// query if queue full
	{
		return false;
	}

	void push(T& x)
	// push data in queue
	{
		m_LinkList.push_back(x);
	}

	T* pop(void)
	// pop top data in queue
	{
		T* pData = m_LinkList.peek_front();
		T Out;

		if (pData != nullptr) {
			memcpy(&Out, pData, sizeof(T));
			m_LinkList.remove(*pData);
			return &Out;
		}

		return nullptr;
	}

	T* peek(void)
	// peek top data in queue
	{
		return m_LinkList.peek_front();
	}

	void show(void)
	// show data in queue
	{
		cout << "	Show all data in queue" << endl;
		m_LinkList.show();
	}

private:
	CLinkList<T> m_LinkList;
	// data in link list
};

#endif