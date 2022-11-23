#include "Game.h"

void Game::draw_game()
{
  cout << "   |   |   " << endl;
  cout << " " << currState.getTileChar(1) << " | " << currState.getTileChar(2) << " | " << currState.getTileChar(3) << " " << endl;
  cout << "   |   |   " << endl;
  cout << "-----------" << endl;
  cout << "   |   |   " << endl;
  cout << " " << currState.getTileChar(4) << " | " << currState.getTileChar(5) << " | " << currState.getTileChar(6) << " " << endl;
  cout << "   |   |   " << endl;
  cout << "-----------" << endl;
  cout << "   |   |   " << endl;
  cout << " " << currState.getTileChar(7) << " | " << currState.getTileChar(8) << " | " << currState.getTileChar(9) << " " << endl;
  cout << "   |   |   " << endl;
  cout << "" << endl;
}

void Game::player_turn()
{
  bool flag = true;
  while (flag)
  {
    cout << "Select A Tile: ";
    int t;
    cin >> t;
    if (!cin || t <= 0 || t > 9)
    {
      cout << "Not a valid tile. Try again." << endl;
      cin.clear();
      cin.ignore();
    }
    else if (currState.getTileChar(t) != ' ')
    {
      cout << "Tile is occupied. Try again." << endl;
      cin.clear();
      cin.ignore();
    }
    else
    {
      currState.updateState(t, 'X');
      flag = false;
    }
  }
}

void Game::win_message()
{
  if (currState.isWin('X'))
    cout << "Player X Wins!" << endl;
  else if (currState.isWin('O'))
    cout << "Player O Wins!" << endl;
  else
    cout << "It's a draw!" << endl;
}

void Game::start_game()
{
  draw_game();
  while (!currState.isOver())
  {
    player_turn();
    if (currState.isOver())
    {
      draw_game();
      win_message();
      break;
    }
    currState = botPlayer.ai_turn(currState);
    draw_game();
  }
}