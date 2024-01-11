#include "CombinationsComparator.h"
#include <algorithm>

bool sortPlayersByCombination(const std::pair<Player*, int>& a, const std::pair<Player*, int> b)
{
	return a.second < b.second;
}

Player& CombinationsComparator::CompareCombinations(std::vector<Player>& players, std::vector<Card>& tableDeck)
{
	std::map<Player*, int> playersCombinations;

	for (auto& player : players)
	{
		playersCombinations.insert({ &player, player.GetCombination(tableDeck) });
	}

	std::vector<Player*> highestCombinationPlayers = GetPlayersWithHighestCombinations(playersCombinations);

	if (highestCombinationPlayers.size() == 1)
		return *highestCombinationPlayers[0];

	Player& playerWithHighestCard = *highestCombinationPlayers[0];

	for (int i = 1; i < highestCombinationPlayers.size(); i++)
	{
		int currentPlayerHighCardValue = highestCombinationPlayers[i]->GetHighCardFromHand()->cardValue;

		if (currentPlayerHighCardValue > playerWithHighestCard.GetHighCardFromHand()->cardValue)
			playerWithHighestCard = *highestCombinationPlayers[i];
	}

	return playerWithHighestCard;
}

std::vector<Player*> CombinationsComparator::GetPlayersWithHighestCombinations(std::map<Player*, int>& playersWithCombinations)
{
	std::vector<std::pair<Player*, int>> playersWithCombinationsVector(playersWithCombinations.begin(), playersWithCombinations.end());
	std::sort(playersWithCombinationsVector.begin(), playersWithCombinationsVector.end(), sortPlayersByCombination);


	Combinations highestCombination = static_cast<Combinations>(playersWithCombinationsVector[playersWithCombinationsVector.size() - 1].second);

	std::vector<Player*> playersWithHighestCombination;

	for (auto& pair : playersWithCombinationsVector)
	{
		if (pair.second == highestCombination)
			playersWithHighestCombination.push_back(pair.first);
	}

	return playersWithHighestCombination;
}