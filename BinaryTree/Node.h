#ifndef NODE_H
#define NODE_H

#include <cstdlib>

namespace si221
{
	template<class DATATYPE>
	class Node
	{	
		public:
			Node(const DATATYPE& d);
			~Node();
			//Getters and setters!
			void setLeft(Node<DATATYPE>* n);
			void setRight(Node<DATATYPE>* n);
			void setData(const DATATYPE& d);
			void setParent(Node<DATATYPE>* p);
			void setBalance(const int& i);
			void incrementB();
			void decrementB();
			
			Node<DATATYPE>* getRight() const;
			Node<DATATYPE>* getLeft() const;
			Node<DATATYPE>* getParent() const;
			int getBalance() const;
			DATATYPE getData() const;
			
		private:
			Node<DATATYPE>* left;
			Node<DATATYPE>* right;
			Node<DATATYPE>* parent;
			int balance;
			DATATYPE data;
	};
}

#endif
