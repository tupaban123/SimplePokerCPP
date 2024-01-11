#pragma once

#include "../Combinations.h"
#include <vector>
#include <string>
#include "E:/Programming/SimplePoker/Card/Card.h"
#include "E:/Programming/SimplePoker/Couple/Couple.h"

#ifndef COMBINATIONSFINDER_H
#define COMBINATIONSFINDER_H

class CombinationsFinder
{
private:


public:
	Combinations CalculateCombination(std::vector<Card>& cards);
	Card* GetHighCard(std::vector<Card>& cards);


	void SortCardsByValue(std::vector<Card>& cards);
	void SortCardsBySuits(std::vector<Card>& cards);
	std::vector<Couple> SortToCouples(std::vector<Card>& cards);

	Combinations isPairsCombination(std::vector<Card>& cards);

	bool isStraight(std::vector<Card>& cards);

	bool isFlush(std::vector<Card>& cards);

	bool isStraightFlush(std::vector<Card>& cards);

	bool isRoyal(std::vector<Card>& cards);

	bool isRoyalFlush(std::vector<Card>& cards);
};

#endif