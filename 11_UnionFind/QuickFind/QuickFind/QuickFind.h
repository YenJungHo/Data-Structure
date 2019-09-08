#ifndef QUICKFIND_H_
#define QUICKFIND_H_

class CQuickFind
{
public:
	CQuickFind( int nSize );
	// constructor

	~CQuickFind();
	// destructor

	bool isConnected(int p, int q);
	// check if p and q connected?

	bool Connect(int p, int q);
	// union q and p

	void Show(void);
	// show array

private:
	int *m_nId;
	// index array

	int m_nCapacity;
	// capacity of index array
};
#endif
