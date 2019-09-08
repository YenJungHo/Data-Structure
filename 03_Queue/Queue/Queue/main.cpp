#include <iostream>
#include "IQueue.h"
#include "LinkList.h"
#include "CircularQueue.h"
#include "LinkListQueue.h"

using namespace std;

#define TEST_QUEUE_ARRAY		1
#define TEST_QUEUE_LINKLIST		2

void TestQueue(int nMethod)
{
	IQueue<int> *pIQueue;
	CCircularQueue<int> objCirQueue;
	CLinkListQueue<int> objLinkListQueue;
	int pushData, *pPopData = nullptr, *pPeekData = nullptr, nSize;

	switch (nMethod) {
	case TEST_QUEUE_ARRAY:
		pIQueue = &objCirQueue;
		break;

	case TEST_QUEUE_LINKLIST:
		pIQueue = &objLinkListQueue;
		break;

	default:
		pIQueue = &objCirQueue;
		break;
	}

	cout << "Show data in queue." << endl;
	pIQueue->show();
	cout << endl;

	cout << "Push 2 data in queue." << endl;
	pushData = 1;
	pIQueue->push(pushData);
	pushData = 2;
	pIQueue->push(pushData);
	pIQueue->show();
	cout << endl;

	cout << "Push 1 data in queue." << endl;
	pushData = 3;
	pIQueue->push(pushData);
	pIQueue->show();
	cout << endl;

	cout << "Push 2 data in queue." << endl;
	pushData = 4;
	pIQueue->push(pushData);
	pushData = 5;
	pIQueue->push(pushData);
	pushData = 6;
	pIQueue->push(pushData);
	pIQueue->show();
	cout << endl;

	cout << "Recursive peek and pop" << endl;
	nSize = pIQueue->size();
	for (int i = 0; i < nSize + 1; i++) {
		pPeekData = pIQueue->peek();

		if (pPeekData == nullptr) {
			cout << "Peek data : nullptr" << endl;
		}
		else {
			cout << "Peek data : " << *pPeekData << endl;
		}

		pPopData = pIQueue->pop();
		if (pPopData == nullptr) {
			cout << "Pop data : nullptr" << endl;
		}
		else {
			cout << "Pop data : " << *pPopData << endl;
		}

		pIQueue->show();
		cout << endl;
	}
}

int main()
{
	cout << "Test Queue implemented by array" << endl;
	TestQueue(TEST_QUEUE_ARRAY);
	cout << endl;
	system("pause");

	cout << "Test Queue implemented by link list" << endl;
	TestQueue(TEST_QUEUE_LINKLIST);
	cout << endl;
	system("pause");

	return 0;
}

