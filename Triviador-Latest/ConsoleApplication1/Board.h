#pragma once
#include <vector>
#include "Territory.h"
#include <iostream>

class Board
{
private:
	std::vector<Territory> m_board;
	uint8_t m_numberOfPlayers;
	uint8_t m_width;
	uint8_t m_height;
public:
	Board(uint8_t numberOfPlayers);
	Board() {};
	const std::vector<Territory>& GetBoard() const;
	const uint8_t& GetNumberOfPlayers() const;
	void SetNumberOfPlayers(const uint8_t& numberOfPlayers);
	const Territory& operator[](const Territory::Position& position) const;
	Territory& operator[](const Territory::Position& position);
	friend std::ostream& operator<<(std::ostream& out,const Board &b);
};

