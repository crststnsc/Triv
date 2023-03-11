#include "Game.h"

bool sortByAnswer(std::pair<unsigned short, Player*>& a, std::pair<unsigned short, Player*>& b) {
	return a.first < b.first;
}

void Game::ChooseBasePhase(Storage& db)
{
	std::vector<std::pair<unsigned short, Player*>> chooseBaseLeaderboard;
	int playerInput, difference;

	for (auto& player : db.iterate<PlayerAnswer>())
	{
		auto question = db.get<QuestionTable>(player.question_id);

		difference = std::abs(question.correctAnswer - player.answer);
		chooseBaseLeaderboard.push_back(std::make_pair(difference, &m_players[player.player_id - 1]));
	}

	std::sort(chooseBaseLeaderboard.begin(), chooseBaseLeaderboard.end(), sortByAnswer);

	std::vector<std::string> playerNames;

	for (auto& player : chooseBaseLeaderboard)
	{
		db.insert(PlayerOrder{ -1, player.second->GetPlayerName() });
	}
}

void Game::ChooseTerritoryPhase()
{
	//Question.PopUp();

	//primeste prima intrebare, trebuie modificat
	for (int round = 0; round < m_board.GetBoard().size() / m_players.size() - 1; round++)
	{
		SingleAnswerQuestion question = m_questionsBank.GetSingleAnswerQuestions()[0];
		std::vector<std::pair<unsigned short, Player*>> chooseTerritoryLeaderboard;
		std::cout << question;
		for (auto& player : m_players)
		{
			unsigned short playerInput, difference;
			std::cout << "Player input: " << std::endl;
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
		std::cout << m_board;
	}
}

void Game::DuelPhase()
{
	Territory::Position position;
	auto& [line, column] = position;
	uint8_t roundNumber = 0;
	uint8_t playersLeft = m_players.size();
	uint8_t numberOfPlayers = m_players.size();
	while (roundNumber < numberOfPlayers * 2 && playersLeft >= 2)
	{
		roundNumber++;
		std::cout << "Round " << static_cast<unsigned int>(roundNumber) << "has started!" << std::endl;
		std::vector<int> indexVector(numberOfPlayers);
		for (uint8_t i = 0; i < indexVector.size(); i++)
		{
			indexVector[i] = m_players[i].GetPlayerNumber() - 1;
		}
		std::random_device rd;
		std::mt19937 g(rd());
		std::shuffle(indexVector.begin(), indexVector.end(), g);
		for (uint8_t i = 0; i < indexVector.size(); i++)
		{
			if (m_players[indexVector[i]].GetPlayerScore() <= 0)
			{
				continue;
			}
			std::cout << "Player " << static_cast<unsigned int>(indexVector[i]) + 1 << " has " << static_cast<unsigned int>(m_players[indexVector[i]].CalculateScore()) << " score" << std::endl;
			std::cout << "Player " << static_cast<unsigned int>(indexVector[i]) + 1 << " attacks " << std::endl;
			bool ok = false;
			while (ok == false)
			{
				unsigned short x, y;
				std::cout << "Choose the territory you want to attack:" << std::endl;
				std::cin >> x >> y;
				line = x;
				column = y;
				if (m_players[indexVector[i]].Attack(m_board, position))
				{
					ok = true;
				}
			}
			uint8_t territoryOwner;
			for (int j = 0; j < m_players.size(); j++)
			{
				if (m_players[j].GetPlayerNumber() == m_board[position].GetPlayer())
				{
					territoryOwner = j;
				}
			}
			std::cout << "You attacked player " << static_cast<unsigned int>(territoryOwner) + 1 << std::endl;
			Question question = m_questionsBank.GetQuestions()[0];
			std::cout << question;
			//trebuie schimbata partea de primit intrebari
			unsigned short player1Input, player2Input, differencePlayer1, differencePlayer2;
			if (m_players[indexVector[i]].CanUseAdvantages(m_board))
			{
				std::cout << "Do you want to use an advantage? Y/N" << std::endl;
				char answer;
				std::cin >> answer;
				if (answer == 'Y')
				{
					if (m_players[indexVector[i]].m_advantages.UseAdvantage(question))
					{
						AdvantageCost(indexVector[i] + 1);
						std::cout << "Player " << static_cast<unsigned int>(indexVector[i]) + 1 << " has " << m_players[indexVector[i]].CalculateScore() << " score" << std::endl;
					}
				}
			}
			std::cout << "Attacker input" << std::endl;
			std::cin >> player1Input;
			if (m_players[territoryOwner].CanUseAdvantages(m_board))
			{
				char answer;
				std::cout << "Do you want to use an advantage? Y/N" << std::endl;
				std::cin >> answer;
				if (answer == 'Y')
				{
					if (m_players[territoryOwner].m_advantages.UseAdvantage(question))
					{
						AdvantageCost(territoryOwner + 1);
						std::cout << "Player " << static_cast<unsigned int>(territoryOwner) + 1 << " has " << m_players[territoryOwner].CalculateScore() << " score" << std::endl;
					}
				}
			}
			std::cout << "Defender input" << std::endl;
			std::cin >> player2Input;
			if (player1Input == player2Input && player1Input == question.GetCorrectAnswer())
			{
				std::cout << "Both players answered the correctly, you will have to answer a numeric question!" << std::endl;
				SingleAnswerQuestion question2 = m_questionsBank.GetSingleAnswerQuestions()[0];
				std::cout << question2;
				if (m_players[indexVector[i]].CanUseAdvantages(m_board))
				{
					char answer;
					std::cout << "Do you want to use an advantage? Y/N" << std::endl;
					std::cin >> answer;
					if (answer == 'Y')
					{
						if (m_players[indexVector[i]].m_advantages.UseNumericAdvantage(question2))
						{
							AdvantageCost(indexVector[i] + 1);
							std::cout << "Player " << static_cast<unsigned int>(indexVector[i]) + 1 << " has " << m_players[indexVector[i]].CalculateScore() << " score" << std::endl;
						}
					}
				}
				std::cout << "Attacker input:" << std::endl;
				std::cin >> player1Input;
				if (m_players[territoryOwner].CanUseAdvantages(m_board))
				{
					char answer;
					std::cout << "Do you want to use an advantage? Y/N" << std::endl;
					std::cin >> answer;
					if (answer == 'Y')
					{
						if (m_players[territoryOwner].m_advantages.UseNumericAdvantage(question2))
						{
							AdvantageCost(territoryOwner + 1);
							std::cout << "Player " << static_cast<unsigned int>(territoryOwner) + 1 << " has " << m_players[territoryOwner].CalculateScore() << " score" << std::endl;
						}
					}
				}
				std::cout << "Defender input:" << std::endl;
				std::cin >> player2Input;
				differencePlayer1 = std::abs(question2.GetCorrectAnswer() - player1Input);
				differencePlayer2 = std::abs(question2.GetCorrectAnswer() - player2Input);
				if (differencePlayer1 < differencePlayer2)
				{
					if (m_board[position].GetScore() > 100)
					{
						m_board[position].SetScore(m_board[position].GetScore() - 100);
						std::cout << "Player " << static_cast<unsigned int>(territoryOwner) + 1 << " has " << m_players[territoryOwner].CalculateScore() << " score" << std::endl;

					}
					else
					{
						if (m_board[position].GetIsBase())
						{

							m_players[territoryOwner].TransferTerritoriesTo(m_board, m_players[indexVector[i]]);
							m_players[territoryOwner].SetPlayerScore(-1 * playersLeft);
							playersLeft--;
							std::cout << "Player " << static_cast<unsigned int>(indexVector[i]) + 1 << " has " << m_players[indexVector[i]].CalculateScore() << " score" << std::endl;
						}
						else
						{
							m_players[territoryOwner].RemoveTerritory(m_board[position]);
							m_board[position].SetPlayer(m_players[indexVector[i]].GetPlayerNumber());
							m_players[indexVector[i]].AddTerritory(m_board[position]);
							std::cout << "Player " << static_cast<unsigned int>(indexVector[i]) + 1 << " has " << m_players[indexVector[i]].CalculateScore() << " score" << std::endl;
							std::cout << "Player " << static_cast<unsigned int>(territoryOwner) + 1 << " has " << m_players[territoryOwner].CalculateScore() << " score" << std::endl;

						}
					}
				}
				else
				{
					m_board[position].SetScore(m_board[position].GetScore() + 100);
					std::cout << "Player " << static_cast<unsigned int>(territoryOwner) + 1 << " has " << m_players[territoryOwner].CalculateScore() << " score" << std::endl;
				}
			}
			else
			{
				if (player1Input == question.GetCorrectAnswer())
				{
					if (m_board[position].GetScore() > 100)
					{
						m_board[position].SetScore(m_board[position].GetScore() - 100);
						std::cout << "Player " << static_cast<unsigned int>(territoryOwner) + 1 << " has " << m_players[territoryOwner].CalculateScore() << " score" << std::endl;

					}
					else
					{
						if (m_board[position].GetIsBase())
						{

							m_players[territoryOwner].TransferTerritoriesTo(m_board, m_players[indexVector[i]]);
							playersLeft--;
							std::cout << "Player " << static_cast<unsigned int>(indexVector[i]) + 1 << " has " << m_players[indexVector[i]].CalculateScore() << " score" << std::endl;
						}
						else
						{
							m_players[territoryOwner].RemoveTerritory(m_board[position]);
							m_board[position].SetPlayer(m_players[indexVector[i]].GetPlayerNumber());
							m_players[indexVector[i]].AddTerritory(m_board[position]);
							std::cout << "Player " << static_cast<unsigned int>(indexVector[i]) + 1 << " has " << m_players[indexVector[i]].CalculateScore() << " score" << std::endl;
							std::cout << "Player " << static_cast<unsigned int>(territoryOwner) + 1 << " has " << m_players[territoryOwner].CalculateScore() << " score" << std::endl;

						}
					}
				}
				else
				{
					m_board[position].SetScore(m_board[position].GetScore() + 100);
					std::cout << "Player " << static_cast<unsigned int>(territoryOwner) + 1 << " has " << m_players[territoryOwner].CalculateScore() << " score" << std::endl;
				}

				for (auto& player : m_players)
				{
					if (player.GetPlayerScore() > 0)
						player.SetPlayerScore(player.CalculateScore());
				}
				std::cout << m_board << std::endl;
			}
		}
	}
}

void Game::ChooseWinnerPhase()
{
	std::sort(m_players.begin(), m_players.end(), PlayerCompare());

	uint8_t place = 1;
	//de gasit solutie pt 2 iteratori in for, gen make_zip_iterator?
	for (auto& player : m_players)
	{
		switch (place)
		{
		case 1:
			std::cout << "First Place: " << player.GetPlayerName() << "\n";
			break;
		case 2:
			std::cout << "Second Place: " << player.GetPlayerName() << "\n";
			break;
		case 3:
			std::cout << "Third Place: " << player.GetPlayerName() << "\n";
			break;
		case 4:
			std::cout << "Fourth Place: " << player.GetPlayerName() << "\n";
			break;
		}
		place++;
	}
}

const Board& Game::GetBoard() const
{
	return m_board;
}

const std::vector<Player>& Game::GetPlayers() const
{
	return m_players;
}

void Game::AdvantageCost(uint8_t playerNumber)
{
	Territory::Position position;
	auto& [line, column] = position;
	std::cout << "You need to pay 100 points for that advantage. Type the territory position" << std::endl;
	bool ok = false;
	while (ok == false)
	{
		unsigned short x, y;
		std::cin >> x >> y;
		line = x;
		column = y;
		if (m_board[position].GetPlayer() == playerNumber && m_board[position].GetScore() > 100)
		{
			m_board[position].SetScore(m_board[position].GetScore() - 100);
			ok = true;
		}
		else
		{
			std::cout << "You can`t use that territory. Type another position" << std::endl;
		}
	}
}

//Game StartGame(Storage db)
//{
//	std::vector<Player> players;
//
//	for (auto& it : db.iterate<GameTable>()) {
//		auto user = db.get<User>(it.user_id);
//		players.push_back(Player(user.username, 0, Player::TipPlayer(it.user_color)));
//	}
//
//	Game g(players, QuestionsBank("questions.txt"), Board(4));
//	return g;
//}

Game StartGame(Storage db, std::vector<std::string> lobby)
{
	std::vector<std::tuple<int, std::string>> users;
	for (auto& name : lobby) {
		users = db.select(sql::columns(&User::id, &User::username), sql::where(sql::c(&User::username) = name));
	}

	std::vector<Player> players;

	int color = 1;
	for (auto& user : users) {
		auto& [id, name] = user;
		players.push_back(Player(name, 0, Player::TipPlayer(color)));
		db.insert(GameTable{ -1, id, color, -1 });
		color++;
	}

	Game g(players, QuestionsBank("questions.txt"), Board(lobby.size()));
	return g;
}
