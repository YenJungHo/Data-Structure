//#include <string.h>
//#include "IStack.h"
//#include "ArrayStack.h"
//
//template<class T>
//CArrayStack<T>::CArrayStack(int nCapacity)
//// constructor
//{
//	if (nCapacity < 1) {
//		m_nCapacity = 10;
//	}
//	m_nCapacity = nCapacity;
//	m_pArray = nullptr;
//	m_pArray = new T[nCapacity];
//
//	clear();
//}
//
//template<class T>
//CArrayStack<T>::~CArrayStack()
//// destructor
//{
//	delete[]m_pArray;
//	m_pArray = nullptr;
//}
//
//template<class T>
//void CArrayStack<T>::clear(void)
//// clear all data in stack
//{
//	m_nTopIndex = -1;
//	memset(m_pArray, 0, sizeof(T) * m_nCapacity);
//}
//
//template<class T>
//int CArrayStack<T>::size(void)
//// get number of data in stack
//{
//	return m_nTopIndex + 1;
//}
//
//template<class T>
//bool CArrayStack<T>::isEmpty(void)
//// query if stack empty
//{
//	return m_nTopIndex == -1;
//}
//
//template<class T>
//bool CArrayStack<T>::isFull(void)
//// query if stack full
//{
//	return m_nTopIndex == ( m_nCapacity - 1);
//}
//
//template<class T>
//void CArrayStack<T>::push(T& x)
//// push data in stack
//{
//	if (isFull() == true) {
//		T *pNewArray = new T[m_nCapacity * 2];
//		memcpy(pNewArray, m_pArray, m_nCapacity * sizeof(T));
//		delete[]m_pArray;
//		m_pArray = pNewArray;
//		m_nCapacity *= 2;
//	}
//	m_pArray[++m_nTopIndex] = x;
//}
//
//template<class T>
//T* CArrayStack<T>::pop(void)
//// pop top data in stack
//{
//	if (isEmpty() == true) {
//		return nullptr;
//	}
//	return &m_pArray[m_nTopIndex--];
//}
//
//template<class T>
//T* CArrayStack<T>::peek(void)
//// peek top data in stack
//{
//	if (isEmpty() == true) {
//		return nullptr;
//	}
//	return &m_pArray[m_nTopIndex];
//}
//
//template<class T>
//void CArrayStack<T>::show(void)
//// show data in stack
//{
//	for (int i = 0; i <= m_nTopIndex; i++) {
//		cout << pNode->m_nData << " ";
//	}
//	cout << "top data : " << m_pArray[m_nTopIndex] << endl;
//}
