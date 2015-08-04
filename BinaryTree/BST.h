#ifndef BST_H
#define BST_H

#include <cstdlib>
#include "Node.h"
#include "Node.cpp"

namespace si221
{
	template <class DATATYPE>
	class BST
	{
		public:
			typedef size_t size_type;
			
			BST();
			~BST();
			
			//INSERT and PRINT
			void insert(const DATATYPE& d);
			void insert2(const DATATYPE& d);
			void visitInOrder();
			void visitPre();
			void visitPost();
			void rightRotate(Node<DATATYPE>* A, Node<DATATYPE>* B, Node<DATATYPE>* C);
			void leftRotate(Node<DATATYPE>* A, Node<DATATYPE>* B, Node<DATATYPE>* C);
			void leftRightRotate(Node<DATATYPE>* A, Node<DATATYPE>* B, Node<DATATYPE>* C);
			void rightLeftRotate(Node<DATATYPE>* A, Node<DATATYPE>* B, Node<DATATYPE>* C);
			
			int search(const DATATYPE& d);
			void remove(const DATATYPE& d);
			
		private:
			Node<DATATYPE>* root;
			size_type size;
			
			void visitInOrder(Node<DATATYPE>* node);
			void visitPre(Node<DATATYPE>* node, int height);
			void visitPost(Node<DATATYPE>* node);
	};

}

#endif
