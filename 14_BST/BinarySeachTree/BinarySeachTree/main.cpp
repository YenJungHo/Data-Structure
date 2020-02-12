// BinarySeachTree.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <queue>
#include <iostream>
using namespace std;
#include "BST.h"



int main()
{
	CBST BST;
	BST.put(5, 0);
	BST.put(3, 0);
	BST.put(7, 0);
	BST.put(9, 0);
	BST.put(1, 0);

	cout << BST.maximum() << endl;
	cout << BST.minimum() << endl;
	BST.deleteMin();
	cout << BST.minimum() << endl;

	system("pause");

    return 0;
}

