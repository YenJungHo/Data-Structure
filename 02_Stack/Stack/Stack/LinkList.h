#ifndef LINKLIST_H_
#define LINKLIST_H_

template< class T >
class CLinkList;

template< class T >
class CListNode
{
public:
	CListNode(void) : m_nData(0), m_pNextNode(nullptr) {};
	// constructor

	CListNode(T nData) :m_nData(nData), m_pNextNode(nullptr) {};
	// constructor

	~CListNode(void) {};
	// destructor

	T m_nData;
	// data

	CListNode<T> *m_pNextNode;
	// next node pointer
};

template< class T >
class CLinkList
{
public:
	CLinkList(void)
	// constructor
	{
		m_pStartNode = nullptr;
		m_pEndNode = nullptr;
		m_nSize = 0;
	}

	~CLinkList(void)
	// destructor
	{
		// clear all data in list
		clear();
	}

	void show(void)
	// show data in link list
	{
		cout << "Show all data in stack" << endl;

		if (isEmpty() == true) {
			cout << "> Warning : no data in stack!" << endl;
			return;
		}

		CListNode<T> *pNode = m_pStartNode;

		cout << "> ";
		while (pNode != nullptr) {
			cout << pNode->m_nData << " ";
			pNode = pNode->m_pNextNode;
		}
		cout << endl;
		cout << "> Start data : " << m_pStartNode->m_nData << endl;
		cout << "> End data : " << m_pEndNode->m_nData << endl;
	}

	void push_front(T nData)
	// push data in link list at front side
	{
		CListNode<T> *pNewNode = new CListNode<T>(nData);
		pNewNode->m_pNextNode = m_pStartNode;
		if (isEmpty() == true) {
			m_pEndNode = pNewNode;
		}
		m_pStartNode = pNewNode;
		m_nSize++;
	}

	void push_back(T nData)
	// push data in link list at back side
	{
		if (isEmpty() == true) {
			push_front(nData);
			return;
		}

		CListNode<T> *pNewNode = new CListNode<T>(nData);
		m_pEndNode->m_pNextNode = pNewNode;
		m_pEndNode = pNewNode;
		m_nSize++;
	}

	void remove(T& nData)
	// remove data in link list
	{
		// empty case
		if (isEmpty() == true) {
			return;
		}

		// travesal
		CListNode<T> *pNode = m_pStartNode, *pLastNode = nullptr;
		while (pNode != nullptr && pNode->m_nData != nData) {
			pLastNode = pNode;
			pNode = pNode->m_pNextNode;
		}

		// no data in list case
		if (pNode == nullptr) {
			cout << "There is no " << nData << " in list.\n";
			return;
		}

		// there is a data in list and removed data at start 
		if (pNode == m_pStartNode) {
			// only one data in list
			if (pNode == m_pEndNode) {
				clear();
				return;
			}

			// more than one data in list
			m_pStartNode = pNode->m_pNextNode;
			delete pNode;
			pNode = nullptr;
		}
		else if (pNode == m_pEndNode) {
			delete pNode;
			pNode = nullptr;
			pLastNode->m_pNextNode = nullptr;
			m_pEndNode = pLastNode;
		}
		else {
			pLastNode->m_pNextNode = pNode->m_pNextNode;
			delete pNode;
			pNode = nullptr;
		}
		m_nSize--;
	}

	void clear(void)
	// clear all data in link list
	{
		CListNode<T> *pDelNode;
		while (isEmpty() == false) {
			pDelNode = m_pStartNode;
			m_pStartNode = m_pStartNode->m_pNextNode;
			delete pDelNode;
			pDelNode = nullptr;
		}
		m_pEndNode = nullptr;
		m_nSize = 0;
	}

	void reverse(void)
	// reverse data link direciton
	{
		// check if empty case
		if (isEmpty() == true) {
			return;
		}

		// check if only one data in list case
		if (m_pEndNode == m_pStartNode) {
			return;
		}

		// initial node pointer
		CListNode<T> *pLastNode = nullptr,
			*pNode = m_pStartNode,
			*pNextNode = m_pStartNode->m_pNextNode;

		m_pStartNode = m_pEndNode;
		m_pEndNode = pNode;

		// travesal and reverse list
		while (pNode != nullptr) {
			pNode->m_pNextNode = pLastNode;
			pLastNode = pNode;
			pNode = pNextNode;

			// need to check null pointer
			if (pNextNode != nullptr) {
				pNextNode = pNextNode->m_pNextNode;
			}
		}
	}

	bool isEmpty(void)
	// query if empty
	{
		if (m_pStartNode == nullptr) {
			//cout << "List is empty.\n";
			return true;
		}

		return false;
	}

	T* peek_front(void)
	// peek front data
	{
		if (isEmpty() == true) {
			return nullptr;
		}
		return &m_pStartNode->m_nData;
	}

	T* peek_back(void)
	// peek back data
	{
		if (isEmpty() == true) {
			return nullptr;
		}
		return &m_pEndNode->m_nData;
	}

	int size(void)
	// get number of data
	{
		return m_nSize;
	}

private:
	CListNode<T> *m_pStartNode;
	// pointer of start node

	CListNode<T> *m_pEndNode;
	// pointer of end node

	int m_nSize;
	// number of data
};
#endif

