#include "Game.h"

bool sortByAnswer(std::pair<unsigned short, Player*>& a, std::pair<unsigned short, Player*>& b) {
	return a.first > b.first;
}

void Game::ChooseBasePhase()
{
	//afiseaza intrebare cu raspuns numeric
	//momentan e prima
	SingleAnswerQuestion question = m_questionsBank.GetQuestions()[1];
	std::cout << question << std::endl;

	std::vector<std::pair<unsigned short, Player*>> chooseBaseLeaderboard;
	unsigned short playerInput, difference;

	for (auto& player : m_players)
	{		
		std::cout << "Player input: ";
		std::cin >> playerInput;

		difference = std::abs(question.GetCorrectAnswer() - playerInput);	
		chooseBaseLeaderboard.push_back(std::make_pair(difference, &player));
	}

	std::sort(chooseBaseLeaderboard.begin(), chooseBaseLeaderboard.end(), sortByAnswer);

	for (auto& pair : chooseBaseLeaderboard) {
		pair.second->ChooseBase(m_board);
	}
}

void Game::ChooseTerritoryPhase()
{
	//Question.PopUp();
	//primeste prima intrebare, trebuie modificat
	SingleAnswerQuestion question = m_questionsBank.GetQuestions()[1];
	std::vector<std::pair<unsigned short, Player*>> chooseTerritoryLeaderboard;
	std::cout << question;
	for (auto& player : m_players)
	{
		unsigned short playerInput, difference;

		std::cout << "Player input: ";
		std::cin >> playerInput;

		difference = std::abs(question.GetCorrectAnswer() - playerInput);
		chooseTerritoryLeaderboard.push_back(std::make_pair(difference, &player));
	}

	std::sort(chooseTerritoryLeaderboard.begin(), chooseTerritoryLeaderboard.end(), sortByAnswer);

	for (int i = 0; i < chooseTerritoryLeaderboard.size() - 1; i++) {
		for (int j = chooseTerritoryLeaderboard.size() - i - 1; j > 0; j--)
		{
			chooseTerritoryLeaderboard[i].second->ChooseTerritory(m_board);
		}
	}
}

void Game::DuelPhase()
{
	//se ataca cat timp se joaca cel putin 2 playeri
	//sunt n atacuri
	//se alege random cine ataca
	//player.attack()
	//daca atacul e bun
	//territory.SetPlayer((int)m_tipPlayer);
	//in caz de baza trec toate teritoriile
	//update score

	int n = 10;
	int PlayersLeft = (int)m_players.size();

	while (n && PlayersLeft) {
		srand(time(NULL));
		Player player = m_players[rand() % m_players.size()];
		unsigned int x, y;
		std::cout << "Choose territory: ";
		std::cin >> x >> y;

		player.Attack(m_board, std::make_pair(x, y));

		for (auto& players : m_players) {
			players.UpdateScore();
			if (players.GetPlayerScore() == 0) 
				PlayersLeft--;
		}
	}
}

void Game::ChooseWinnerPhase()
{
	std::sort(m_players.begin(), m_players.end(), PlayerCompare());

	int place = 1;
	//de gasit solutie pt 2 iteratori in for, gen make_zip_iterator?
	for (auto& player : m_players)
	{
		if (place == 1) std::cout << "First Place: " << player.GetPlayerName() << "\n";
		if (place == 2) std::cout << "Second Place: " << player.GetPlayerName() << "\n";
		if (place == 3) std::cout << "Third Place: " << player.GetPlayerName() << "\n";
		if (place == 4) std::cout << "Fourth Place: " << player.GetPlayerName() << "\n";
		place++;
	}
}
