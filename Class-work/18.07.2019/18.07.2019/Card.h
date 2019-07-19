#pragma once
class Card
{
public:
	enum card { C6=0, C7, C8, C9, C10, J, Q, K, ACE };
	enum suit {Diamonds=0,Spades,Clubs,Hearts};
	Card(card CARD,suit SUIT)
	{
		this->CARD = CARD;
		this->SUIT = SUIT;
	}
	Card(){}
	card Get_card()
	{
		return this->CARD;
	}
	void Set_card(card CARD)
	{
		this->CARD=CARD;
	}
	suit Get_suit()
	{
		return this->SUIT;
	}
	void Set_suit(suit SUIT)
	{
		this->SUIT = SUIT;
	}
	void operator()(card CARD, suit SUIT)
	{
		this->CARD = CARD;
		this->SUIT = SUIT;
	}
	bool operator > (const Card &other)const
	{
		return this->CARD > other.CARD &&this->SUIT > other.SUIT;
	}
	bool operator < (const Card &other)const
	{
		return !(*this > other);
	}
	friend std::ostream& operator<< (std::ostream &out, const Card &point);
private:
	card CARD;
	suit SUIT;
};

std::ostream& operator<< (std::ostream &out, const Card &point)
{
	out << "dsfs" << "\t" << "sds" << std::endl;
	return out;
}