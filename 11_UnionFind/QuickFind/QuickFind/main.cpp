#include <iostream>
#include "QuickFind.h"

using namespace std;

void TestQuickFind( void )
{
	CQuickFind objQF(6);

	cout << "Show initial index array." << endl;
	objQF.Show();

	cout << "Union( 0, 1 )" << endl;
	objQF.Connect(0, 1);
	objQF.Show();

	cout << "Union( 5, 4 )" << endl;
	objQF.Connect(5, 4);
	objQF.Show();

	cout << "Is (0,5) Connected? ";
	cout << "Ans : " << ((objQF.isConnected(0, 5))? "true" : "false") << endl << endl;

	cout << "Union( 3, 2 )" << endl;
	objQF.Connect(3, 2);
	objQF.Show();

	cout << "Union( 5, 0 )" << endl;
	objQF.Connect(5, 0);
	objQF.Show();

	cout << "Is (0,5) Connected? " ;
	cout << "Ans : " << ((objQF.isConnected(0, 5)) ? "true" : "false") << endl << endl;
}

int main(void)
{
	TestQuickFind();

	system("pause");
	return 0;
}
