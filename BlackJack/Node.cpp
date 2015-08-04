#ifndef NODE_CPP
#define NODE_CPP

#include "Node.h"

namespace si221
{
	template<class DATATYPE>
	DATATYPE Node<DATATYPE>::getData() const
	{
		return data;
	}
	template<class DATATYPE>
	Node<DATATYPE>* Node<DATATYPE>::getNext() const
	{
		return next;
	}
	template<class DATATYPE>
	Node<DATATYPE>* Node<DATATYPE>::getPrev() const
	{
		return prev;
	}		
	template<class DATATYPE>
	void Node<DATATYPE>::setData(const DATATYPE& d)
	{
		data = d;
	}
	template<class DATATYPE>
	void Node<DATATYPE>::setNext(Node<DATATYPE>* n)
	{
		next = n;
	}
	template<class DATATYPE>
	void Node<DATATYPE>::setPrev(Node<DATATYPE>* p)
	{
		prev = p;
	}
	
	
}

#endif
