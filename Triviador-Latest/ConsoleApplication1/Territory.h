#pragma once
#include <utility>
class Territory
{
private:
	unsigned short m_score;
	std::pair<uint8_t, uint8_t> m_position;
	uint8_t m_numberOfLives;
	uint8_t m_player;
	bool m_isOccupied;
	bool m_isBase;
public:
	using Position = std::pair<uint8_t, uint8_t>;
	Territory(Position position, unsigned short score = 100, uint8_t player = 0,
		uint8_t numberOfLives = 1, bool isBase = false, bool occupied = false);
	void SetScore(const unsigned short& score);
	void SetPosition(const Position& position);
	void SetNumberOfLives(const uint8_t& numberOfLives);
	void SetIsBase(const bool& isBase);
	void SetPlayer(const uint8_t& player);
	void SetIsOccupied(const bool& occupied);
	const uint8_t& GetPlayer() const;
	const bool& GetIsOccupied() const;
	const unsigned short& GetScore() const;
	const Position& GetPosition() const;
	const uint8_t& GetNumberOfLives() const;
	const bool& GetIsBase() const;
};





