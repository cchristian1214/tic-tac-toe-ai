#include "State.h"

class AI
{
public:
  /**The method ai_turn uses an object of State to determine
   * the next move the artificial intelligence should make.
   *
   * To make the next move, the AI looks at the current state and
   * examines where the player has positioned themselves in the game
   * at that moment. If the player can win, the AI will prioritize
   * stopping the player. Otherwise, if the AI can win it will prioritize
   * moving to this winning position. In all other cases the AI simply
   * makes a random move.
   */
  State ai_turn(State current);

private:
  /**
   * The function canWin uses the current state to determine if a player
   * can win. Requires: char c is one of 'X' or 'O'.
   *
   * This function uses hardcoded win pre-conditions to determine if any
   * of the two players can win. If they can, the function returns the
   * number of the tile on the game board that will allow for a win
   * to occur.
   */
  int canWin(State current, char c);
};