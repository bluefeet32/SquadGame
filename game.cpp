#include "game.hpp"


Class Game {

public:
  void Game::Game(int players) {
    playerList = new Player [players];
    this.numRounds = (52/players);

    return;
  }

  void Game::~Game() {
    free(playerList);

    return;
  }

  void Game::addPlayer(string name, int number) {
    playerList[number].addPlayer(name, this.numRounds);

    return;
  }
    
  void Game::play() {
    
    for (int i=0; i<this.numRounds; i++) {
      cout << "trumps this round are: " << trumps[i%5] << endl;
      enterBids();

      cout << "Play Game!" << endl;

      enterScores();
      printScores();
    }
    

    return;
  }

  void enterBids() {
    int bid;
    for (int i=0; i<this.numPlayers; i++) {
      cout << "Enter bid for: " << playerList[i].getName() << endl;
      cin >> bid;

      playerList[i].updateBid(bid);
    }

    return;
  }

  void enterScores() {

    int score;
    for (int i=0; i<this.numPlayers; i++) {
      cout << "Enter no. tricks for: " << playerList[i].getName() << endl;
      cin >> score;

      playerList[i].updateScore(score);
    }

    return;
  }

  void printScores(int rounds) {

      cout << "Scores: ";
    for (int i=0; i<this.numPlayers; i++) {
      cout << playerList[i].getName() << "\t";
    }
    cout << "\n";

    for (int i=0; i<rounds; i++) {
      cout << i << "\t";
      for (int j=0; i<this.numPlayers; i++) {
        cout << playerList[j].getScore() << "\t";
      }
      cout << "\n";
    }

    cout << "\n\n" << endl;

    return;
  }

}
