#pragma once
#include<iostream>
#include"Board.h"
#include<vector>
#include<chrono>
#include<string>
#include <cstdlib>
#include "Territory.h"
#include "Advantages.h"
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
	short m_playerScore;
	TipPlayer m_tipPlayer;
	std::vector<Territory> m_territories;
	std::string m_answer;
public:
	Advantages m_advantages;
	Player(std::string m_playerName, unsigned short m_playerScore, TipPlayer m_tipPlayer);
	void SetPlayerName(const std::string& name);  
	void SetPlayerScore(const short& score);
	const std::string& GetPlayerColor() const;
	const  short& GetPlayerScore() const;
	const std::string& GetPlayerName() const;
	const uint8_t& GetPlayerNumber() const;
	const std::vector<Territory>& GetTerritories() const;
	bool Attack(const Board& board, const Territory::Position& position);
	short CalculateScore();
	bool CanUseAdvantages(const Board& board);
	std::chrono::steady_clock::time_point InitialTime();
	std::chrono::duration<float> FinalTime();
	void RemoveTerritory(const Territory& territory);
	void AddTerritory(const Territory& territory);
	void TransferTerritoriesTo(Board& board,Player& player);
	void ChooseTerritory(Board& board);
	void ChooseBase(Board& board);
};