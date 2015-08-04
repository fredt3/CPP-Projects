#ifndef CARD_H
#define CARD_H

#include <string>
#include <ostream>
#include <istream>

namespace si221
{
	class Card
	{
		public:
			const static int HEARTS = 2;
			const static int CLUBS = 0;
			const static int SPADES = 3;
			const static int DIAMONDS = 1;
			
			const static char HEARTS_SYMBOL[];
			const static char CLUBS_SYMBOL[];
			const static char SPADES_SYMBOL[];
			const static char DIAMONDS_SYMBOL[];
				
			//Constructor		
			Card(int s, int fV, int pV);
			Card();
			//Deconstructor (doesn't do anything at all)
			~Card();			
			
			//Turn the card into a string for printing purposes
			std::string toString() const;
			
			//Getters
			int getSuit() const;
			int getFaceValue() const;
			int getPointValue() const;
			
			//Setters
			void setSuit(int s);
			void setFaceValue(int fV);
			void setPointValue(int pV);
			void setCard(int s, int fV, int pV);
			
			//Friend Functions
			friend std::ostream& operator << (std::ostream& out, const Card& c);
			friend std::istream& operator >> (std::istream& in, const Card& c);
			
		private:
			int suit;		//Used for the SUIT
			int faceValue; //Used for the 10 in 10 of clubs
			int pointValue;//Used for the value 10 if a king, etc
	};
	
	bool operator > (const Card& c1, const Card& c2);
	
}

#endif 
