#include <iostream>
#include "AI.h"

class Game
{
public:
  /**currState initializes the empty state of a new game.*/
  State currState;

  /**start_game initializes a new game. */
  void start_game();

private:
  /**botPlayer represents the AI player that a human user will play against.*/
  AI botPlayer;

  /**draw_game creates the text-based game board.*/
  void draw_game();

  /**player_turn allows prompts the human user to take their turn
   * in the game. It should prompt the using continously until a valid
   * empty tile on the board in the current state has been inputted.
   */
  void player_turn();

  /**win_message uses the current state to determine if a win, loss, or draw
   * has occurred, and outputs an appropriate message in each case.
   */
  void win_message();
};