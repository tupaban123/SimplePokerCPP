#include <iostream>
#include <vector>
#include "./Card/Card.h"
#include "./Player/Player.h"
#include <ctime>
#include <string>
#include "./Combinations/Finder/CombinationsFinder.h"
#include "./Combinations/Comparator/CombinationsComparator.h"


std::map<Combinations, std::string> combinationsInString
{
	{Combinations::HighCard, "HighCard"},
	{Combinations::Pair, "Pair"},
	{Combinations::TwoPair, "TwoPair"},
	{Combinations::ThreeOfAKind, "ThreeOfAKind"},
	{Combinations::Straight, "Straight"},
	{Combinations::Flush, "Flush"},
	{Combinations::FullHouse, "FullHouse"},
	{Combinations::FourOfAKind, "FourOfAKind"},
	{Combinations::StraightFlush, "StraightFlush"},
	{Combinations::RoyalFlush, "RoyalFlush"}
};

std::map<CardsValue, std::string> cardsValueInString
{
	{CardsValue::Two, "Two"},
	{CardsValue::Three, "Three"},
	{CardsValue::Four, "Four"},
	{CardsValue::Five, "Five"},
	{CardsValue::Six, "Six"},
	{CardsValue::Seven, "Seven"},
	{CardsValue::Eight, "Eight"},
	{CardsValue::Nine, "Nine"},
	{CardsValue::Ten, "Ten"},
	{CardsValue::Jack, "Jack"},
	{CardsValue::Queen, "Queen"},
	{CardsValue::King, "King"},
	{CardsValue::Ace, "Ace"}
};

std::map<Suits, std::string> suitsInString
{
	{Suits::Clubs, "Clubs"},
	{Suits::Diamonds, "Diamonds"},
	{Suits::Hearts, "Hearts"},
	{Suits::Spades, "Spades"},
};

std::vector<Card> GetRandomCardsFromDeck(std::vector<Card>& deck, int count)
{
	std::vector<Card> deckToReturn;

	for (; deckToReturn.size() < count; )
	{
		int randomCardIndex = rand() % deck.size();

		Card card = deck[randomCardIndex];
		deckToReturn.push_back(card);

		deck.erase(deck.begin() + randomCardIndex);
	}

	return deckToReturn;
};

std::string GetCardStr(Card& card)
{
	return cardsValueInString[card.cardValue] + " " + suitsInString[card.suit];
}

int main()
{
	//deck generating
	std::vector<Card> cardsDeck;

	for (int iValue = CardsValue::Two; iValue != CardsValue::Ace + 1; iValue++)
	{
		for (int iSuit = Suits::Clubs; iSuit != Suits::Spades + 1; iSuit++)
		{
			Card card = Card(static_cast<CardsValue>(iValue), static_cast<Suits>(iSuit));
			cardsDeck.push_back(card);
		}
	}

	std::cout << cardsDeck.size() << std::endl;

	//players creating
	srand(time(NULL));

	std::vector<Player> players;
	int playersCount = 0;

	std::cout << "enter players count: ";
	std::cin >> playersCount;
	std::cout << std::endl;

	if (playersCount > 4)
		playersCount = 4;

	for (int i = 0; i < playersCount; i++)
	{
		std::string playerName = "Player " + std::to_string(i + 1);
		std::cout << std::endl << "creating " << playerName << std::endl;

		std::vector<Card> playerHand = GetRandomCardsFromDeck(cardsDeck, 2);

		Player player = Player(playerHand, playerName);

		std::cout << "player hand cards: " << player.cards.size() << std::endl;

		for (std::vector<Card>::iterator i = player.cards.begin(); i != player.cards.end(); i++)
		{
			std::cout << GetCardStr(*i) << std::endl;
		}

		std::cout << "highest card: " << GetCardStr(*player.GetHighCardFromHand()) << std::endl;

		players.push_back(player);
	}

	cardsDeck.shrink_to_fit();

	//creating table deck
	std::vector<Card> tableDeck = GetRandomCardsFromDeck(cardsDeck, 5);

	std::cout << std::endl << "deck on table: " << std::endl;

	for (std::vector<Card>::iterator i = tableDeck.begin(); i != tableDeck.end(); i++)
	{
		std::cout << GetCardStr(*i) << ", ";
	}

	std::cout << std::endl;

	for (int i = 0; i < players.size(); i++)
	{
		std::cout << players[i].name << " combination: " << combinationsInString[players[i].GetCombination(tableDeck)] << std::endl;
	}

	CombinationsComparator cc = CombinationsComparator();

	std::cout << "Winner: " << cc.CompareCombinations(players, tableDeck).name << std::endl;

	/*std::vector<Card> cards;
	cards.push_back(Card(CardsValue::Queen, Suits::Diamonds));
	cards.push_back(Card(CardsValue::Six, Suits::Diamonds));
	cards.push_back(Card(CardsValue::Five, Suits::Hearts));
	cards.push_back(Card(CardsValue::Two, Suits::Hearts));
	cards.push_back(Card(CardsValue::Four, Suits::Diamonds));
	cards.push_back(Card(CardsValue::Jack, Suits::Clubs));
	cards.push_back(Card(CardsValue::Two, Suits::Diamonds));

	CombinationsFinder cf = CombinationsFinder();

	bool isStraight = cf.isPairsCombination(cards);*/

	return 0;
}
