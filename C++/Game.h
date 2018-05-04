#ifndef GAME_H_
#define GAME_H_

#include "Player.h"
#include <iostream>
#include <list>
#include <vector>

class Player;

class Game
{
	public:
		Game();
		bool isPlayable();
		bool addPlayer(std::string playerName);
		void startTurn();
		int howManyPlayers();
		void roll(int roll);
		bool wasCorrectlyAnswered();
		bool wrongAnswer();

	private:
		void nextPlayerIndex();
		void setCurrentPlayer();
		void readQuestions(int number);
		void askQuestion();
		std::string currentCategory();
		bool didPlayerWin();
		std::vector<Player> players;
		std::list<std::string> popQuestions;
		std::list<std::string> scienceQuestions;
		std::list<std::string> sportsQuestions;
		std::list<std::string> rockQuestions;
		Player* currentPlayer;
		int currentPlayerIndex;
		int dice;
};

#endif /* GAME_H_ */