#ifndef game
#define game

#include <stdlib>

Class Game {

private:
  int numPlayers;
  int numRounds;
  char *trumps = "cdhsn";
  Player *player;

  void enterBids();
  void enterScores();
  void printScores();
  
public:
  void Game::Game(int players);
  void Game::~Game();
  void Game::addPlayer(string name, int number);
  void Game::play();

}

#endif
