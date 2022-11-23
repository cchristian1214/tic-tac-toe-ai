#include <iostream>
#include <map>
using namespace std;

class State
{
public:
  /**Default constructor for State object representing the game state.*/
  State()
  {
    for (int i = 1; i < 10; i++)
    {
      BoardPair def_state(i, ' ');
      state.insert(def_state);
    }
  }

  /**updateState updates the state of the game accordingly given
   * the tile t and character p. Requires: 0 < t < 10 and p is one of 'X' or
   * 'O'.
   */
  void updateState(int t, char p);

  /**isWin uses hard-coded win conditions to determine if player c has one
   * the game in the current state.
   */
  bool isWin(char c);

  /**isOver checks if the game has ended. The game has ended if either the
   * state is filled with player characters or if the game has been won.
   */
  bool isOver();

  /**Retrieves the player character at tile t.*/
  char getTileChar(int t)
  {
    return state[t];
  }

  /**Changes the character present at tile t to character p. */
  void setTileChar(int t, char p)
  {
    updateState(t, p);
  }

private:
  // A map value type representing a tile of the game state.
  typedef map<int, char>::value_type BoardPair;
  // A map of int, character pairs representing the game state.
  map<int, char> state;
};