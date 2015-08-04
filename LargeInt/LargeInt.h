#ifndef LARGEINT_H
#define LARGEINT_H
#include <cassert>
#include <algorithm>
#include <iostream>
#include <string>

namespace largeintnamespace
{
	class LargeInt
	{
		public:
			typedef int value_type;
			typedef std::size_t size_type;
			static const size_type CAPACITY = 5;

			LargeInt();
			~LargeInt();
			value_type data[CAPACITY];
			
			//void insert(const value_type& entry);
			//size_type count(const value_type& target) const;
			//size_type size() const;
			//size_type erase(const value_type& target);
			//bool erase_one(const value_type& target);
			void operator +=(const LargeInt& addend);
			void operator -=(const LargeInt& subend);
			friend std::ostream& operator<<(std::ostream& OUT, const LargeInt& l);
      		friend std::istream& operator>>(std::istream& IN, LargeInt& l);
			
		private:
			
			size_type dataIndex;
	};
	
	LargeInt operator +(const LargeInt& l1, const LargeInt& l2);
	//LargeInt operator -(const LargeInt& l1, const LargeInt& l2);
}
#endif
