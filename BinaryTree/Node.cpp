#ifndef NODE_CPP
#define NODE_CPP

#include "Node.h"

namespace si221
{
	template<class DATATYPE>
	Node<DATATYPE>::Node(const DATATYPE& d)
	{
		left = NULL;
		right = NULL;
		data = d;
		balance = 0;
	}
	template<class DATATYPE>
	Node<DATATYPE>::~Node()
	{
		if(left != NULL)
			delete left;
		if(right != NULL)
			delete right;
	}
	template<class DATATYPE>
	void Node<DATATYPE>::setLeft(Node<DATATYPE>* n)
	{
		left = n;
	}
	
	template<class DATATYPE>
	void Node<DATATYPE>::setRight(Node<DATATYPE>* n)
	{
		right = n;
	}
	
	template<class DATATYPE>
	void Node<DATATYPE>::setParent(Node<DATATYPE>* p)
	{
		parent = p;
	}
	
	template<class DATATYPE>
	void Node<DATATYPE>::setData(const DATATYPE& d)
	{
		data = d;
	}
	
	template<class DATATYPE>
	void Node<DATATYPE>::setBalance(const int& i)
	{
		balance = i;
	}
	
	template<class DATATYPE>
	Node<DATATYPE>* Node<DATATYPE>::getRight() const
	{
		return right;
	}	
	
	template<class DATATYPE>
	Node<DATATYPE>* Node<DATATYPE>::getLeft() const
	{
		return left;
	}
	
	template<class DATATYPE>
	Node<DATATYPE>* Node<DATATYPE>::getParent() const
	{
		return parent;
	}
	
	template<class DATATYPE>
	DATATYPE Node<DATATYPE>::getData() const
	{
		return data;
	}
	
	template<class DATATYPE>
	int Node<DATATYPE>::getBalance() const
	{
		return balance;
	}
	
	template<class DATATYPE>
	void Node<DATATYPE>::incrementB()
	{
		balance++;
	}
	
	template<class DATATYPE>
	void Node<DATATYPE>::decrementB()
	{
		balance--;
	}


}

#endif
