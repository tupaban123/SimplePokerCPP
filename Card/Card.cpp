#include "iostream"
#include "./Card.h"
#include "../CardsValue.h"
#include "../Suits.h"
#include <string>

Card::Card(CardsValue cardValue, Suits suit)
{
	this->cardValue = cardValue;
	this->suit = suit;
}