#ifndef BAG_H
#define BAG_H
#include <cassert>
#include <algorithm>

namespace bagnamespace
{
	class Bag
	{
		public:
			typedef int value_type;
			typedef std::size_t size_type;
			static const size_type CAPACITY = 30;

			Bag();
			~Bag();
			
			void insert(const value_type& entry);
			size_type count(const value_type& target) const;
			size_type size() const;
			size_type erase(const value_type& target);
			bool erase_one(const value_type& target);
			void operator +=(const Bag& addend);
			void operator -=(const Bag& subend);
			value_type getData(const value_type& index);
			
		private:
			value_type data[CAPACITY];
			size_type used;
	};
	
	Bag operator +(const Bag& b1, const Bag& b2);
	Bag operator -(const Bag& b1, const Bag& b2);
}
#endif
