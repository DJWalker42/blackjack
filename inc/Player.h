#ifndef PLAYER_H
#define PLAYER_H

#include "Card.h"
#include "Deck.h"

#include <vector>
#include <iostream>
#include <string>

namespace game{

	class Player{
	public:
		Player() : m_hand(2), m_score(0), m_name() {}
		Player(std::string name) : m_hand(2), m_score(0), m_name(name) {}
		Player(std::string name, Card one, Card two) : m_hand(2), m_score(0), m_name(name) {
			dealCards(one, two);
		}

	public:
		bool hitting(Deck& deck); 
		bool bust() const { return m_score > 21; }
		int getScore() const { return m_score; }
		std::string getName() const { return m_name; }

		void setName(const std::string& name) { m_name = name; }
		void dealCards(Card one, Card two) {
			m_hand[0] = one;
			m_hand[1] = two;
			m_score = one.getValue() + two.getValue();	
			std::cout << "\n" << m_name << " has be dealt " << m_score << "\n\n";
		}

		void reset() {
			m_hand.clear();
			m_hand.resize(2); 
			m_score = 0;
		}

	private:
		virtual char decision() const;

	protected:
		std::vector<Card> m_hand;
		int m_score;
		std::string m_name;
	}; 

	class Dealer : public Player {
	public:
		Dealer() : Player("Dealer") {}
		Dealer (Card one, Card two) : Player("Dealer", one, two) {}
	private:
		virtual char decision() const;
	};

	typedef std::vector<Player> Players;
}
#endif