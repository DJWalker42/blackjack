#include "Game.h"

#include <iostream>

namespace game {

	BlackJack::BlackJack() : 
		Game(), 
		m_Deck(), 
		m_Dealer(),
		m_Players()	
	{
		displayTitle();
		setUpPlayers();
	}

	void BlackJack::displayTitle(){

		int count = 0;
		while(count++ < 33){
			std::cout << "*"; 
		}
		std::cout << "\n*\tWelcome to Blackjack\t*\n";
		count = 0;
		while (count++ < 33) {
			std::cout << "*";
		}

		std::cout << "\n\n";
	}

	void BlackJack::setUpPlayers(bool reuse){

		m_Deck.shuffle();

		if(!reuse) {
			size_t numPlayers;
			do {
				std::cout << "\nHow many players (1 - 4)? ";
				std::cin >> numPlayers;
			} while (numPlayers < 1 || numPlayers > 4);

			m_Players.resize(numPlayers);
		}

		int count = 1;		
		for (auto& p : m_Players) {
			if (!reuse) {
				std::string name;
				std::cout << "\nEnter player " << count++ << " name: ";
				std::cin >> name;
				p.setName(name);
			}
			p.dealCards(m_Deck.getNextCard(), m_Deck.getNextCard());
		}

		m_Dealer.dealCards(m_Deck.getNextCard(), m_Deck.getNextCard());
	}

	void BlackJack::play(){
		char c = 'n';
		do {
			if (c != 'n') {
				char cc = 'n';
				do {
					std::cout << "Do you wish to keep the same players? (y/n): "; 
					std::cin >> cc;
				} while (cc != 'n' && cc != 'y');
				bool reuse = false;
				(cc == 'n') ? m_Players.clear() : reuse = true;
				setUpPlayers(reuse);
			}
			run();
			clearGame();
			std::cout << "\nDo want to play again? (y/n): ";
			std::cin >> c;
		} while (c != 'n');
	}

	void BlackJack::run(){
		size_t numPlayers = m_Players.size();
		size_t bustCount = 0;

		for (auto& p : m_Players) {
			while (!(p.bust()) && p.hitting(m_Deck))
				/*empty body*/;
			if (p.bust()) {
				std::cout << p.getName() << " is bust with a score of " << p.getScore() << "\n\n";
				++bustCount;
			}
			else {
				std::cout << p.getName() << " sticks on a score of " << p.getScore() << "\n\n";
			}
		}

		if (bustCount == numPlayers) {
			std::cout << "All players bust.\n";
			std::cout << "Dealer wins.\n";
			return;
		}

		while (!(m_Dealer.bust()) && m_Dealer.hitting(m_Deck))
			/*empty body*/;

		std::cout << m_Dealer.getName() << " has a total score of: " << m_Dealer.getScore() << "\n";

		if (m_Dealer.bust()) {
			std::cout << "\nDealer bust. All players not bust win:\n";
			for (const auto& pp : m_Players) {
				if (!(pp.bust())) {
					std::cout << pp.getName() << " is a winner!\n";
				}
			}
		}
		else {
			//compare players' score to dealer's score, win if greater (currently doesn't take into account blackjack)
			for (const auto& pp : m_Players) {
				if (!(pp.bust()) && pp.getScore() > m_Dealer.getScore()) {
					std::cout << pp.getName() << " is a winner!\n";
				} else {
					std::cout << pp.getName() << " loses.\n";
				}
			}
		}
		return;
	}

	void BlackJack::clearGame() {
		m_Dealer.reset();
		for(auto&& p : m_Players)
			p.reset();
	}
}