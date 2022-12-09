#pragma once
#include <vector>
#include "Territory.h"
#include <iostream>

class Board
{
private:
	std::vector<Territory> m_board;
	unsigned int m_numberOfPlayers;
	unsigned int m_width;
	unsigned int m_height;
public:
	Board(unsigned int numberOfPlayers);
	std::vector<Territory> GetBoard();
	unsigned int GetNumberOfPlayers();
	void SetNumberOfPlayers(unsigned int numberOfPlayers);
	Territory& operator[](std::pair<unsigned short, unsigned short> indices);
	
	friend std::ostream& operator<<(std::ostream& out, Board b) {
		for (int i = 0; i < b.m_height; i++)
		{
			for (int j = 0; j < b.m_width; j++)
			{
				out << b[{i, j}].GetPlayer() << ' ';
			}
			out << std::endl;
		}
		return out;
	}
};

