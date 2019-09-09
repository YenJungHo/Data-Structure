#ifndef QUCICKUNION_H
#define QUCICKUNION_H

class CQuickUnion
{
public:
	CQuickUnion(int nCapacity);
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
};


#endif // !QUCICKUNION_H

