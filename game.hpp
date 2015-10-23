#ifndef game
#define game

#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>

#include "player.hpp"

using namespace::std;

class Game {

private:
  int numPlayers;
  int numRounds;
  int numCards;
//  char *trumps = new char [5] "cdhsn";
  Player *playerList;

  int enterBids(int round);
  int enterScores(int round);
  void printScores(int round);
  
public:
  Game(int players);
  ~Game();
  void addPlayer(string name, int number);
  void play();

};

#endif
