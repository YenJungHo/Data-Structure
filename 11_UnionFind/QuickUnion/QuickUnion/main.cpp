#include <iostream>
#include "QuickUnion.h"
using namespace std;

void testQuickUnion(bool bWeigth, bool bPathCompress )
{
	CQuickUnion objQuickUnion( 8, bWeigth, bPathCompress);

	cout << "Show initial quick union array." << endl;

	objQuickUnion.show();

	cout << "Union( 1, 4 )" << endl;
	objQuickUnion.connenct(1, 4);
	objQuickUnion.show();

	cout << "Union( 1, 0 )" << endl;
	objQuickUnion.connenct(1, 0);
	objQuickUnion.show();

	cout << "Union( 5, 0 )" << endl;
	objQuickUnion.connenct(5, 0);
	objQuickUnion.show();

	cout << "Union( 6, 2 )" << endl;
	objQuickUnion.connenct(6, 2);
	objQuickUnion.show();

	cout << "Union( 7, 2 )" << endl;
	objQuickUnion.connenct(7, 2);
	objQuickUnion.show();

	cout << "Union( 6, 3 )" << endl;
	objQuickUnion.connenct(6, 3);
	objQuickUnion.show();

	cout << "isConnected( 3, 7 ) ? Ans :";
	cout << (objQuickUnion.isConnected(3, 7) ? "true" : "false") << endl << endl;

	cout << "isConnected( 1, 6 ) ? Ans :";
	cout << (objQuickUnion.isConnected(1, 6) ? "true" : "false") << endl << endl;

	cout << "Union( 1, 3 )" << endl;
	objQuickUnion.connenct(1, 3);
	objQuickUnion.show();

	cout << "isConnected( 1, 6 ) ? Ans :";
	cout << (objQuickUnion.isConnected(1, 6) ? "true" : "false") << endl << endl;
}

int main(void)
{
	testQuickUnion(false,false);

	testQuickUnion(true, false);

	testQuickUnion(false, true);

	testQuickUnion(true, true);

	system("pause");
	return 0;
}
