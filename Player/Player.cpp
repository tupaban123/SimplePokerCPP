#include "Player.h"
#include <iostream>
#include "../Card/Card.h"

Player::Player(std::vector<Card> cards, std::string& name) : name(name)
{
	this->cards = cards;
}

Card* Player::GetHighCardFromHand()
{
	if (Player::cards.size() == 0)
	{
		std::cout << "player hand is empty" << std::endl;
		return nullptr;
	}

	Card* highestCard = &Player::cards[0];

	for (std::vector<Card>::iterator i = Player::cards.begin() + 1; i != Player::cards.end(); i++)
	{
		Card* currentCard = &(*i);

		if (currentCard->cardValue > highestCard->cardValue)
			highestCard = currentCard;
	}

	return highestCard;
}

Combinations Player::GetCombination(std::vector<Card> tableDeck)
{
	CombinationsFinder cf = CombinationsFinder();

	for (auto& card : cards)
		tableDeck.push_back(card);

	return cf.CalculateCombination(tableDeck);
}