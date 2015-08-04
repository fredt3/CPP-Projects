#include <iostream>
#include <cstdlib>
#include "LargeInt.h"

using namespace std;
using namespace largeintnamespace;

int main()
{
	LargeInt l1;
	LargeInt l2;
	LargeInt l3;
	
/*	l1.data[0] = 0;
	l1.data[1] = 9;
	l1.data[2] = 9;
	l1.data[3] = 9;
	l1.data[4] = 9;
	
	l2.data[0] = 0;
	l2.data[1] = 1;
	l2.data[2] = 1;
	l2.data[3] = 1;
	l2.data[4] = 1;*/
//	l1.insert(6);
//	l1.insert(5);
	
//	l2.insert(8);
//	l2.insert(2);
//	char x;
cin >> l1;
cin >> l2;
l3 = l1+l2;
//	int c;
//	c = int(x);
//	l1 = l1 + l2;
//	cin >> l1;
	
	cout << endl << endl;
	cout << l3 << endl;
	cout << endl << endl << endl;
//	cin >> l3;
//	cout << l3 << endl;
	return EXIT_SUCCESS;
}
