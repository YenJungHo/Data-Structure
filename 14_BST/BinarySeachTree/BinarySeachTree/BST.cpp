#include "stdafx.h"
#include <queue>
#include <iostream>
using namespace std;
#include "BST.h"


CBST::CBST(void)
{
	m_pRootNode = nullptr;
}

CBST::~CBST(void) {

}

void CBST::put(int nKey, int nValue) {
	m_pRootNode = put(m_pRootNode, nKey, nValue);
}

int CBST::get(int nKey) {
	CNode *pNode = m_pRootNode;

	while (pNode != nullptr) {
		if (pNode->m_nKey == nKey) {
			return pNode->m_nVal;
		}
		else if (pNode->m_nKey > nKey) {
			pNode = pNode->m_pLeftNode;
		}
		else {
			pNode = pNode->m_pRightNode;
		}
	}
}

int CBST::size(void) {
	return size(m_pRootNode);
}

int CBST::rank(int nKey) {
	return rank(nKey, m_pRootNode);
}

queue<int> CBST::inOrder(void) {
	clearQueue();
	inorder(m_pRootNode);
	return m_queue;
}

int CBST::minimum(void) {
	return minimum(NULL, m_pRootNode);
}

int CBST::maximum(void) {
	return maximum(NULL, m_pRootNode);
}

void CBST::deleteMin(void) {
	m_pRootNode = deleteMin(m_pRootNode);
}

void CBST::deleteNode(int nKey) {
	m_pRootNode = deleteNode(nKey, m_pRootNode);
}

CNode* CBST::put(CNode* pNode, int nKey, int nValue) {
	if (pNode == nullptr) {
		return new CNode(nKey, nValue);
	}

	if (pNode->m_nKey > nKey) {
		pNode->m_pLeftNode = put(pNode->m_pLeftNode, nKey, nValue);
	}
	else if (pNode->m_nKey < nKey) {
		pNode->m_pRightNode = put(pNode->m_pRightNode, nKey, nValue);
	}
	else {
		pNode->m_nVal = nValue;
	}

	pNode->m_nCount = 1 + size(pNode->m_pLeftNode) + size(pNode->m_pRightNode);
	return pNode;
}

int CBST::size(CNode *pNode) {
	if (pNode == nullptr) {
		return 0;
	}
	return pNode->m_nCount;
}

int CBST::rank(int nKey, CNode *pNode) {
	if (pNode == nullptr) {
		return 0;
	}

	if (pNode->m_nKey > nKey) {
		return rank(nKey, pNode->m_pLeftNode);
	}
	else if (pNode->m_nKey < nKey) {
		return 1 + size(pNode->m_pLeftNode) + rank(nKey, pNode->m_pRightNode);
	}
	else {
		return size(pNode->m_pLeftNode);
	}
}

void CBST::inorder(CNode *pNode) {
	if (pNode == nullptr) {
		return;
	}
	inorder(pNode->m_pLeftNode);
	m_queue.push(pNode->m_nKey);
	inorder(pNode->m_pRightNode);

}

int CBST::minimum(int nKey, CNode *pNode) {
	if (pNode == nullptr) {
		return nKey;
	}
	return minimum(pNode->m_nKey, pNode->m_pLeftNode);
}

int CBST::maximum(int nKey, CNode *pNode) {
	if (pNode == nullptr) {
		return nKey;
	}
	return maximum(pNode->m_nKey, pNode->m_pRightNode);
}

CNode* CBST::minimum(CNode*pNode) {
	if (pNode->m_pLeftNode == nullptr) return pNode;
	return minimum(pNode->m_pLeftNode);
}

CNode *CBST::deleteMin(CNode* pNode) {
	if (pNode->m_pLeftNode == nullptr) {
		CNode* pTmpNode = pNode->m_pRightNode;
		delete pNode;
		return pTmpNode;
	}

	pNode->m_pLeftNode = deleteMin(pNode->m_pLeftNode);
	pNode->m_nCount = 1 + size(pNode->m_pLeftNode) + size(pNode->m_pRightNode);
	return pNode;
}

CNode *CBST::deleteNode(int nKey, CNode *pNode) {
	if (pNode == nullptr) {
		return nullptr;
	}
	if (pNode->m_nKey > nKey) {
		pNode->m_pLeftNode = deleteNode(nKey, pNode->m_pLeftNode);
	}
	else if (pNode->m_nKey < nKey) {
		pNode->m_pRightNode = deleteNode(nKey, pNode->m_pRightNode);
	}
	else {
		if (pNode->m_pLeftNode == nullptr) {
			return pNode->m_pRightNode;
		}
		if (pNode->m_pRightNode == nullptr) {
			return pNode->m_pLeftNode;
		}

		CNode *t = pNode;
		pNode = minimum(t->m_pRightNode);
		pNode->m_pRightNode = deleteMin(t->m_pRightNode);
		pNode->m_pLeftNode = t->m_pLeftNode;
	}

	pNode->m_nCount = size(pNode->m_pLeftNode) + size(pNode->m_pRightNode) + 1;
	return pNode;
}

void CBST::clearQueue(void) 
{
	while (!m_queue.empty()) {
		m_queue.pop();
	}
}
