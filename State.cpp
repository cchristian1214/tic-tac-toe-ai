#include <iostream>
#include "State.h"
using namespace std;

void State::updateState(int t, char p)
{
  BoardPair update(t, p);
  if (state.find(t) == state.end())
    state.insert(update);
  else
  {
    state.erase(t);
    state.insert(update);
  }
}

bool State::isWin(char c)
{
  if (state[1] == c && state[2] == c && state[3] == c)
    return true;
  else if (state[4] == c && state[5] == c && state[6] == c)
    return true;
  else if (state[7] == c && state[8] == c && state[9] == c)
    return true;
  else if (state[1] == c && state[4] == c && state[7] == c)
    return true;
  else if (state[2] == c && state[5] == c && state[8] == c)
    return true;
  else if (state[3] == c && state[6] == c && state[9] == c)
    return true;
  else if (state[1] == c && state[5] == c && state[9] == c)
    return true;
  else if (state[3] == c && state[5] == c && state[7] == c)
    return true;
  return false;
}

bool State::isOver()
{
  if (isWin('X') || isWin('O'))
    return true;
  bool flag = true;
  for (auto i = state.begin(); i != state.end(); ++i)
  {
    if (i->second == ' ')
      flag = false;
  }
  return flag;
}