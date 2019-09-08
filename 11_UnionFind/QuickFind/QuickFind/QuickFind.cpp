#include <iostream>
#include "QuickFind.h"

using namespace std;

CQuickFind::CQuickFind(int nSize)
// constructor
{
	m_nId = nullptr;
	m_nId = new int[nSize];
	for (int i = 0; i < nSize; i++) {
		m_nId[i] = i;
	}

	m_nCapacity = nSize;
}

CQuickFind::~CQuickFind()
// destructor
{
	delete[]m_nId;
	m_nId = nullptr;
}

bool CQuickFind::isConnected(int p, int q)
// check if p and q connected?
{
	if (p > m_nCapacity - 1) {
		return false;
	}

	if (q > m_nCapacity - 1) {
		return false;
	}

	return m_nId[p] == m_nId[q];
}

bool CQuickFind::Connect(int p, int q)
// union q and p
{
	if (p > m_nCapacity - 1) {
		return false;
	}

	if (q > m_nCapacity - 1) {
		return false;
	}

	int p_id = m_nId[p];
	int q_id = m_nId[q];

	for (int i = 0; i < m_nCapacity; i++) {
		if (m_nId[i] == p_id) {
			m_nId[i] = q_id;
		}
	}
	return true;
}

void CQuickFind::Show(void)
// show array
{
	cout << ">> Show ID array";
	cout << ", Array size : " << m_nCapacity << endl;
	cout << ">> ";
	for (int i = 0; i < m_nCapacity; i++) {
		cout << m_nId[i] << " ";
	}
	cout << endl << endl;
}
