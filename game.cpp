#include "game.hpp"


Game::Game(int players) {
  playerList = new Player [players];
  this->numRounds = (52/players) * 2 + players - 2;
  this->numPlayers = players;
  this->numCards = (52/players);

  return;
}

Game::~Game() {
  free(playerList);

  return;
}

void Game::addPlayer(string name, int number) {
  playerList[number].assign(name, this->numRounds);

  return;
}
  
void Game::play() {
  
  bool good = false;
  char answer;
  int totalBid;
  int totalScore;

  cout << "There will be " << this->numRounds << " Rounds. Play Game!" << endl;
  for (int i=0; i<this->numRounds; i++) {
//    cout << "trumps this->round are: " << trumps[i%5] << endl;
    cout << "Round " << i+1 << ". " <<  this->numCards << " cards." << endl;
    while (!good) {
      totalBid = enterBids(i);
      cout << "Was that correct? (y/n)" << endl;
      cin  >> answer;
      if (answer == 'y') {good = true;}
    }
    cout << totalBid << " tricks bid for with " << this->numCards << " cards!" << endl;
    good = false;
    while (!good) {
      totalScore = enterScores(i);
      if (totalScore != this->numCards) {
        cout << "You entered " << totalScore << " tricks, when there were " << this->numCards << endl;
        good = false;
      } else {
        cout << "Was that correct? (y/n)" << endl;
        cin  >> answer;
        if (answer == 'y') good = true;
      }
    }
    printScores(i);
    this->numCards--;
    good = false;
  }
  

  return;
}

int Game::enterBids(int round) {
  int bid;
  int sum = 0;
  for (int i=0; i<this->numPlayers; i++) {
    cout << "Enter bid for " << playerList[i].getName() << ": " << endl;
    cin >> bid;

    sum += bid;
    playerList[i].updateBid(bid, round);
  }

  return sum;
}

int Game::enterScores(int round) {

  int score;
  int sum = 0;
  for (int i=0; i<this->numPlayers; i++) {
    cout << "Enter no. tricks for " << playerList[i].getName() <<  ": " << endl;
    cin >> score;

    sum += score;
    playerList[i].updateScore(score, round);
  }

  return sum;
}

void Game::printScores(int rounds) {

    cout << "Scores: ";
  for (int i=0; i<this->numPlayers; i++) {
    cout << playerList[i].getName() << "\t";
  }
  cout << "\n";

  for (int i=0; i<rounds; i++) {
    cout << i << "\t";
    for (int j=0; j<this->numPlayers; j++) {
      cout << playerList[j].getScore(i) << "\t";
    }
    cout << "\n";
  }

  cout << "\n\n" << endl;

  return;
}

