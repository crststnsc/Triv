#include "database.h"

void defineTerritories(Storage& db) {
	
	std::vector<TerritoryTable> territories;
	
	for (int i = 0; i < 24; i++)
	{
		territories.push_back(TerritoryTable{ -1, 100 });
	}

	db.insert_range(territories.begin(), territories.end());
}