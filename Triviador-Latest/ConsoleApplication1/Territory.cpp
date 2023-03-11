#include "Territory.h"

Territory::Territory(Position position, unsigned short score, uint8_t player, uint8_t numberOfLives, bool isBase, bool occupied) :
	m_position(position), m_score(score), m_player(player), m_numberOfLives(numberOfLives), m_isBase(isBase), m_isOccupied(occupied) {}

void Territory::SetScore(const unsigned short& score)
{
	 m_score = score; 
}

void Territory::SetPosition(const Position& position)
{
	m_position = position;
}

void Territory::SetNumberOfLives(const uint8_t& numberOfLives)
{
	m_numberOfLives = numberOfLives;
}

void Territory::SetIsBase(const bool& isBase)
{
	m_isBase = isBase;
}

void Territory::SetPlayer(const uint8_t& player)
{
	m_player = player;
}

void Territory::SetIsOccupied(const bool& occupied)
{
	m_isOccupied = occupied;
}

const uint8_t& Territory::GetPlayer() const
{
	return m_player;
}

const bool& Territory::GetIsOccupied() const
{
	return m_isOccupied;
}

const unsigned short& Territory::GetScore() const
{
	return m_score;
}

const Territory::Position& Territory::GetPosition() const
{
	return m_position;
}

const uint8_t& Territory::GetNumberOfLives() const
{
	return m_numberOfLives;
}

const bool& Territory::GetIsBase() const
{
	return m_isBase;
}

