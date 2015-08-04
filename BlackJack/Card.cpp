#ifndef CARD_CPP
#define CARD_CPP

#include <sstream>
#include "Card.h"

using namespace std;

namespace si221
{
	const char Card::HEARTS_SYMBOL[] = "\xe2\x99\xa5";
	const char Card::CLUBS_SYMBOL[] = "\xe2\x99\xa3";
	const char Card::SPADES_SYMBOL[] = "\xe2\x99\xa0";
	const char Card::DIAMONDS_SYMBOL[] = "\xe2\x99\xa6";
		
	Card::Card(int s, int fV, int pV)
	{
		suit = s;
		faceValue = fV;
		pointValue = pV;
	}
	Card::Card()
	{
	
	}
	Card::~Card()
	{
	
	}
		
	std::string Card::toString() const
	{
		stringstream retval;
		
		if(faceValue == 1)
			retval<<'A';
		else if(faceValue == 11)
			retval<<'J';
		else if(faceValue == 12)
			retval<<'Q';
		else if(faceValue == 13)
			retval<<'K';
		else
			retval<<faceValue;
		
		if(suit == CLUBS)
			retval<<CLUBS_SYMBOL;
		else if(suit == DIAMONDS)
			retval<<DIAMONDS_SYMBOL;
		else if(suit == SPADES)
			retval<<SPADES_SYMBOL;
		else if(suit == HEARTS)
			retval<<HEARTS_SYMBOL;
				
		return retval.str();
	}
	
	//Getters
	int Card::getSuit() const
	{
		return suit;
	}
	int Card::getFaceValue() const
	{
		return faceValue;
	}
	int Card::getPointValue() const 
	{
		return pointValue;
	}
	
	//Setters
	void Card::setSuit(int s)
	{
		suit = s;
	}
	void Card::setFaceValue(int fV)
	{
		faceValue = fV;
	}
	void Card::setPointValue(int pV)
	{
		pointValue = pV;
	}
	void Card::setCard(int s, int fV, int pV)
	{
		suit = s;
		faceValue = fV;
		pointValue = pV;
	}
	
	bool operator > (const Card& c1, const Card& c2)
	{
		bool retval = false;
		
		if(c1.getSuit() > c2.getSuit())
			retval = true;
		else if(c1.getSuit() < c2.getSuit())
			retval = false;
		else
		{
			if(c1.getFaceValue() > c2.getFaceValue())
				retval = true;
		}
		
		return retval;
	}
	
	ostream& operator << (ostream& out, const Card& c)
	{
		if(c.faceValue == 1)
			out<<'A';
		else if(c.faceValue == 11)
			out<<'J';
		else if(c.faceValue == 12)
			out<<'Q';
		else if(c.faceValue == 13)
			out<<'K';
		else
			out<<c.faceValue;
		
		if(c.suit == Card::CLUBS)
			out<<Card::CLUBS_SYMBOL;
		else if(c.suit == Card::DIAMONDS)
			out<<Card::DIAMONDS_SYMBOL;
		else if(c.suit == Card::SPADES)
			out<<Card::SPADES_SYMBOL;
		else if(c.suit == Card::HEARTS)
			out<<Card::HEARTS_SYMBOL;
		return out;
	}
	istream& operator >> (istream& in, const Card& c)
	{	
		return in;
	}
}

#endif 
