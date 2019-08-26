#ifndef _LINKLIST_H_
#define _LINKLIST_H_

class CLinkList;

class CListNode
{
public:
	CListNode(void) : m_nData(0), m_pNextNode(nullptr) {};
	// constructor

	CListNode(int nData) :m_nData(nData), m_pNextNode(nullptr) {};
	// constructor
	
	~CListNode(void) {};
	// destructor

	int m_nData;
	// data

	CListNode *m_pNextNode;
	// next node pointer
};

class CLinkList
{
public:
	CLinkList(void);
	// constructor

	~CLinkList( void );
	// destructor

	void show( void );
	// show data in link list

	void push_front( int nData );
	// push data in link list at front side

	void push_back( int nData );
	// push data in link list at back side

	void remove( int nData );
	// remove data in link list

	void clear( void );
	// clear all data in link list

	void reverse(void);
	// reverse data link direciton

	bool isEmpty(void);
	// query if empty

	bool peek_front(int &nData);
	// peek front data

	bool peek_back(int &nData);
	// peek back data

private:
	CListNode *m_pStartNode;
	// pointer of start node

	CListNode *m_pEndNode;
	// pointer of end node
};
#endif
