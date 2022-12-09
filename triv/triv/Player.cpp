#include "Player.h"
#include "Territory.h"
#include "Board.h"
#include "Game.h"
#include <chrono>

Player::Player(std::string playerName, unsigned int playerScore, TipPlayer tipPlayer) :
	m_playerName(playerName), m_playerScore (playerScore) , m_tipPlayer( tipPlayer ){}

void Player::SetPlayerName(std::string name)
{
	m_playerName = name;
}

std::string Player::GetPlayerName()
{
	return m_playerName;
}

void Player::SetPlayerScore(int score)
{
	m_playerScore = score;
}

unsigned int Player::GetPlayerScore()
{
	return m_playerScore;
}

bool  Player::Attack(Board board, std::pair<unsigned int ,unsigned int > position)
{
	//primeste un teritoriu ca parametru
	//verifica daca e un inamic si e vecin
	//daca atacul e bun
	//territory.SetPlayer((int)m_tipPlayer);
	//in caz de baza trec toate teritoriile
	//update score
	
	if (board[position].GetPlayer() == (int)m_tipPlayer)
	{
		std::cout << "Nu puteti ataca teritoriu propriu\n";
		return false;
	}
	else
	{
		if (board[position].GetPlayer() == board[{position.first - 1, position.second - 1}].GetPlayer() ||
			board[position].GetPlayer() == board[{position.first - 1, position.second}].GetPlayer()     ||
			board[position].GetPlayer() == board[{position.first - 1, position.second + 1}].GetPlayer() ||
			board[position].GetPlayer() == board[{position.first, position.second - 1}].GetPlayer()     ||
			board[position].GetPlayer() == board[{position.first, position.second + 1}].GetPlayer()     ||
			board[position].GetPlayer() == board[{position.first + 1, position.second - 1}].GetPlayer() ||
			board[position].GetPlayer() == board[{position.first + 1, position.second}].GetPlayer()     ||
			board[position].GetPlayer() == board[{position.first + 1, position.second + 1}].GetPlayer())
		{		
			return true;
		}
		else
		{
			std::cout << "Nu puteti ataca teritoriu care nu este vecin cu teritoriu propriu\n";
			return false;
		}
	}	
}

int Player::CalculateScore()
{
	int score = 0;
	for (int i = 0; i < m_territories.size(); i++)
	{
		score = score + m_territories[i].GetScore();
	}
	return score;
}

void Player::UpdateScore()
{
	m_playerScore = CalculateScore();
}

void Player::GetPlayerColor()
{
	switch ((int)m_tipPlayer)
	{
	case 1:
		std::cout << "Blue";
		break;
	case 2:
		std::cout << "Yellow";
		break;
	case 3:
		std::cout << "Red";
		break;
	case 4:
		std::cout << "Green";
		break;
	default:
		break;
	}
}

std::string Player::GetAnswer()
{
	std::cin >> m_answer;
	return m_answer;
}

std::chrono::steady_clock::time_point Player::InitialTime()
{
	std::chrono::steady_clock::time_point m_beforeAnswer = std::chrono::steady_clock::now();
	return m_beforeAnswer;

}

std::chrono::duration<float> Player::FinalTime()
{
	
	std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
	std::chrono::duration<float> duration = end - InitialTime();
	return duration;

}

std::vector<Territory> Player::GetTerritories()
{
	return m_territories;
}

void Player::AddTerritory(Territory territory)
{
	m_territories.push_back(territory);
}

int& Player::GetPlayerNumber()
{
	return int(m_tipPlayer);
}

void Player::TransferTerritoriesTo(Player player)
{
	for (int i = 0; i < m_territories.size(); i++)
	{
		m_territories[i].SetPlayer(player.GetPlayerNumber());
		if (m_territories[i].GetIsBase())
		{
			m_territories[i].SetIsBase(false);
		}
		player.AddTerritory(m_territories[i]);
	}
	m_territories.clear();
}

void Player::ChooseTerritory(Board& board)
{
	std::pair<unsigned short, unsigned short> pos;
	bool ok = false;
	while (ok == false)
	{
		std::cout << "Choose territory position: ";
		std::cin >> pos.first >> pos.second;
		if (board[pos].GetIsOccupied() == false)
		{
			for (int i = 0; i < m_territories.size(); i++)
			{
				if (std::abs(int(m_territories[i].GetPosition().first) - pos.first) + 
				std::abs(int(m_territories[i].GetPosition().second) - pos.second) == 1)
				{
					ok = true;
					board[pos].SetIsOccupied(true);
					board[pos].SetPlayer(unsigned short(m_tipPlayer));
					m_territories.push_back(board[pos]);
					UpdateScore();
					break;
				}
			}
		}
	}
}

void Player::ChooseBase(Board& board)
{
	std::pair<unsigned short, unsigned short> pos;
	bool ok = false;
	while (ok == false)
	{
		std::cout << "Choose base position: ";
		std::cin >> pos.first >> pos.second;
		if (board[pos].GetIsOccupied() == false)
		{
			ok = true;
			board[pos].SetIsBase(true);
			board[pos].SetIsOccupied(true);
			board[pos].SetNumberOfLives(3);
			board[pos].SetPlayer(unsigned short(m_tipPlayer));
			board[pos].SetScore(300);
			m_territories.push_back(board[pos]);
			UpdateScore();
		}
	}
}



