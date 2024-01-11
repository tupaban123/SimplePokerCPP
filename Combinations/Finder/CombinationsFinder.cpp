#include "CombinationsFinder.h"
#include <algorithm>
#include <iostream>

void CombinationsFinder::SortCardsByValue(std::vector<Card>& cards)
{
	for (int i = 0; i < cards.size(); i++)
	{
		for (int a = 0; a < cards.size() - 1; a++)
		{
			int cardValueIndex = cards[a].cardValue;
			int nextCardValueIndex = cards[a + 1].cardValue;

			if (cardValueIndex > nextCardValueIndex)
			{
				Card temp = (cards[a + 1]);
				cards[a + 1] = cards[a];
				cards[a] = temp;
			}
		}
	}
}

void CombinationsFinder::SortCardsBySuits(std::vector<Card>& cards)
{
	for (int i = 0; i < cards.size(); i++)
	{
		for (int a = 0; a < cards.size() - 1; a++)
		{
			int cardValueIndex = cards[a].suit;
			int nextCardValueIndex = cards[a + 1].suit;

			if (cardValueIndex > nextCardValueIndex)
			{
				Card temp = (cards[a + 1]);
				cards[a + 1] = cards[a];
				cards[a] = temp;
			}
		}
	}
}

std::vector<Couple> CombinationsFinder::SortToCouples(std::vector<Card>& cards)
{
	SortCardsByValue(cards);

	std::cout << std::endl;

	std::vector<Couple> couples;
	int lastAddedCardIndex = -1;

	for (auto& card : cards)
	{
		int cardIndex = card.cardValue;

		if (cardIndex == lastAddedCardIndex)
		{
			couples[couples.size() - 1].cards.push_back(card);
		}
		else
		{
			std::vector<Card> coupleCards;
			coupleCards.push_back(card);

			Couple couple = Couple(coupleCards);
			couples.push_back(couple);
		}

		lastAddedCardIndex = cardIndex;
	}

	std::vector<int> couplesIndexesToReturn;

	for (int i = 0; i < couples.size(); i++)
	{
		if (couples[i].cards.size() > 1)
			couplesIndexesToReturn.push_back(i);
	}

	std::vector<Couple> couplesToReturn;

	for (const auto& index : couplesIndexesToReturn)
		couplesToReturn.push_back(couples[index]);

	couples.clear();

	return couplesToReturn;
}


Card* CombinationsFinder::GetHighCard(std::vector<Card>& cards)
{
	Card* highCard = &cards[0];

	for (int i = 1; i < cards.size(); i++)
	{
		Card* currentCard = &cards[i];

		if (currentCard->cardValue >= highCard->cardValue)
			highCard = currentCard;
	}

	return highCard;
}


Combinations CombinationsFinder::isPairsCombination(std::vector<Card>& cards)
{
	std::vector<Couple> sortedToCouples = SortToCouples(cards);

	int twoCardsCouples = 0;
	int threeCardsCouples = 0;
	int fourCardsCouples = 0;

	for (auto& couple : sortedToCouples)
	{
		switch (couple.cards.size())
		{
		case 2:
			twoCardsCouples++;
			break;
		case 3:
			threeCardsCouples++;
			break;
		case 4:
			fourCardsCouples++;
			break;
		}
	}

	if (twoCardsCouples != 0 && threeCardsCouples != 0)
		return Combinations::FullHouse;
	else if (fourCardsCouples != 0)
		return Combinations::FourOfAKind;
	else if (threeCardsCouples != 0)
		return Combinations::ThreeOfAKind;
	else if (twoCardsCouples >= 2)
		return Combinations::TwoPair;
	else if (twoCardsCouples != 0)
		return Combinations::Pair;

	return Combinations::HighCard;
}

