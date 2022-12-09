#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "PlayerCompare.h"
#include "Board.h"
#include "Player.h"
#include "QuestionsBank.h"

#include <crow.h>
#include <sqlite_orm/sqlite_orm.h>
namespace sql = sqlite_orm;

class Game
{
private:
	std::vector<Player> m_players;
	QuestionsBank m_questionsBank;
	Board m_board;
public:
	Game(std::vector<Player> players, QuestionsBank qBank, Board board):
		m_players(players), m_questionsBank(qBank), m_board(board) {};
	
	void ChooseBasePhase();
	void ChooseTerritoryPhase();
	void DuelPhase();
	void ChooseWinnerPhase();

	Board GetBoard() { return m_board; }
	std::vector<Player> GetPlayers() { return m_players; }
};

