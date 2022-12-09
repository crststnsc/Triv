#include <iostream>
#include "Game.h"

int main()
{
	Player player1("player1", 0, Player::TipPlayer::Blue);
	Player player2("player2", 0, Player::TipPlayer::Yellow);
	Player player3("player3", 0, Player::TipPlayer::Red);

	std::vector<Player> players;
	players.push_back(player1);
	players.push_back(player2);
	players.push_back(player3);

	Board board((int)players.size());

	QuestionsBank questionsBank("questions.txt");

	Game game(players, questionsBank, board);
	game.ChooseBasePhase();
	std::cout << game.GetBoard();
	
	for (auto player : game.GetPlayers()) {
		std::cout << player.GetPlayerScore() << ' ';
	}

	game.ChooseTerritoryPhase();
	std::cout << game.GetBoard();

	for (auto player : game.GetPlayers()) {
		std::cout << player.GetPlayerScore() << ' ';
	}
}