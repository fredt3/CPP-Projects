#ifndef NODE_H
#define NODE_H



namespace si221
{
	template<class DATATYPE>
	class Node
	{
		public:
			DATATYPE getData() const;
			Node<DATATYPE>* getNext() const;
			Node<DATATYPE>* getPrev() const;
			
			void setData(const DATATYPE& d);
			void setNext(Node<DATATYPE>* n);
			void setPrev(Node<DATATYPE>* p);
			
		
		private:
			DATATYPE data;
			Node<DATATYPE>* next;
			Node<DATATYPE>* prev;
	};
}

#endif
