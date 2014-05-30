#include <stdio>
#include <stdlib>
#include <string>

#include <game.hpp>

int main () {

  int players;
  string name;

  cout << "Welcome to squad game" << endl;
  cout << "Please enter the number of players:" << endl;
  cin << players;

  Game match(players);

  for (int i=0; i<players; i++) {
    cout << "Enter the name of player " << i << endl;
    cin >> name;
    match.addPlayer(name, i)
  }

  match.play();

  return 0;
}
