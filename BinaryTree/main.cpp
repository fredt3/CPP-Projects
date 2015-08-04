#include <iostream>
#include <cstdlib>
#include "BST.h"
#include "BST.cpp"

using namespace std;
using namespace si221;

int main()
{
	BST<int> bst;
	int size = 10;
	//int n = 457;

	
/* 	for(int i = 0; i < size; i++)
	{
		//int r = rand()%size;
		//bst.insert(r);
		bst.insert2(i);
	} */
	
	bst.insert2(5);
	bst.insert2(8);
	bst.insert2(7);
	bst.insert2(4);
	bst.insert2(9);
	
	
	//bst.remove(2);
	
	
	
	//cout<< "Starting BST Search..."<<endl;
	//cout<< n <<" exists " << bst.search(n) << " times!" <<endl;
	
	bst.visitInOrder();
	cout << endl;
	
	return EXIT_SUCCESS;
}


