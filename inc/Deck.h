#ifndef DECK_DJW_H
#define DECK_DJW_H

#include "Card.h"

#include <array>
#include <random> //for std::minstd_rand0 (rng) and uniform_int_distribution<>

namespace game{

	const int numCards = 52; //standard playing card deck

	class Deck {
	public:
		//sets up the deck of cards, and seeds rng for shuffling.
		Deck();

		//uses rng to swap cards, essentially shuffling the deck.
		void shuffle(); 

		//return current, dereferenced iterator, and move it on one. If iterator at end move back to beginning.
		const Card& getNextCard() { 
			if (m_deck_it != m_deck.end()) 
				return *m_deck_it++; 
			else
				return *(m_deck_it = m_deck.begin());
		}

	private:
		std::array<Card, numCards> m_deck;					//data strcuture representing a card deck
		std::minstd_rand0 m_generator;						//rng engine found in <random>
		std::uniform_int_distribution<int> m_distribution;	//uniform distribution of integers, used with the rng.
		std::array<Card, numCards>::iterator m_deck_it;		//iterator pointing to current card location.
	};
}
#endif