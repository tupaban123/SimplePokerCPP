#pragma once

#include <iostream>
#include <vector>
#include <string>
#include "E:/Programming/SimplePoker/Player/Player.h"

class CombinationsComparator
{
public:
	Player& CompareCombinations(std::vector<Player>& players, std::vector<Card>& tableDeck);

private:
	std::vector<Player*> GetPlayersWithHighestCombinations(std::map<Player*, int>& playersWithCombinations);
};