//bool CombinationsFinder::isPair(std::vector<Couple>& couples)
//{
//	Couple* combinationCouple = GetPair(couples);
//
//	return combinationCouple == NULL ? false : combinationCouple->cards.size() == 2;
//}
//
//Couple* CombinationsFinder::GetPair(std::vector<Couple>& couples)
//{
//	for (auto& couple : couples)
//	{
//		if (couple.cards.size() == 2)
//			return &couple;
//	}
//
//	return NULL;
//}
//
//
//bool CombinationsFinder::isTwoPairs(std::vector<Couple>& couples)
//{
//	std::vector<Couple*> combinationCouples = GetTwoPairs(couples);
//
//	for (auto& couple : combinationCouples)
//	{
//		std::cout << "current couple size: " << couple->cards.size() << std::endl;
//
//		if (couple->cards.size() != 2)
//			return false;
//	}
//
//	return true;
//}
//
//std::vector<Couple*> CombinationsFinder::GetTwoPairs(std::vector<Couple> couples)
//{
//	Couple* firstPair = GetPair(couples);
//
//	/*if (firstPair->cards.size() > 0)
//		couples.erase(std::remove_if(couples.begin(), couples.end(), [firstPair](Couple c)
//			{
//				return &c == firstPair;
//			}), couples.end());
//	*/
//	if (firstPair->cards.size() > 0)
//		couples.erase(std::remove(couples.begin(), couples.end(), firstPair), couples.end());
//
//	Couple* secondPair = GetPair(couples);
//
//	std::vector<Couple*> couplesToReturn{ firstPair, secondPair };
//
//	return couplesToReturn;
//}
//
//
//bool CombinationsFinder::isThreeOfAKind(std::vector<Couple>& couples)
//{
//	Couple* combinationCouple = GetThreeOfAKind(couples);
//
//	return combinationCouple == NULL ? false : combinationCouple->cards.size() == 3;
//}
//
//Couple* CombinationsFinder::GetThreeOfAKind(std::vector<Couple>& couples)
//{
//	for (auto& couple : couples)
//	{
//		if (couple.cards.size() == 3)
//			return &couple;
//	}
//
//	return NULL;
//}
//
//
//bool CombinationsFinder::isFourOfAKind(std::vector<Couple>& couples)
//{
//	Couple* combinationCouple = GetThreeOfAKind(couples);
//
//	return combinationCouple == NULL ? false : combinationCouple->cards.size() == 4;
//}
//
//Couple* CombinationsFinder::GetFourOfAKind(std::vector<Couple>& couples)
//{
//	for (auto& couple : couples)
//	{
//		if (couple.cards.size() == 4)
//			return &couple;
//	}
//
//	return NULL;
//}
//
//
//bool CombinationsFinder::isFullHouse(std::vector<Couple>& couples)
//{
//	std::vector<Couple*> combinationCouples = GetFullHouse(couples);
//
//	for (auto& couple : combinationCouples)
//	{
//		if (couple->cards.size() < 2)
//			return false;
//	}
//
//	return true;
//}
//
//std::vector<Couple*> CombinationsFinder::GetFullHouse(std::vector<Couple>& couples)
//{
//	Couple* pair = GetPair(couples);
//
//	/*if (pair->cards.size() > 0)
//		couples.erase(std::remove_if(couples.begin(), couples.end(), [pair](Couple c)
//			{
//				return c == *pair;
//			}), couples.end());*/
//
//	Couple* threeOfAKind = GetThreeOfAKind(couples);
//
//	std::vector<Couple*> couplesToReturn{ pair, threeOfAKind };
//
//	return couplesToReturn;
//}


bool CombinationsFinder::isStraight(std::vector<Card>& cards)
{
	SortCardsByValue(cards);

	//int lastCardValue = -1;
	int straightCount = 1;

	for (int i = 0; i < cards.size() - 1; ++i)
	{
		if (cards[i + 1].cardValue - cards[i].cardValue == 1)
		{
			straightCount++;
			if (straightCount == 5)
				return true;
		}
		else if (cards[i + 1].cardValue - cards[i].cardValue > 1)
			straightCount = 1;

		/*Card& currentCard = cards[i];
		CardsValue& currentCardValue = currentCard.cardValue;

		if (currentCardValue == lastCardValue)
		{
			iterationsCount++;
			continue;
		}
		else if ((lastCardValue == currentCardValue - 1) || (lastCardValue == -1))
		{
			lastCardValue = currentCardValue;
			continue;
		}
		else
			return false;*/
	}

	return false;
}


bool CombinationsFinder::isFlush(std::vector<Card>& cards)
{
	SortCardsBySuits(cards);

	int lastCardSuitIndex = -1;
	int cardInRowCount = 0;

	for (auto& card : cards)
	{
		int currentCardSuitIndex = card.suit;

		if (currentCardSuitIndex == lastCardSuitIndex || lastCardSuitIndex == -1)
		{
			cardInRowCount++;
			lastCardSuitIndex = currentCardSuitIndex;

			if (cardInRowCount == 5)
				return true;
		}
		else
		{
			lastCardSuitIndex = currentCardSuitIndex;
			cardInRowCount = 1;
		}
	}

	return false;
}


bool CombinationsFinder::isStraightFlush(std::vector<Card>& cards)
{
	return isStraight(cards) && isFlush(cards);
}


bool CombinationsFinder::isRoyal(std::vector<Card>& cards)
{
	Couple couple = Couple(cards);

	return couple.CheckCard(CardsValue::Ace) && couple.CheckCard(CardsValue::King) &&
		couple.CheckCard(CardsValue::Queen) && couple.CheckCard(CardsValue::Jack) &&
		couple.CheckCard(CardsValue::Ten);
}


bool CombinationsFinder::isRoyalFlush(std::vector<Card>& cards)
{
	bool royal = isRoyal(cards);

	if (!royal)
		return false;

	std::vector<Card> royalCards;

	for (auto& card : cards)
	{
		if (card.cardValue == CardsValue::Ace || card.cardValue == CardsValue::King || card.cardValue == CardsValue::Queen ||
			card.cardValue == CardsValue::Jack || card.cardValue == CardsValue::Ten)
		{
			royalCards.push_back(card);
		}
	}

	return isFlush(royalCards);
}


Combinations CombinationsFinder::CalculateCombination(std::vector<Card>& cards)
{
	if (isRoyalFlush(cards))
		return Combinations::RoyalFlush;
	else if (isStraightFlush(cards))
		return Combinations::StraightFlush;
	else if (isFlush(cards))
		return Combinations::Flush;
	else if (isStraight(cards))
		return Combinations::Straight;
	else
		return isPairsCombination(cards);
}