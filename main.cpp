#include <iostream>
#include <cstdlib>
#include "Game.h"
using namespace std;

int main(int argc, char *argv[])
{
  Game init;
  init.start_game();
  while (true)
  {
    Game new_game;
    char play;
    cout << "Enter \'P\' to play again. Press \'Q\' to quit." << endl;
    cin >> play;
    if (play == 'P' || play == 'p')
      new_game.start_game();
    else if (play == 'Q' || play == 'q')
      break;
  }
  system("pause");
}