#include "player.hpp"

Class Player {

  void Player::Player() {

/*    this.name = newName;  
    this.totalScore = new int [numRounds];
    this.totalBid = new int [numRounds];
*/  
    return;
  }
  
  void Player::~Player() {

    free(totalScore);
    free(totalBid);
  
    return;
  }

  void Player::updateScore(int roundScore, int round) {

    if (roundScore == this.totalBid[round]) {
      this.totalScore[round] = this.totalScore[round - 1] + roundScore + 10;
    } else {
      this.totalScore[round] = this.totalScore[round - 1] + roundScore;
    }

      return;
  }

  void Player::updateBid(int roundBid, int round) {

    this.totalBid[round] = roundBid;

    return;
  }

  void Player::aassign(string, newName, int numRounds) {

    this.totalScore = new int [numRounds];
    this.totalBid = new int [numRounds];
    this.name = newName;  

    return;
  }

}
