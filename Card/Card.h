#pragma once

#ifndef CARD_H
#define CARD_H

#include <map>
#include "../CardsValue.h"
#include "../Suits.h"
#include <string>

class Card
{
public:
	CardsValue cardValue;
	Suits suit;

	Card(CardsValue cardValue, Suits suit);
};
#endif
