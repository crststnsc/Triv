#pragma once
#include <iostream>
#include "Board.h"
#include <vector>
#include <chrono>
#include <string>
#include <cstdlib>

class Player
{
public:
	enum class TipPlayer
	{
		Blue = 1,
		Yellow = 2,
		Red = 3,
		Green = 4
	};

private:
	std::string m_playerName;
	unsigned int m_playerScore;
	TipPlayer m_tipPlayer = TipPlayer::Blue;
	std::vector<Territory> m_territories;
	std::string m_answer;

public:
	Player(std::string playerName, unsigned int playerScore, TipPlayer tipPlayer);
	
	void SetPlayerName(std::string name);
	void SetPlayerScore(int score);
	
	std::string GetPlayerName();
	unsigned int GetPlayerScore();
	void GetPlayerColor();
	int& GetPlayerNumber();
	std::vector<Territory> GetTerritories();
	std::string GetAnswer();

	bool Attack(Board board, std::pair<unsigned int, unsigned int > position);
	void UpdateScore();
	int CalculateScore();

	std::chrono::steady_clock::time_point InitialTime();
	std::chrono::duration<float> FinalTime();

	void AddTerritory(Territory territory);
	void TransferTerritoriesTo(Player player);
	void ChooseTerritory(Board& board);
	void ChooseBase(Board& board);
};