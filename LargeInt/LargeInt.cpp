#include "LargeInt.h"

namespace largeintnamespace
{
	const LargeInt::size_type LargeInt::CAPACITY;

	LargeInt::LargeInt()
	{
		//dataIndex = LargeInt::CAPACITY - 1;
		for(size_type i = 0; i < LargeInt::CAPACITY; i++)
		{
			data[i] = 0;
		}
		//dataIndex = 0;
	}
	LargeInt::~LargeInt()
	{
		 
	}		
	void LargeInt::operator +=(const LargeInt& addend)
	{
		LargeInt l;
		l = addend;
		for(size_type i = 0; i < LargeInt::CAPACITY ; i++)
		{
			l.data[i] = data[i] + l.data[i];
			if((l.data[i] >= 10) && (i != LargeInt::CAPACITY - 1))
			{
				l.data[i] -= 10;
				l.data[i+1] += 1;
			}
		}
		std::copy(l.data, l.data+LargeInt::CAPACITY, data);
	}
	LargeInt operator +(const LargeInt& l1, const LargeInt& l2)
	{
		LargeInt l3;
				
		l3 += l1;
		l3 += l2;
		
		return l3;
	}
	void LargeInt::operator -=(const LargeInt& subend)
	{
		LargeInt l;
		l = subend;
		for(size_type i = 0; i < LargeInt::CAPACITY ; i++)
		{
			l.data[i] = data[i] - l.data[i];
			if((l.data[i] < 0) && (i != LargeInt::CAPACITY - 1))
			{
				l.data[i] += 10;
				l.data[i-1] -= 1;
			}
		}
		std::copy(l.data, l.data+LargeInt::CAPACITY, data);
	}
/*	LargeInt operator -(const LargeInt& l1, const LargeInt& l2)
	{
		LargeInt l3;
		if(l1.size() < l2.size())
		{
			return l3;
		}
		else
		{
			l3 += l1;
			l3 -= l2;
			return l3;
		}
		
	}*/
	std::ostream& operator<<(std::ostream &OUT, const LargeInt& l)
    { 
    	for(LargeInt::size_type i = 0; i < LargeInt::CAPACITY; i++) 
        {
        	OUT << l.data[LargeInt::CAPACITY - 1 - i];
        }
        return OUT;            
    }
    std::istream& operator>>(std::istream &IN, LargeInt& l)
    { 
    	LargeInt::value_type x = 0;
    	std::string s;
    	IN >> s;
    	for(LargeInt::size_type i = 0; i < LargeInt::CAPACITY; i++)
        {
        	
        	//x = LargeInt::value_type(c);
        	l.data[LargeInt::CAPACITY - 1 -i] = s[i] - 48;
        }
        return IN;            
    }
}










