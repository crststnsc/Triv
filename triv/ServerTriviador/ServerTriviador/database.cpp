#include "database.h"

void populateDatabase(Storage& database)
{
	std::vector<Player> players = {
		Player{-1, "player1", 0},
		Player{-1, "player2", 0}
	};
	database.insert_range(players.begin(), players.end());
}
