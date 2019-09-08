#include <iostream>
#include "IQueue.h"
#include "CircularQueue.h"

using namespace std;

#define TEST_QUEUE_ARRAY		1
#define TEST_QUEUE_LINKLIST		2

void TestQueue(int nMethod)
{
	IQueue<int> *pIQueue;
	CCircularQueue<int> objCirQueue;
	int pushData, *pPopData = nullptr, *pPeekData = nullptr, nSize;

	switch (nMethod) {
	case TEST_QUEUE_ARRAY:
		pIQueue = &objCirQueue;
		break;

	case TEST_QUEUE_LINKLIST:
		pIQueue = &objCirQueue;	
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
	TestQueue(TEST_QUEUE_ARRAY);
	system("pause");
	return 0;
}

