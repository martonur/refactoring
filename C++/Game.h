#ifndef GAME_H_
#define GAME_H_

#include <iostream>
#include <list>
#include <vector>

class Game{
	public:
		Game();
		bool isPlayable();
		bool add(std::string playerName);
		int howManyPlayers();
		void roll(int roll);
		bool wasCorrectlyAnswered();
		bool wrongAnswer();

	private:
		void askQuestion();
		std::string currentCategory();
		bool didPlayerWin();
		std::vector<std::string> players;
		int places[6];
		int purses[6];
		bool inPenaltyBox[6];
		std::list<std::string> popQuestions;
		std::list<std::string> scienceQuestions;
		std::list<std::string> sportsQuestions;
		std::list<std::string> rockQuestions;
		int currentPlayer;
		bool isGettingOutOfPenaltyBox;
};

#endif /* GAME_H_ */