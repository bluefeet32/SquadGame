#ifndef player
#define player 

#include <stdio.h>
#include <stdlib.h>
#include <string>

using namespace::std;

class Player {

private:
  string name;
  int *totalScore;
  int *totalBid;
  int *streak;

public:
  Player();
  ~Player();

  void updateScore(int score, int round);
  void updateBid(int bid, int round);
  void assign(string name, int numRounds);
  string getName();
  int getScore(int round);
  int getBid(int round);

};
 

#endif
