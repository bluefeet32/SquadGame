#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>

#include "game.hpp"

int main () {

  int players;
  string name;
  char answer;
  bool good;

  cout << "Welcome to squad game" << endl;
  cout << "Please enter the number of players:" << endl;
  cin >> players;

  Game match(players);

  for (int i=0; i<players; i++) {
    good = false;
    cout << "Enter the name of player " << i+1 << endl;
    cin >> name;
    while (!good) {
      cout << "Was that correct? (y/n)" << endl;
      cin  >> answer;
      if (answer == 'y') good = true;
    }
    match.addPlayer(name, i);
  }

  match.play();

  return 0;
}
