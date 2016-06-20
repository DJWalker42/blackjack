#ifndef GAME_DJW_H
#define GAME_DJW_H

#include "Deck.h"
#include "Player.h"

namespace game {

	/* Abstract base class for a Game */
	class Game {
	protected:
		Game(){}
		virtual ~Game(){}
	public:
		virtual void play() = 0;
	};

	/* BlackJack definition - inherits from Game class*/
	class BlackJack : public Game {
	public:
		//Constructs a game of blackjack - the deck, the dealer, and the players
		BlackJack();

		//function to run the game logic - calls run() from within a loop
		virtual void play();

		//function to ask for number of players, their names, and to deal first pair of cards
		//@param reuse true if you want to resuse the same player names. 
		void setUpPlayers(bool reuse = false);

	private:
		void displayTitle();
		void run();				//this actually does the game logic
		void clearGame();		//resets Dealer and Player scores to zero, and clears hands.

	private:
		Deck m_Deck;
		Dealer m_Dealer;
		Players m_Players;
	};
}
#endif