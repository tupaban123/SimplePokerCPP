#pragma once

#ifndef PLAYER_H
#define PLAYER_H

#include <vector>
#include "../Card/Card.h"
#include "../Combinations/Finder/CombinationsFinder.h"

class Player
{


public:
	std::string name;
	std::vector<Card> cards;

	Player(std::vector<Card> cards, std::string& name);

	Card* GetHighCardFromHand();

	Combinations GetCombination(std::vector<Card> tableDeck);
};

#endif
