#include "Board.h"

void Board::SetNumberOfPlayers(unsigned int numberOfPlayers)
{
	m_numberOfPlayers = numberOfPlayers;
}

Board::Board(unsigned int numberOfPlayers)
{
	m_numberOfPlayers = numberOfPlayers;

	if (numberOfPlayers == 2)
	{
		m_width = 3;
		m_height = 3;
	}
	else if (numberOfPlayers == 3)
	{
		m_width = 5;
		m_height = 3;
	}
	else if (numberOfPlayers == 4)
	{
		m_width = 6;
		m_height = 4;
	}
	for (int i = 0; i < m_height; i++)
	{
		for (int j = 0; j < m_width; j++)
		{
			m_board.push_back(Territory({ i, j }));
		}
	}
}

std::vector<Territory> Board::GetBoard()
{
	return m_board;
}

unsigned int Board::GetNumberOfPlayers()
{
	return m_numberOfPlayers;
}

Territory& Board::operator[](std::pair<unsigned short, unsigned short> indices)
{	
		return m_board[m_width * indices.first + indices.second];	
}
