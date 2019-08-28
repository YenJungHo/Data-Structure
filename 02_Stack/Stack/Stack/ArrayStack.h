#ifndef ARRAYSTACK_H
#define ARRAYSTACK_H

template< class T >
class CArrayStack : public IStack<T>
{
public:
	CArrayStack(int nCapacity = 3)
	// constructor
	{
		if (nCapacity < 1) {
			m_nCapacity = 10;
		}
		m_nCapacity = nCapacity;
		m_pArray = nullptr;
		m_pArray = new T[nCapacity];

		clear();
	}

	~CArrayStack()
	// destructor
	{
		delete[]m_pArray;
		m_pArray = nullptr;
	}

public:
	void clear(void)
	// clear all data in stack
	{
		m_nTopIndex = -1;
		memset(m_pArray, 0, sizeof(T) * m_nCapacity);
	}

	int size(void)
	// get number of data in stack
	{
		return m_nTopIndex + 1;
	}

	bool isEmpty(void)
	// query if stack empty
	{
		return m_nTopIndex == -1;
	}

	bool isFull(void)
	// query if stack full
	{
		return m_nTopIndex == (m_nCapacity - 1);
	}

	void push(T& x)
	// push data in stack
	{
		if (isFull() == true) {
			T *pNewArray = new T[m_nCapacity * 2];
			memcpy(pNewArray, m_pArray, m_nCapacity * sizeof(T));
			delete[]m_pArray;
			m_pArray = pNewArray;
			m_nCapacity *= 2;
		}
		m_pArray[++m_nTopIndex] = x;
	}

	T* pop(void)
	// pop top data in stack
	{
		if (isEmpty() == true) {
			return nullptr;
		}
		return &m_pArray[m_nTopIndex--];
	}

	T* peek(void)
	// peek top data in stack
	{
		if (isEmpty() == true) {
			return nullptr;
		}
		return &m_pArray[m_nTopIndex];
	}

	void show(void)
	// show data in stack
	{
		cout << "Show all data in stack" << endl;

		if (isEmpty() == true) {
			cout << "> Warning : no data in stack!" << endl;
			cout << "> Capacity : " << m_nCapacity << endl;
			return;
		}
		cout << "> ";
		for (int i = 0; i <= m_nTopIndex; i++) {
			cout << m_pArray[i] << " ";
		}
		cout << endl;
		cout << "> Capacity : " << m_nCapacity << endl;
		cout << "> Top data : " << m_pArray[m_nTopIndex] << endl;
	}

private:
	T* m_pArray;
	// stack array

	int m_nTopIndex;
	// top index of array

	int m_nCapacity;
	// stack total size
};

#endif // 
