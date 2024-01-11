#include "Couple.h"

Couple::Couple(std::vector<Card> cards)
{
	this->cards = cards;
}

bool Couple::CheckCard(CardsValue cardValue)
{
	for (auto& card : cards)
	{
		if (card.cardValue == cardValue)
			return true;
	}

	return false;
}

bool Couple::operator ==(const Couple* couple) const
{
	if (cards.size() != couple->cards.size())
		return false;

	for (int i = 0; i < cards.size(); i++)
	{
		if ((cards[i].cardValue != couple->cards[i].cardValue) || (cards[i].suit != couple->cards[i].suit))
			return false;
	}

	return true;
}