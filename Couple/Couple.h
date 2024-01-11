#pragma once

#include <vector>
#include "../Card/Card.h"

#ifndef COUPLE_H
#define COUPLE_H

class Couple
{
public:
	std::vector<Card> cards;

	Couple(std::vector<Card> cards);

	bool CheckCard(CardsValue cardValue);

	bool operator ==(const Couple* couple) const;
};

#endif
