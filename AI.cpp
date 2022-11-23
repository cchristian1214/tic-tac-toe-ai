#include "AI.h"

int AI::canWin(State current, char c)
{
  if (current.getTileChar(1) == c && current.getTileChar(2) == c && current.getTileChar(3) == ' ')
    return 3;
  else if (current.getTileChar(1) == ' ' && current.getTileChar(2) == c && current.getTileChar(3) == c)
    return 1;
  else if (current.getTileChar(1) == c && current.getTileChar(2) == ' ' && current.getTileChar(3) == c)
    return 2;
  else if (current.getTileChar(4) == c && current.getTileChar(5) == c && current.getTileChar(6) == ' ')
    return 6;
  else if (current.getTileChar(4) == ' ' && current.getTileChar(5) == c && current.getTileChar(6) == c)
    return 4;
  else if (current.getTileChar(4) == c && current.getTileChar(5) == ' ' && current.getTileChar(6) == c)
    return 5;
  else if (current.getTileChar(7) == c && current.getTileChar(8) == c && current.getTileChar(9) == ' ')
    return 9;
  else if (current.getTileChar(7) == ' ' && current.getTileChar(8) == c && current.getTileChar(9) == c)
    return 7;
  else if (current.getTileChar(7) == c && current.getTileChar(8) == ' ' && current.getTileChar(9) == c)
    return 8;
  else if (current.getTileChar(1) == c && current.getTileChar(4) == c && current.getTileChar(7) == ' ')
    return 7;
  else if (current.getTileChar(1) == ' ' && current.getTileChar(4) == c && current.getTileChar(7) == c)
    return 1;
  else if (current.getTileChar(1) == c && current.getTileChar(4) == ' ' && current.getTileChar(7) == c)
    return 4;
  else if (current.getTileChar(2) == c && current.getTileChar(5) == c && current.getTileChar(8) == ' ')
    return 8;
  else if (current.getTileChar(2) == ' ' && current.getTileChar(5) == c && current.getTileChar(8) == c)
    return 2;
  else if (current.getTileChar(2) == c && current.getTileChar(5) == ' ' && current.getTileChar(8) == c)
    return 5;
  else if (current.getTileChar(3) == c && current.getTileChar(6) == c && current.getTileChar(9) == ' ')
    return 9;
  else if (current.getTileChar(3) == ' ' && current.getTileChar(6) == c && current.getTileChar(9) == c)
    return 3;
  else if (current.getTileChar(3) == c && current.getTileChar(6) == ' ' && current.getTileChar(9) == c)
    return 6;
  else if (current.getTileChar(1) == c && current.getTileChar(5) == c && current.getTileChar(9) == ' ')
    return 9;
  else if (current.getTileChar(1) == ' ' && current.getTileChar(5) == c && current.getTileChar(9) == c)
    return 1;
  else if (current.getTileChar(1) == c && current.getTileChar(5) == ' ' && current.getTileChar(9) == c)
    return 5;
  else if (current.getTileChar(3) == c && current.getTileChar(5) == c && current.getTileChar(7) == ' ')
    return 7;
  else if (current.getTileChar(3) == ' ' && current.getTileChar(5) == c && current.getTileChar(7) == c)
    return 3;
  else if (current.getTileChar(3) == c && current.getTileChar(5) == ' ' && current.getTileChar(7) == c)
    return 5;
  return 0;
}

State AI::ai_turn(State current)
{
  int xWin = canWin(current, 'X');
  int oWin = canWin(current, 'O');
  if (xWin != 0)
  {
    current.updateState(xWin, 'O');
  }
  else if (oWin != 0)
  {
    current.updateState(oWin, 'O');
  }
  else
  {
    srand(time(0));
    while (true)
    {
      int move = rand() % 10 + 1;
      if (current.getTileChar(move) == ' ')
      {
        current.updateState(move, 'O');
        break;
      }
    }
  }
  return current;
}