#include "Board.h"

void Board::SetNumberOfPlayers(const uint8_t& numberOfPlayers)
{
	m_numberOfPlayers = numberOfPlayers;
}

Board::Board(uint8_t numberOfPlayers)
{
	Territory::Position position;
	auto& [line, column] = position;
	m_numberOfPlayers = numberOfPlayers;
	switch (m_numberOfPlayers)
	{
	case 2:
		m_width = 3;
		m_height = 3;
		break;
	case 3:
		m_width = 5;
		m_height = 3;
		break;
	case 4:
		m_width = 6;
		m_height = 4;
		break;
	}
	for (line = 0; line < m_height; line++)
	{
		for (column = 0; column < m_width; column++)
		{
			m_board.push_back(Territory(position));
		}
	}
}

const std::vector<Territory>& Board::GetBoard() const
{
	return m_board;
}

const uint8_t& Board::GetNumberOfPlayers() const
{
	return m_numberOfPlayers;
}

const Territory& Board::operator[](const Territory::Position& position) const
{
	const auto& [line, column] = position;

	/*if (line >= m_height || column >= m_width)
		throw "Board index out of bound.";*/
	return m_board[line * m_width + column];
}

Territory& Board::operator[](const Territory::Position& position)
{
	const auto& [line, column] = position;

	/*if (line >= m_height || column >= m_width)
		throw "Board index out of bound.";*/
	return m_board[line * m_width + column];
}

std::ostream& operator<<(std::ostream& out, const Board& board)
{
	Territory::Position position;
	auto& [line, column] = position;
	for (line = 0; line < board.m_height; line++)
	{
		for (column = 0; column < board.m_width; column++)
		{
			out <<static_cast<int>(board[position].GetPlayer()) << ' ';
		}
		out << std::endl;
	}
	return out;
}
