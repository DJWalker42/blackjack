#ifndef CARD_DJW_H
#define CARD_DJW_H

namespace game{
	class Card {
	public:
		enum CardSuit
		{
			SUIT_CLUB,
			SUIT_DIAMOND,
			SUIT_HEART,
			SUIT_SPADE,
			MAX_SUITS
		};

		enum CardRank
		{
			RANK_2,
			RANK_3,
			RANK_4,
			RANK_5,
			RANK_6,
			RANK_7,
			RANK_8,
			RANK_9,
			RANK_10,
			RANK_JACK,
			RANK_QUEEN,
			RANK_KING,
			RANK_ACE,
			MAX_RANKS
		};

		Card() : m_suit(SUIT_CLUB), m_rank(RANK_ACE) {}

		Card(CardSuit suit, CardRank rank) : m_suit(suit), m_rank(rank) {}

		CardSuit getSuit() const { return m_suit; }
		CardRank getRank() const { return m_rank; }

		void setSuit(CardSuit suit) {m_suit = suit;}
		void setRank(CardRank rank) {m_rank = rank;}

		int getValue() const {
			switch (m_rank) {
			case RANK_2:		return 2;
			case RANK_3:		return 3;
			case RANK_4:		return 4;
			case RANK_5:		return 5;
			case RANK_6:		return 6;
			case RANK_7:		return 7;
			case RANK_8:		return 8;
			case RANK_9:		return 9;
			case RANK_10:		return 10;
			case RANK_JACK:		return 10;
			case RANK_QUEEN:	return 10;
			case RANK_KING:		return 10;
			case RANK_ACE:		return 11;
			}

			return 0;
		}

	private:
		CardSuit m_suit;
		CardRank m_rank;
	};
}
#endif