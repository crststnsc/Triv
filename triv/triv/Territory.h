#pragma once
#include <utility>

class Territory
{
private:
	unsigned int m_score;
	std::pair<unsigned short, unsigned short> m_position;
	unsigned int m_numberOfLives;
	unsigned int m_player = 0;

	bool m_isOccupied;
	bool m_isBase;

public:
	Territory(std::pair<unsigned short, unsigned short> position, unsigned int score = 100, 
		unsigned int numberOfLives = 1, bool isBase = false, unsigned int player = 0, bool occupied=false);

	void SetScore(unsigned int score) { m_score = score; }
	void SetPosition(std::pair<unsigned short, unsigned short> position) { m_position = position; }
	void SetNumberOfLives(unsigned int numberOfLives) { m_numberOfLives = numberOfLives; }
	void SetIsBase(bool isBase) { m_isBase = isBase; }
	void SetPlayer(unsigned int player) { m_player = player; }
	void SetIsOccupied(bool occupied) { m_isOccupied = occupied; }

	unsigned int GetPlayer() { return m_player;}
	bool GetIsOccupied() { return m_isOccupied;}
	unsigned int GetScore() { return m_score; }
	std::pair<unsigned short, unsigned short> GetPosition() { return m_position; }
	unsigned int GetNumberOfLives() { return m_numberOfLives; }
	bool  GetIsBase() { return m_isBase; }
};





