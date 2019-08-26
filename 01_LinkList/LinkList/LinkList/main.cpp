#include <iostream>
#include "LinkList.h"

using namespace std;

int main()
{
	CLinkList List;
	List.push_back(1);
	List.show();
	system("pause");

	List.reverse();
	List.show();
	system("pause");

	List.push_back(3);
	List.show();
	system("pause");

	List.push_back(5);
	List.show();
	system("pause");

	List.push_front(-1);
	List.show();
	system("pause");

	List.reverse();
	List.show();
	system("pause");

	List.remove(5);
	List.show();
	system("pause");

	List.remove(1);
	List.show();
	system("pause");

	List.remove(-1);
	List.show();
	system("pause");

	List.remove(3);
	List.show();
	system("pause");
	return 0;
}

