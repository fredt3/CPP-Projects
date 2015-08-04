#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <cstdlib>
#include "Node.h"
#include "Node.cpp"
#include <ostream>
#include <sstream>

namespace si221
{
	template<class DATATYPE>
	class LinkedList
	{
		public:
			typedef std::size_t size_type;
		
			//Constructors/Deconstructors
			LinkedList();
			LinkedList(const LinkedList& copy);
			~LinkedList();
			
			//Operators
			void operator=(const LinkedList& copy);
			void operator+=(const LinkedList& list);
			
			//Insert functions
			void insertTop(const DATATYPE& d);
			void insertBottom(const DATATYPE& d);
			void insertAt(const DATATYPE& d, size_type index);
			
			//Remember to delete nodes in these functions!
			DATATYPE removeTop();
			DATATYPE removeBottom();
			DATATYPE removeAt(size_type index);
			
			//Takes all of l1 and empties it into the 'this' list
			void emptyAllIntoThisList(LinkedList& l1);
			
			//Getters
			size_type getSize() const;
			const Node<DATATYPE>* getHead() const;
			const Node<DATATYPE>* getTail() const; 
			
			std::string toString() const;
			//Friend Functions
			//friend std::ostream& operator<< <> (std::ostream& out, const LinkedList<DATATYPE>& l);
			
		private:
			Node<DATATYPE>* head;
			Node<DATATYPE>* tail;
			size_type size;
	};
	template<class DATATYPE>
	LinkedList<DATATYPE> operator+(const LinkedList<DATATYPE>& l1, const LinkedList<DATATYPE>& l2);
}

#endif 
