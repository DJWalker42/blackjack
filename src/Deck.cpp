#include "Deck.h"

#include <cassert>
#include <chrono>	//for high_resolution_clock
#include <utility>	//for std::swp

namespace game {

	Deck::Deck() : 
		m_deck(), //use loop in the constructor body to assign correct values
		//seed the rng based on system time/clock
		m_generator( static_cast<unsigned int>(std::chrono::high_resolution_clock::now().time_since_epoch().count()) ),
		m_distribution(0, numCards - 1), //constructor for the distribution; rng will provide integers in range [0,51]
		m_deck_it(m_deck.begin())
	{
		//we only consider a standard pack of playing cards - todo change to a exception(?)
		assert(Card::MAX_SUITS * Card::MAX_RANKS == numCards);

		for (int suit = 0; suit < Card::MAX_SUITS; ++suit) {
			for (int rank = 0; rank < Card::MAX_RANKS; ++rank) {
				int card = suit * Card::MAX_RANKS + rank;
				m_deck[card].setSuit(static_cast<Card::CardSuit>(suit));
				m_deck[card].setRank(static_cast<Card::CardRank>(rank));
			}
		} 
	}

	void Deck::shuffle(){
		// Step through each card in the deck and swap with a random card
		for (int index = 0; index < numCards; ++index) {
			std::swap(m_deck[index], m_deck[m_distribution(m_generator)]);
		}
		m_deck_it = m_deck.begin(); //return to the start of the deck
	}
}