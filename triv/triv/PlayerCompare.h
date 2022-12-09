#pragma once
#include "Player.h"

class PlayerCompare
{
public:
	bool operator() (Player& player1, Player& player2) {
		return player1.GetPlayerScore() > player2.GetPlayerScore();
	}
};