#ifndef CIRCULARQUEUE_H
#define CIRCULARQUEUE_H

template<class T>
class CCircularQueue : public IQueue<T>
{
public:
	CCircularQueue(int nCapacity = 3)
	// consrtuctor
	{
		m_nCapacity = nCapacity;
		m_pData = nullptr;
		m_pData = new T[m_nCapacity];

		clear();
	}

	~CCircularQueue(void)
	// destructor
	{
		clear();
		delete[]m_pData;
		m_pData = nullptr;
	}

	void clear(void)
	// clear all data in queue
	{
		m_nFront = 0;
		m_nBack = 0;
	}

	int size(void)
	// get number of data in queue
	{
		int nSize;
		if (isEmpty() == true) {
			nSize = 0;
		}
		else if (m_nFront < m_nBack) {
			nSize = m_nBack - m_nFront;
		}
		else {
			nSize = m_nCapacity - (m_nFront - m_nBack);
		}

		return nSize;
	}

	bool isEmpty(void)
	// query if queue empty
	{
		return m_nBack == m_nFront;
	}

	bool isFull(void)
	// query if queue full
	{
		return ((m_nBack + 1) % m_nCapacity) == m_nFront;
	}

	void push(T& x)
	// push data in queue
	{
		if (isFull() == true) {
			doubleQueueCapacity();
		}
		m_nBack = (m_nBack + 1) % m_nCapacity;
		m_pData[m_nBack] = x;
	}

	T* pop(void)
	// pop top data in queue
	{
		if (isEmpty() == true) {
			return nullptr;
		}
		m_nFront = (m_nFront + 1) % m_nCapacity;
		return &m_pData[m_nFront];
	}

	T* peek(void)
	// peek top data in queue
	{
		if (isEmpty() == true) {
			return nullptr;
		}
		return &m_pData[(m_nFront + 1) % m_nCapacity];
	}

	void show(void)
	// show data in queue
	{
		cout << "	Show all data in queue" << endl;
		if (isEmpty() == true) {
			cout << "	Warning : no data in queue!" << endl;
			cout << "	Capacity : " << m_nCapacity;
			cout << "	Data number : " << size() << endl;
			cout << "	Front index : " << m_nFront;
			cout << "	Back index : " << m_nBack << endl;
			return;
		}

		int nSize = size();
		int j;

		cout << "	";
		for (int i = 1; i <= nSize; i++) {
			j = (m_nFront + i) % m_nCapacity;
			cout << m_pData[j]<<" ";
		}
		cout << endl;
		cout << "	Capacity : " << m_nCapacity;
		cout << "	Data number : " << size() << endl;
		cout << "	Front index : " << m_nFront;
		cout << "	Back index : " << m_nBack << endl;
	}

private:
	void doubleQueueCapacity(void)
		// double Queue Capacity
	{
		T* pNewArray = new T[2 * m_nCapacity];
		int nStart = (m_nFront + 1) % m_nCapacity;
		if (nStart < 2) {
			memcpy(pNewArray, m_pData + nStart, sizeof(T) * (m_nCapacity - 1));
		}
		else {
			memcpy(pNewArray, m_pData + nStart, sizeof(T) * (m_nCapacity - nStart));
			memcpy(pNewArray + m_nCapacity - nStart, m_pData, sizeof(T) *(m_nBack + 1));
		}

		m_nFront = 2 * m_nCapacity - 1;
		m_nBack = m_nCapacity - 2;
		m_nCapacity *= 2;
		delete[]m_pData;
		m_pData = pNewArray;
	}

	T *m_pData;
	// data in queue

	int m_nCapacity;
	// capacity of queue

	int m_nFront;
	// front index of queue

	int m_nBack;
	// back index of queue
};

#endif
