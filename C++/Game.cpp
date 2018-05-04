﻿#include "Game.h"
#include <iostream>
#include <sstream>

using namespace std;

Game::Game() : currentPlayerIndex(0)
{
	readQuestions(50);
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

void Game::roll(int roll)
{
	setCurrentPlayer();
	cout << currentPlayer -> getName() << " is the current player" << endl;
	cout << "They have rolled a " << roll << endl;

	if(currentPlayer -> isInPenaltyBox())
	{
		if (roll % 2 != 0)
		{
			isGettingOutOfPenaltyBox = true;
			cout << currentPlayer -> getName() << " is getting out of the penalty box" << endl;
			currentPlayer -> step(roll);
			cout << currentPlayer -> getName() << "'s new location is " << currentPlayer -> getPlace() << endl;
			cout << "The category is " << currentCategory() << endl;
			askQuestion();
		}
		else
		{
			cout << currentPlayer -> getName() << " is not getting out of the penalty box" << endl;
			isGettingOutOfPenaltyBox = false;
		}

	}
	else
	{
		currentPlayer -> step(roll);
		cout << currentPlayer -> getName() << "'s new location is " << currentPlayer -> getPlace() << endl;
		cout << "The category is " << currentCategory() << endl;
		askQuestion();
	}

}

void Game::askQuestion()
{
	if (currentCategory() == "Pop")
	{
		cout << popQuestions.front() << endl;
		popQuestions.pop_front();
	}
	if (currentCategory() == "Science")
	{
		cout << scienceQuestions.front() << endl;
		scienceQuestions.pop_front();
	}
	if (currentCategory() == "Sports")
	{
		cout << sportsQuestions.front() << endl;
		sportsQuestions.pop_front();
	}
	if (currentCategory() == "Rock")
	{
		cout << rockQuestions.front() << endl;
		rockQuestions.pop_front();
	}
}


string Game::currentCategory()
{
	if (currentPlayer -> getPlace() == 0) return "Pop";
	if (currentPlayer -> getPlace() == 4) return "Pop";
	if (currentPlayer -> getPlace() == 8) return "Pop";
	if (currentPlayer -> getPlace() == 1) return "Science";
	if (currentPlayer -> getPlace() == 5) return "Science";
	if (currentPlayer -> getPlace() == 9) return "Science";
	if (currentPlayer -> getPlace() == 2) return "Sports";
	if (currentPlayer -> getPlace() == 6) return "Sports";
	if (currentPlayer -> getPlace() == 10) return "Sports";
	return "Rock";
}

bool Game::wasCorrectlyAnswered()
{
	if (currentPlayer -> isInPenaltyBox())
	{
		if (isGettingOutOfPenaltyBox)
		{
			cout << "Answer was correct!!!!" << endl;
			currentPlayer -> addCoin();
			cout << currentPlayer -> getName()
			     << " now has "
			     << currentPlayer -> getPurse()
				<<  " Gold Coins." << endl;

			bool winner = didPlayerWin();

			nextPlayerIndex();
			return winner;
		}
		else
		{
			nextPlayerIndex();
			return true;
		}
	}
	else
	{

		cout << "Answer was corrent!!!!" << endl;
		currentPlayer -> addCoin();
		cout << currentPlayer -> getName()
				<< " now has "
				<< currentPlayer -> getPurse()
			<< " Gold Coins." << endl;

		bool winner = didPlayerWin();
		nextPlayerIndex();
		return winner;
	}
}

bool Game::wrongAnswer()
{
	cout << "Question was incorrectly answered" << endl;
	cout << currentPlayer -> getName() + " was sent to the penalty box" << endl;
	currentPlayer -> sendToPenaltyBox();
	nextPlayerIndex();
	return true;
}


bool Game::didPlayerWin()
{
	return !(currentPlayer -> getPurse() == 6);
}

void Game::nextPlayerIndex()
{
	currentPlayerIndex++;
	if(currentPlayerIndex == howManyPlayers())
	{
		currentPlayerIndex = 0;
	}
}

void Game::setCurrentPlayer()
{
	currentPlayer = &players[currentPlayerIndex];
}
