#ifndef GAME_H_
#define GAME_H_

#include "Player.h"
#include <list>
#include <vector>

class Player;

class Game
{
	public:
		Game();
		bool addPlayer(std::string playerName);
		void startGame();	
	private:
		void readQuestions(int number);
		int howManyPlayers();
		bool isPlayable();
		void startTurn();
		void setCurrentPlayer();
		void roll(int roll);
		void checkPlayerStatus();
		void isRollOdd();
		void movePlayer();
		std::string currentCategory();
		void askQuestion();
		void getAnswer();
		void wrongAnswer();
		void correctAnswer();
		bool didPlayerWin();
		void nextPlayerIndex();

		int dice;
		std::vector<Player> players;
		int currentPlayerIndex;
		Player* currentPlayer;
		std::list<std::string> popQuestions;
		std::list<std::string> scienceQuestions;
		std::list<std::string> sportsQuestions;
		std::list<std::string> rockQuestions;	
};

#endif /* GAME_H_ */