#include <iostream>
#include "QuickUnion.h"

using namespace std;

CQuickUnion::CQuickUnion(int nCapacity)
// constructor
{
	m_nCapacity = nCapacity;

	m_pId = nullptr;
	m_pId = new int[nCapacity];

	for (int i = 0; i < nCapacity; i++) {
		m_pId[i] = i;
	}
}

CQuickUnion::~CQuickUnion(void)
// destructor
{
	delete[]m_pId;
	m_pId = nullptr;
}

int CQuickUnion::root(int i)
// find root of index i
{
	if (i >= m_nCapacity) {
		return -1;
	}

	while (i != m_pId[i]) {
		i = m_pId[i];
	}
	return i;
}

bool CQuickUnion::isConnected(int p, int q)
// check if index q and q are connencted
{
	if (root(p) == -1) {
		return false;
	}

	if (root(q) == -1) {
		return false;
	}

	return root(p) == root(q);
}

bool CQuickUnion::connenct(int p, int q)
// connect index p to index q
{
	if (root(p) == -1) {
		return false;
	}

	if (root(q) == -1) {
		return false;
	}

	int root_p = root(p);
	int root_q = root(q);

	m_pId[root_p] = root_q;

	return true;
}

void CQuickUnion::show(void)
// show index array
{
	cout << "Show quick union index array." << endl;
	cout << "Array size : " << m_nCapacity << endl;
	cout << ">>";
	for (int i = 0; i < m_nCapacity; i++) {
		cout << m_pId[i] << " ";
	}
	cout << endl << endl;
}
