#ifndef BST_CPP
#define BST_CPP

#include <iostream>
#include "BST.h"

using namespace std;

namespace si221
{
	template<class DATATYPE>
	BST<DATATYPE>::BST()
	{
		root = NULL;
		size = 0;
	}
	template<class DATATYPE>
	BST<DATATYPE>::~BST()
	{
		if(root != NULL)
			delete root;
	}
	template<class DATATYPE>
	void BST<DATATYPE>::insert(const DATATYPE& d)
	{
		size++;
		bool doTraverse = true;
		Node<DATATYPE>* newnode = new Node<DATATYPE>(d);
		Node<DATATYPE>* traverse = root;
		
		if(root == NULL)
		{
			root = newnode;
		}
		else
		{
			while(doTraverse)
			{
				if(traverse->getData() < d && traverse->getRight() != NULL)
				{
					traverse = traverse->getRight();
				}
				else if(traverse->getData() < d && traverse->getRight() == NULL)
				{
					traverse->setRight(newnode);
					newnode->setParent(traverse);
					doTraverse = false;
				}
				else if(traverse->getData() >= d && traverse->getLeft() != NULL)
				{
					traverse = traverse->getLeft();
				}
				else if(traverse->getData() >= d && traverse->getLeft() == NULL)
				{
					traverse->setLeft(newnode);
					newnode->setParent(traverse);
					doTraverse = false;
				}
				else
				{
					cout<<"Error occurred!";
				}
			}
		}
	}
	
	
	
	template<class DATATYPE>
	void BST<DATATYPE>::insert2(const DATATYPE& d)
	{
		size++;
		bool doTraverse = true;
		Node<DATATYPE>* newnode = new Node<DATATYPE>(d);
		Node<DATATYPE>* traverse = root;
		
		if(root == NULL)
		{
			root = newnode;
		}
		else
		{
			while(doTraverse)
			{
				if(traverse->getData() < d && traverse->getRight() != NULL)
				{
					//traverse->setBalance(traverse->getBalance() + 1);
					traverse->incrementB();
					traverse = traverse->getRight();
				}
				else if(traverse->getData() < d && traverse->getRight() == NULL)
				{
					//traverse->setBalance(traverse->getBalance() + 1);
					traverse->incrementB();
					traverse->setRight(newnode);
					newnode->setParent(traverse);
					doTraverse = false;
				}
				else if(traverse->getData() >= d && traverse->getLeft() != NULL)
				{
					//traverse->setBalance(traverse->getBalance() - 1);
					traverse->decrementB();
					traverse = traverse->getLeft();
				}
				else if(traverse->getData() >= d && traverse->getLeft() == NULL)
				{
					//traverse->setBalance(traverse->getBalance() - 1);
					traverse->decrementB();
					traverse->setLeft(newnode);
					newnode->setParent(traverse);
					doTraverse = false;
				}
				else
				{
					cout<<"Error occurred!";
				}
			}
		}
	}
	
	
	
	
	
	
	
	template<class DATATYPE>
	void BST<DATATYPE>::visitInOrder()
	{
		visitInOrder(root);
	}
	template<class DATATYPE>
	void BST<DATATYPE>::visitInOrder(Node<DATATYPE>* node)
	{
		if(node == NULL)
			return;
		
		visitInOrder(node->getLeft());
		cout<<node->getData() << "(" << node->getBalance() << ")" << " ";
		visitInOrder(node->getRight());
	}
	template<class DATATYPE>
	void BST<DATATYPE>::visitPre()
	{
		visitPre(root, 0);
	}
	template<class DATATYPE>
	void BST<DATATYPE>::visitPre(Node<DATATYPE>* node, int height)
	{
		if(node == NULL)
		{
			for(int i = 0; i < height; i++)
			{
			
			}
		}
	}
	template<class DATATYPE>
	void BST<DATATYPE>::visitPost()
	{
		visitPost(root);
	}
	template<class DATATYPE>
	void BST<DATATYPE>::visitPost(Node<DATATYPE>* node)
	{
		if(node == NULL)
			return;
		
		visitInOrder(node->getLeft());	
		visitInOrder(node->getRight());
		cout<<node->getData() << " ";
	}
	template<class DATATYPE>
	int BST<DATATYPE>::search(const DATATYPE& d)
	{
		int retval = 0;
		Node<DATATYPE>* traverse = root;
		
		while(traverse != NULL)
		{
			if(traverse->getData() == d)
			{
				retval++;
				traverse = traverse->getLeft();
			}
			else if(traverse->getData() > d)
				traverse = traverse->getLeft();
			else if(traverse->getData() < d)
				traverse = traverse->getRight();
		}
		
		return retval;
	}
	template<class DATATYPE>
	void BST<DATATYPE>::remove(const DATATYPE& d)
	{
		Node<DATATYPE>* remove;
		Node<DATATYPE>* swap;
		bool isFound = false;
		bool removing = true;
		
		remove = root;
		
		while(remove != NULL && !isFound)
		{
			if(remove->getData() == d)
			{
				isFound = true;
			}
			else if(remove->getData() > d)
			{
				remove = remove-> getLeft();
			}
			else if(remove->getData() < d)
			{
				remove = remove->getRight();
			}
		}
		
		
		//Catch phrase for removing BSTs
		//Go left Slice Right
		
		if(isFound)
		{
			while(removing)
			{
				swap = remove->getLeft();
			
				if(swap != NULL)
				{
					while(swap->getRight() != NULL)
					{
						swap = swap->getRight();
					}
				
					remove->setData(swap->getData());
					remove = swap;
				}
				else if(remove->getRight() != NULL)
				{
					swap = remove->getRight();
					while(swap->getLeft() != NULL)
					{
						swap = swap->getLeft();
					}
					remove->setData(swap->getData());
					remove = swap;
				}
				else
				{
					if(remove != root)
					{
						if(remove->getParent()->getLeft() == remove)
							remove->getParent()->setLeft(NULL);
						else if(remove->getParent()->getRight() == remove)
							remove->getParent()->setRight(NULL);
					}
					
					size--;
					delete remove;
					
					if(size == 0)
						root = NULL;
						
					removing = false;
				}
			}
		}
	}
	
	
	
	template<class DATATYPE>
	void BST<DATATYPE>::rightRotate(Node<DATATYPE>* A, Node<DATATYPE>* B, Node<DATATYPE>* C)
	{
		A->setRight(B->getLeft());
		B->setLeft(A);
	}
	template<class DATATYPE>
	void BST<DATATYPE>::leftRotate(Node<DATATYPE>* A, Node<DATATYPE>* B, Node<DATATYPE>* C)
	{
		A->setLeft(B->getRight());
		B->SetRight(A);
	}
	template<class DATATYPE>
	void BST<DATATYPE>::leftRightRotate(Node<DATATYPE>* A, Node<DATATYPE>* B, Node<DATATYPE>* C)
	{
		A->setRight(C->getLeft());
		C->setLeft(A);
		B->setLeft(C->getRight());
		C->setRight(B);
	}
	template<class DATATYPE>
	void BST<DATATYPE>::rightLeftRotate(Node<DATATYPE>* A, Node<DATATYPE>* B, Node<DATATYPE>* C)
	{
		A->setLeft(C->getRight());
		C->setRight(A);
		B->setRight(C->getLeft());
		C->setLeft(B);
	}
}


#endif































