#include "player.hpp"

Player::Player() {

/*    this->name = newName;  
  this->totalScore = new int [numRounds];
  this->totalBid = new int [numRounds];
*/  
}

Player::~Player() {

  free(totalScore);
  free(totalBid);

}

void Player::updateScore(int roundScore, int round) {
  int oldRound;
  if (round == 0) {
    oldRound = round;
  } else {
    oldRound = round - 1;
  }
  if (roundScore == this->totalBid[round]) {
    this->totalScore[round] = this->totalScore[oldRound] + roundScore + 10;
    this->streak[round] = this->streak[oldRound] + 1;
  } else {
    this->totalScore[round] = this->totalScore[oldRound] + roundScore;
    this->streak[round] = 0;
  }

    return;
}

void Player::updateBid(int roundBid, int round) {

  this->totalBid[round] = roundBid;

  return;
}

void Player::assign(string newName, int numRounds) {

  this->totalScore = new int [numRounds];
  this->totalBid = new int [numRounds];
  this->streak = new int [numRounds];
  this->name = newName;  
  
  this->totalScore[0] = 0;
  this->streak[0] = 0;

  return;
}

string Player::getName() {

  return this->name;
}

int Player::getScore(int round) {

  return this->totalScore[round];
}

int Player::getBid(int round) {

  return this->totalBid[round];
}

