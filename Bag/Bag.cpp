#include "Bag.h"

namespace bagnamespace
{
	const Bag::size_type Bag::CAPACITY;

	Bag::Bag()
	{
		used = 0;
	}
	Bag::~Bag()
	{
		 
	}		
	void Bag::insert(const value_type& entry)
	{
		assert(size() < CAPACITY);
		data[used] = entry;
		++used;
	}
	Bag::size_type Bag::count(const value_type& target) const
	{
		size_type answer = 0;
		size_type i;
		for(i = 0; i < used; ++i)
		{
			if(target==data[i])
			{
				++answer;
			}
		}
		return answer;
	}
	Bag::size_type Bag::size() const
	{
		return used;
	}
	Bag::size_type Bag::erase(const value_type& target)
	{
		size_type x = count(target);
		size_type i;
		for(i = 0; i < x; ++i)
		{
			bool b = erase_one(target);
		}
		return x;
	}
	bool Bag::erase_one(const value_type& target)
	{
		size_type index = 0;
		while((index<used) && (data[index] != target))
		{
			++index;
		}
		if (index == used)
		{
			return false;
		}
		--used;
		data[index] = data[used];
		return true;
	}
	void Bag::operator +=(const Bag& addend)
	{
		assert(size() + addend.size() <= CAPACITY);
		
		std::copy(addend.data, addend.data+addend.used, data+used);
		used += addend.used;
	}
	Bag operator +(const Bag& b1, const Bag& b2)
	{
		Bag b3;
		assert(b1.size() + b2.size() <= Bag::CAPACITY);
		b3 += b1;
		b3 += b2;
		
		return b3;
	}
	Bag::value_type getData(const value_type& index)
	{
		return data[index];
	}
	void operator -=(const Bag& subend)
	{
		value_type index = 0;
		for(size_type i = 0; i < subend.size(); i++)
		{
			erase_one(subend.getData(index));
			
			index++;
		}
	
	
	}
	Bag operator -(const Bag& b1, const Bag& b2)
	{
		Bag b3;
		if(b1.size() < b2.size())
		{
			return b3;
		}
		else
		{
			Bag b3 += b1;
			Bag b3 -= b2;
			return b3;
		}
		
	}
}










