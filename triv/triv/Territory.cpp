#include "Territory.h"

Territory::Territory(std::pair<unsigned short, unsigned short> position, unsigned int score, unsigned int numberOfLives, bool isBase,unsigned int player, bool occupied) :
	m_position( position ), m_score( score ), m_numberOfLives( numberOfLives ), m_isBase( isBase ), m_player( player ), m_isOccupied( occupied ){}

