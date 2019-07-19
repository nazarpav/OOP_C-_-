#include "CardDeck.h"
#include<vector>
#include<string>
#include<ctime>
#include<iostream>
#include<algorithm>
#include<iterator>
#include"Card.h"
using namespace std;


void CardDeck::Init()
{
	Card::card card_;
	Card::suit suit_;
	Card tmp;
	const short card1_4 = 9;
	for (size_t i = 0; i < card1_4; i++)
	{
		tmp((Card::card)i, Card::suit::Diamonds);
		CardDeck_.push_back(tmp);
	}
	for (size_t i = 0; i < card1_4; i++)
	{
		tmp((Card::card)i, Card::suit::Spades);
		CardDeck_.push_back(tmp);
	}
	for (size_t i = 0; i < card1_4; i++)
	{
		tmp((Card::card)i, Card::suit::Clubs);
		CardDeck_.push_back(tmp);
	}
	for (size_t i = 0; i < card1_4; i++)
	{
		tmp((Card::card)i, Card::suit::Hearts);
		CardDeck_.push_back(tmp);
	}
}

void CardDeck::Print_Deck()
{
	for (size_t i = 0; i < CardDeck_.size(); i++)
	{
		cout<<CardDeck_[i];
	}
}

void CardDeck::Shuffle_Deck()
{
	srand(unsigned(time(NULL)));
	random_shuffle(CardDeck_.begin(), CardDeck_.end());
}

void CardDeck::Sort_Deck()
{
	sort(CardDeck_.begin(), CardDeck_.end());
}

CardDeck::CardDeck()
{
	Init();
}


