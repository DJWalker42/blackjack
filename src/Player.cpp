#include "Player.h"
#include "Deck.h"

#include <iostream>

namespace game{

	bool Player::hitting(Deck& deck){
		std::cout << m_name << " has " << m_score << ": ";
		if (decision() != 's') {
			std::cout << "Hitting\n";
			Card next = deck.getNextCard();
			m_hand.push_back(next);
			m_score += next.getValue();
			return true;
		}
		std::cout << "Sticking\n";
		return false;
	}

	char Player::decision() const {		
		char choice;
		do {
			std::cout << "(h) to hit, or (s) to stick: ";
			std::cin >> choice;
		} while (choice != 'h' && choice != 's');

		return choice;
	}

	char Dealer::decision() const {
		if (m_score < 17)
			return 'h';
		else
			return 's';
	}
}