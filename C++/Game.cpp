#include "Game.h"
#include <iostream>
#include <sstream>

using namespace std;

Game::Game() : currentPlayerIndex(0)
{
	readQuestions(50);
}

void Game::startGame()
{
	if(isPlayable())
	{
		startTurn();
	}
	else
	{
		cout << "The minimum is 2 players" << endl;
	}
}

void Game::readQuestions(int number)
{
	for (int i = 0; i < number; i++)
	{
		ostringstream oss (ostringstream::out);
		oss << "Pop Question " << i;
		popQuestions.push_back(oss.str());
		
		oss.str("");
		oss.clear();
		oss << "Science Question " << i;
		scienceQuestions.push_back(oss.str());

		oss.str("");
		oss.clear();
		oss << "Sports Question " << i;
		sportsQuestions.push_back(oss.str());

		oss.str("");
		oss.clear();
		oss << "Rock Question " << i;
		rockQuestions.push_back(oss.str());		
	}
}

bool Game::isPlayable()
{
	return (howManyPlayers() >= 2);
}

bool Game::addPlayer(string playerName){
	Player newPlayer = Player(playerName);
	players.push_back(newPlayer);
	cout << playerName << " was added" << endl;
	cout << "They are player number " << players.size() << endl;
	return true;
}

int Game::howManyPlayers()
{
	return players.size();
}

void Game::startTurn()
{
	roll(rand() % 5 + 1);
	setCurrentPlayer();
	cout << currentPlayer -> getName() << " is the current player" << endl;
	cout << "They have rolled a " << dice << endl;
	checkPlayerStatus();
}

void Game::checkPlayerStatus()
{
	if(currentPlayer -> isInPenaltyBox())
	{		
		isRollOdd();
	}
	else
	{
		movePlayer();
	}
}

void Game::movePlayer()
{
	currentPlayer -> step(dice);
	cout << currentPlayer -> getName() << "'s new location is " << currentPlayer -> getPlace() << endl;
	cout << "The category is " << currentCategory() << endl;
	askQuestion();
}

void Game::isRollOdd()
{
	if (dice % 2 != 0)
	{
		currentPlayer -> getOutOfPenaltyBox();
		cout << currentPlayer -> getName() << " is getting out of the penalty box" << endl;
		movePlayer();
	}
	else
	{
		cout << currentPlayer -> getName() << " is not getting out of the penalty box" << endl;
		nextPlayerIndex();
	}
}

void Game::roll(int roll)
{
	dice = roll;
}

void Game::askQuestion()
{
	std::string category = currentCategory();
	if (category == "Pop")
	{
		cout << popQuestions.front() << endl;
		popQuestions.pop_front();
	}
	else if (category == "Science")
	{
		cout << scienceQuestions.front() << endl;
		scienceQuestions.pop_front();
	}
	else if (category == "Sports")
	{
		cout << sportsQuestions.front() << endl;
		sportsQuestions.pop_front();
	}
	else if (category == "Rock")
	{
		cout << rockQuestions.front() << endl;
		rockQuestions.pop_front();
	}
	getAnswer();
}

void Game::getAnswer()
{
	if (rand() % 9 == 7)
	{
		wrongAnswer();
	}
	else
	{
		correctAnswer();
	}
}


string Game::currentCategory()
{
	int place = currentPlayer -> getPlace();
	if (place == 0 || place == 4 || place == 8) return "Pop";
	else if (place == 1 || place == 5 || place == 9) return "Science";
	else if (place == 2 || place == 6 || place == 10) return "Sports";
	return "Rock";
}

void Game::correctAnswer()
{
	cout << "Answer was corrent!!!!" << endl;
	currentPlayer -> addCoin();
	cout << currentPlayer -> getName() << " now has " << currentPlayer -> getPurse() << " Gold Coins." << endl;
	if(!didPlayerWin())
	{
		nextPlayerIndex();
	}
}

void Game::wrongAnswer()
{
	cout << "Question was incorrectly answered" << endl;
	cout << currentPlayer -> getName() + " was sent to the penalty box" << endl;
	currentPlayer -> sendToPenaltyBox();
	nextPlayerIndex();
}


bool Game::didPlayerWin()
{
	return (currentPlayer -> getPurse() == 6);
}

void Game::nextPlayerIndex()
{
	currentPlayerIndex++;
	if(currentPlayerIndex == howManyPlayers())
	{
		currentPlayerIndex = 0;
	}
	startTurn();
}

void Game::setCurrentPlayer()
{
	currentPlayer = &players[currentPlayerIndex];
}
