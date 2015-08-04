#ifndef LINKEDLIST_CPP
#define LINKEDLIST_CPP

#include "LinkedList.h"
#include <iostream>

using namespace std;

namespace si221
{
	template<class DATATYPE>
	LinkedList<DATATYPE>::LinkedList()
	{
		head = NULL;
		tail = NULL;
		size = 0;
	}
	template<class DATATYPE>
	LinkedList<DATATYPE>::LinkedList(const LinkedList& copy)
	{
		head = NULL;
        tail = NULL;
        size = 0;
       
        Node<DATATYPE>* temp = copy.head;
        for(size_type i=0; i<copy.size; i++)
        {
            insertTop(temp->getData());
            temp = temp->getNext();
        }
	}
	template<class DATATYPE>
	LinkedList<DATATYPE>::~LinkedList()
	{
		Node<DATATYPE>* temp = head;
		
		while(head != NULL)
		{
			head = head->getNext();
			delete temp;
			temp = head;
		}	
	}
	template<class DATATYPE>
	void LinkedList<DATATYPE>::operator=(const LinkedList& copy)
	{
		Node<DATATYPE>* temp = head;
		
		while(head != NULL)
		{
			head = head->getNext();
			delete temp;
			temp = head;
		}	
		
		head = NULL;
        tail = NULL;
        size = 0;
       
        temp = copy.head;
        for(size_type i=0; i<copy.size; i++)
        {
            insertTop(temp->getData());
            temp = temp->getNext();
        }
	}
	template<class DATATYPE>
	void LinkedList<DATATYPE>::operator+=(const LinkedList& list)
	{
		const Node<DATATYPE>* temp = new Node<DATATYPE>();
		temp = list.getHead();
		for(size_type i = 0; i < list.getSize() - 1; i++)
		{
			insertBottom(temp->getData());
			temp = temp->getNext();
		}
		
		insertBottom(temp->getData());
	}
	template<class DATATYPE>
	LinkedList<DATATYPE> operator+(const LinkedList<DATATYPE>& l1, const LinkedList<DATATYPE>& l2)
	{
		LinkedList<DATATYPE> ll;
		ll += l1;
		ll += l2;
		return ll;
	}	
	template<class DATATYPE>	
	void LinkedList<DATATYPE>::insertTop(const DATATYPE& d)
	{
		size++;
		Node<DATATYPE>* temp = new Node<DATATYPE>();
		temp->setData(d);
		
		if(head == NULL)
		{
			temp->setNext(NULL);
			temp->setPrev(NULL);
			head = temp;
			tail = temp;	
		}
		else
		{
			temp->setPrev(NULL);
			temp->setNext(head);			
			head->setPrev(temp);
			head = temp;
		}
	}
	template<class DATATYPE>
	void LinkedList<DATATYPE>::insertBottom(const DATATYPE& d)
	{
		size++;
		Node<DATATYPE>* temp = new Node<DATATYPE>();
		temp->setData(d);
		
		if(head == NULL)
		{
			temp->setNext(NULL);
			temp->setPrev(NULL);
			head = temp;
			tail = temp;	
		}
		else
		{
			temp->setPrev(tail);
			temp->setNext(NULL);			
			tail->setNext(temp);
			tail = temp;
		}
	}
	template<class DATATYPE>
	void LinkedList<DATATYPE>::insertAt(const DATATYPE& d, size_type index)
	{
		if(index == 0)
			insertTop(d);
		else if(index == getSize())
			insertBottom(d);	
		else if(index < getSize())
		{
			Node<DATATYPE>* llhead = new Node<DATATYPE>();
			llhead = head;
			Node<DATATYPE>* temp = new Node<DATATYPE>();
			temp->setData(d);
		
			//go through list
			for(size_type i = 0; i < index - 1; i++)
			{
				head = head->getNext();
			}
			
			temp->setPrev(head);
			temp->setNext(head->getNext());
			head->setNext(temp);
			head = head->getNext()->getNext();
			head->setPrev(temp);
	
			head = llhead;
			size++;
		}
	}
	template<class DATATYPE>
	DATATYPE LinkedList<DATATYPE>::removeTop()
	{
		Node<DATATYPE>* temp = new Node<DATATYPE>();
		temp = head;
		DATATYPE c;
		c = head->getData();
		head = head->getNext();
		delete temp;
		size--;
		
		return c;
	}
	template<class DATATYPE>
	DATATYPE LinkedList<DATATYPE>::removeBottom()
	{
		Node<DATATYPE>* temp = new Node<DATATYPE>();
		temp = tail;
		DATATYPE c;
		c = tail->getData();
		tail = tail->getPrev();
		delete temp;
		tail->setNext(NULL);
		size--;
	}
	template<class DATATYPE>
	DATATYPE LinkedList<DATATYPE>::removeAt(size_type index)
	{
		if(index == 0)
		{
			removeTop();
		}
		else if(index == size - 1)
		{
			removeBottom();
		}
		else
		{ 
			Node<DATATYPE>* llhead = new Node<DATATYPE>();
			llhead = head;
			
			
			
			//go through list
			for(size_type i = 0; i < index - 1; i++)
			{
				head = head->getNext();
			}
			
			Node<DATATYPE>* temp = new Node<DATATYPE>();
			temp = head->getNext();
			
			DATATYPE c;
			c = temp->getData();
			
			head->setNext(head->getNext()->getNext());
			head = head->getNext();
			head->setPrev(head->getPrev()->getPrev());
			head = llhead;
		
			size--;
			delete temp;
			
			return c;
		}
	}	
	template<class DATATYPE>		
	void LinkedList<DATATYPE>::emptyAllIntoThisList(LinkedList& l1)
	{
		tail->setNext(l1.head);
		l1.head->setPrev(tail);
		tail = l1.tail;
		
		size += l1.size;
		
		l1.head = NULL;
		l1.tail = NULL;
		l1.size = 0;
		
	}	
	template<class DATATYPE>	
	typename LinkedList<DATATYPE>::size_type LinkedList<DATATYPE>::getSize() const
	{
		return size;
	}
	template<class DATATYPE>
	const Node<DATATYPE>* LinkedList<DATATYPE>::getHead() const
	{
		return head;
	}
	template<class DATATYPE>
	const Node<DATATYPE>* LinkedList<DATATYPE>::getTail() const
	{
		return tail;
	}
	template<class DATATYPE>
	string LinkedList<DATATYPE>::toString() const
	{
		stringstream retval;
		Node<DATATYPE>* t = head;
	
		while(t!=NULL)
		{
			retval<<t->getData();
			retval<<endl;
			t = t->getNext();
		}
		
		return retval.str();
	}
}

#endif
