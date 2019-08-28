#include <iostream>
#include "IStack.h"
#include "LinkList.h"
#include "ArrayStack.h"
#include "LinkListStack.h"

using namespace std;

#define TestArrayStack			(1)
#define TestLinkListStack		(2)

void testStack( int nTest = TestArrayStack)
{
	int pushData, *pPopData = nullptr, *pPeekData = nullptr, nSize;

	CArrayStack<int> ArrayStack;
	CLinkListStack<int> LinkListStack;
	IStack<int> *pIStack;

	switch (nTest) {
	case TestArrayStack:
		pIStack = &ArrayStack;
		break;

	case TestLinkListStack: 
		pIStack = &LinkListStack;
		break;

	default:
		pIStack = &ArrayStack;
		break;
	}

	cout << "put 3 datas in stack" << endl;
	pushData = 1;
	pIStack->push(pushData);
	pushData = 2;
	pIStack->push(pushData);
	pushData = 3;
	pIStack->push(pushData);
	pIStack->show();
	cout << endl;

	cout << "put more 1 data in stack" << endl;
	pushData = 4;
	pIStack->push(pushData);
	pIStack->show();
	cout << endl;

	nSize = pIStack->size() + 1;
	for (int i = 0; i < nSize; i++) {
		pPeekData = pIStack->peek();
		if (pPeekData)
			cout << "peek data : " << *pPeekData << endl;
		else
			cout << "peek data : null" << endl;

		pPopData = pIStack->pop();
		cout << "pop data" << endl;

		pIStack->show();
		cout << endl;
	}
}

int main()
{
	testStack(TestArrayStack);
	testStack(TestLinkListStack);

	system("pause");
	return 0;
}
