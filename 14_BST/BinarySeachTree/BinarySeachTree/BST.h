#ifndef CBST_H
#define CBST_H


#pragma once
class CNode {
public:
	CNode(int nKey, int nValue) {
		m_nKey = nKey;
		m_nVal = nValue;
		m_pLeftNode = nullptr;
		m_pRightNode = nullptr;
		m_pParent = nullptr;
		m_nCount = 1;
	}

	CNode(CNode* pParent, int nKey, int nValue) {
		m_nKey = nKey;
		m_nVal = nValue;
		m_pLeftNode = nullptr;
		m_pRightNode = nullptr;
		m_pParent = pParent;
		m_nCount = 1;
	}

	~CNode(void) {
	}
public:
	int m_nKey;
	int m_nVal;
	int m_nCount;

	CNode *m_pLeftNode;
	CNode *m_pRightNode;
	CNode *m_pParent;

};

class CBST {
public:

public:
	CBST(void);

	~CBST(void);

	void put(int nKey, int nValue);

	int get(int nKey);

	int size(void);

	int rank(int nKey);

	queue<int> inOrder(void);

	int minimum(void);

	int maximum(void);

	void deleteMin(void);

	void deleteNode(int nKey);

private:
	CNode* put(CNode* pNode, int nKey, int nValue);

	int size(CNode *pNode);

	int rank(int nKey, CNode *pNode);

	void inorder(CNode *pNode);

	int minimum(int nKey, CNode *pNode);

	int maximum(int nKey, CNode *pNode);

	CNode* minimum(CNode*pNode);

	CNode *deleteMin(CNode* pNode);

	CNode *deleteNode(int nKey, CNode *pNode);

	void clearQueue(void);

private:
	CNode *m_pRootNode;
	// root

	queue<int> m_queue;
};


#endif
