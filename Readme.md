#blackjack

##Blackjack card game written in modern(ish) C++

Provides an object orientated solution to [question 4](http://www.learncpp.com/cpp-tutorial/8-15-chapter-8-comprehensive-quiz/), chapter 8, of the C++ tutorial found at [learncpp.com](http://www.learncpp.com/).
This borrows heavily from the code found in that tutorial written by someone called Alex.

###Issues
1. Currently does not take into account Blackjack (ace and a picture) on the first deal.
2. Aces only have a value of 11. They should have a value of one if a player is going bust with an ace in their hand.

###Fixes
1. Should be a trivial fix; some way of recording Blackjack (owned by the Player) and checking for it later on.
2. This is quite involved. One strategy would be to scan through a player's hand if they are going bust and set the first Ace thay encounter to a value of one. This change would need to be recorded such that if a player is going bust again the next ace in the hand, if they have one, is set to a value of one, and so on.