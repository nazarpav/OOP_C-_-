#pragma once
#include<vector>
#include<string>
#include<stack>
#include<iostream>
#include"Card.h"
using namespace std;
class CardDeck
{
	vector<Card>CardDeck_;
	void Init();
public:
	void Print_Deck();
	void Shuffle_Deck();
	Card PickCard()
	{
		return CardDeck_[CardDeck_.size()-1];
	}
	Card PopCard()
	{
		Card tmp = CardDeck_[CardDeck_.size() - 1];
		CardDeck_.pop_back();
		return tmp;
	}
	void Sort_Deck();
	CardDeck();
};

