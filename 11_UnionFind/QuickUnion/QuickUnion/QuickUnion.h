#ifndef QUCICKUNION_H
#define QUCICKUNION_H

class CQuickUnion
{
public:
	CQuickUnion(int nCapacity, bool bWeigth = false, bool bPathCompress = false);
	// constructor

	~CQuickUnion(void);
	// destructor

	int root(int i);
	// find root of index i

	bool isConnected(int p, int q);
	// check if index q and q are connencted

	bool connenct(int p, int q);
	// connect index p to index q

	void show(void);
	// show index array

private:
	int *m_pId;
	// index array

	int m_nCapacity;
	// size of array

	bool m_bWeigth;
	// flag for Weighted quick-union

	int *m_pSz;
	// size of tree for Weighted quick-union

	bool m_bPathCompress;
	// flag for path compression
};


#endif // !QUCICKUNION_H

