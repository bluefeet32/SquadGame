#ifndef player
#define player 

#include <stdio>
#include <string.h>

Class Player {

private:
  string name;
  int *totalScore;
  int *totalBid;

public:
  void Player::Player();
  void Player::~Player();

  void Player::updateScore(int roundScore);
  void Player::updateBid(int roundBid);
  void Player::assign(string name, int numRounds);

}

#endif
