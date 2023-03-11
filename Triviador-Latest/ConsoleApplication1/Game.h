#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "PlayerCompare.h"
#include "Board.h"
#include "Player.h"
#include "QuestionsBank.h"
#include <random>
#include "database.h"
class Game
{
private:
	std::vector<Player> m_players;
	QuestionsBank m_questionsBank;
	Board m_board;
public:
	Game(std::vector<Player> players, QuestionsBank qBank, Board board) :
		m_players(players), m_questionsBank(qBank), m_board(board) {};
	Game() {};
	void ChooseBasePhase(Storage& db);
	void ChooseTerritoryPhase();
	void DuelPhase();
	void ChooseWinnerPhase();
	const Board& GetBoard() const;
	const std::vector<Player>& GetPlayers() const;
	void AdvantageCost(uint8_t playerNumber);
};
Game StartGame(Storage db, std::vector<std::string> lobby);