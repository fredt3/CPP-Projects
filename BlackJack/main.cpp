#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Card.h"
#include "LinkedList.h"
#include "LinkedList.cpp"

using namespace std;
using namespace si221;

template<class DATATYPE>
DATATYPE maximum(DATATYPE a, DATATYPE b);

LinkedList<Card> createDeck();
void shuffle(LinkedList<Card>& deck);
void draw(LinkedList<Card>& deck, LinkedList<Card>& ll);
int pointVal(LinkedList<Card>& ll);

int main()
{
	system("clear");

	srand(time(0));
	//Declare my initial Deck
	LinkedList<Card> deck = createDeck();
	LinkedList<Card> player;
	LinkedList<Card> dealer;
	LinkedList<Card> trash = createDeck();
	
	char c = 'h';
	int gamesD = 0;
	int gamesP = 0;
	double account = 500.00;
	double bet = 0;
	
	
	do{
		cout << "Amount to bet: " << account << endl;
		cout << "How much would you like to bet? ";
		cin >> bet;
		while(bet > account)
		{
			cout << "Please enter a valid bet: ";
			cin >> bet;
		}
		draw(deck, player);
		draw(deck, dealer);
		draw(deck, player);
		draw(deck, dealer);
		
		cout<<endl<<player.toString();
	
		while(pointVal(player) < 21)
		{
			cout << endl << "Would you like to Hit (h) or Stay (s): ";
			cin >> c;
			system("clear");
			
			if(c == 'h')
			{
				draw(deck, player);
				cout<<endl<<player.toString();
			}
			else
			{
				break;
			}
		}
	
		if(pointVal(player) <= 21)
		{	if(pointVal(dealer) < pointVal(player))
			{	
				while(pointVal(dealer) < 17)
				{
					draw(deck, dealer);
				}
			}
		}
	
		system("clear");
		cout<<endl<<endl<<endl<<"Player Hand:"<<endl;
		cout<<player.toString();
		cout<<pointVal(player)<<endl<<endl;
		cout<<endl<<endl<<endl<<"Dealer Hand:"<<endl;
		cout<<dealer.toString();
		cout<<pointVal(dealer)<<endl;
	
		if((pointVal(dealer)>=pointVal(player) && pointVal(dealer) <= 21) || pointVal(player)>21)
		{
			cout<<endl<<"Dealer Wins"<<endl;
			gamesD++;
			account -= bet;
		}
		if((pointVal(player)>pointVal(dealer) && pointVal(player) <= 21) || pointVal(dealer)>21)
		{
			cout<<endl<<"Player Wins"<<endl;
			gamesP++;
			account += bet;
		}
		
		cout << endl<< "Dealer: " << gamesD << endl;
		cout << "Player: " << gamesP<<endl;
		cout << endl << "Account balance: " << account;
		cout<<endl<<"Play Again? Yes(y) or No(n): ";
		cin >> c;
		system("clear");
		if(c == 'y')
		{
			deck.emptyAllIntoThisList(player);
			deck.emptyAllIntoThisList(dealer);
			trash.emptyAllIntoThisList(deck);
			deck = createDeck();
		}
		
		
	
	}while(c == 'y');
	
	cout<<deck.toString();
	
	return EXIT_SUCCESS;
}

template<class DATATYPE>
DATATYPE maximum(DATATYPE a, DATATYPE b)
{
	DATATYPE retval;
	
	if(a>b)
		retval = a;
	else if(b>a)
		retval = b;
	else
		retval = a;
		
	return retval;
}

LinkedList<Card> createDeck()
{
	LinkedList<Card> deck;
	Card c;
	for(int i = 0; i < 4; i++)
	{
		for(int j = 1; j < 14; j++)
		{
			if(j==11 || j==12 || j==13)
			{
				c.setCard(i, j, 10);
			}
			else
			{
				c.setCard(i, j, j);
			}
			deck.insertTop(c);
		}
	}
	shuffle(deck);
	return deck;
}

void shuffle(LinkedList<Card>& deck)
{
	Card c;
	int random = rand() % deck.getSize();

	for(int i = 0; i < 200; i++)
	{
		c = deck.removeAt(random);
		deck.insertTop(c);
		random = rand() % deck.getSize(); 
	}
}

void draw(LinkedList<Card>& deck, LinkedList<Card>& ll)
{
	Card c;
	c = deck.removeTop();
	ll.insertTop(c);
}

int pointVal(LinkedList<Card>& ll)
{
	int retval = 0;
	const Node<Card>* temp = ll.getHead();
	bool ace = false;
	
	for(int i = 0; i < ll.getSize(); i++)
	{
		int points = temp->getData().getPointValue();
		if(points == 1)
		{
			ace = true;
		}
		retval += points;
		temp = temp->getNext();
	}
	
	if(ace && retval + 10 <= 21)
	{
		retval += 10;
	}
	
	return retval;
}
























