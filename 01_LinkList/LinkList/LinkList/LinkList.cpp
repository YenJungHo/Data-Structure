#include <iostream>
#include "LinkList.h"

using namespace std;

CLinkList::CLinkList(void)
// constructor
{
	m_pStartNode = nullptr;
	m_pEndNode = nullptr;
}

CLinkList::~CLinkList(void)
// destructor
{
	// clear all data in list
	clear();
}

void CLinkList::show(void)
// show data in link list
{
	if (isEmpty() == true) {
		return;
	}

	CListNode *pNode = m_pStartNode;
	while (pNode != nullptr) {
		cout << pNode->m_nData << " ";
		pNode = pNode->m_pNextNode;
	}
	cout << endl;
	cout << "Start data : " << m_pStartNode->m_nData << endl;
	cout << "End data : " << m_pEndNode->m_nData << endl;
}

void CLinkList::push_front(int nData)
// push data in link list at front side
{
	CListNode *pNewNode = new CListNode(nData);
	pNewNode->m_pNextNode = m_pStartNode;
	if (isEmpty() == true) {
		m_pEndNode = pNewNode;
	}
	m_pStartNode = pNewNode;
}

void CLinkList::push_back(int nData)
// push data in link list at back side
{
	if (isEmpty() == true) {
		push_front(nData);
		return;
	}

	CListNode *pNewNode = new CListNode(nData);
	m_pEndNode->m_pNextNode = pNewNode;
	m_pEndNode = pNewNode;
}

void CLinkList::remove(int nData)
// remove data in link list
{
	// empty case
	if (isEmpty() == true) {
		return;
	}

	// travesal
	CListNode *pNode = m_pStartNode, *pLastNode = nullptr;
	while( pNode!=nullptr && pNode->m_nData!=nData ) {
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
	else if(pNode == m_pEndNode) {
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
}

void CLinkList::clear(void)
// clear all data in link list
{
	CListNode *pDelNode;
	while (isEmpty() == false) {
		pDelNode = m_pStartNode;
		m_pStartNode = m_pStartNode->m_pNextNode;
		delete pDelNode;
		pDelNode = nullptr;
	}
	m_pEndNode = nullptr;
}

void CLinkList::reverse(void)
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
	CListNode *pLastNode = nullptr,
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

bool CLinkList::isEmpty(void)
// query if empty
{
	if (m_pStartNode == nullptr) {
		cout << "List is empty.\n";
		return true;
	}

	return false;
}

bool CLinkList::peek_front(int &nData)
// peek front data
{
	if (isEmpty() == true) {
		return false;
	}
	nData = m_pStartNode->m_nData;
	return true;
}

bool CLinkList::peek_back(int &nData)
// peek back data
{
	if (isEmpty() == true) {
		return false;
	}
	nData = m_pEndNode->m_nData;
	return true;
}
