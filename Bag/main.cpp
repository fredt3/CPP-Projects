#include <iostream>
#include <cstdlib>
#include "Bag.h"

using namespace std;
using namespace bagnamespace;

int main()
{
	Bag b1;
	Bag b2;
	Bag b3;
	
	b1.insert(5);
	b1.insert(6);
	b1.insert(5);
	
	b2.insert(3);
	b2.insert(2);
	
	b3 = b1+b2;
	
	b3 += b1;
	
	b3.erase(5);
	
	cout << endl << endl;
	cout << b3.size() << endl << b3.count(5);
	cout << endl << endl << endl;


	return EXIT_SUCCESS;
}
