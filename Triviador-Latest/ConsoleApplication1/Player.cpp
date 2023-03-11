#include "Player.h"


Player::Player(std::string playerName, unsigned short playerScore, TipPlayer tipPlayer) :
	m_playerName(playerName), m_playerScore(playerScore), m_tipPlayer(tipPlayer) {}

void Player::SetPlayerName(const std::string& name)
{
	m_playerName = name;
}
const std::string& Player::GetPlayerName() const
{
	return m_playerName;
}
void Player::SetPlayerScore(const short& score)
{
	m_playerScore = score;
}

const  short& Player::GetPlayerScore() const
{
	return m_playerScore;
}
 bool Player::Attack(const Board& board,const Territory::Position& position) 
{
	if (board[position].GetPlayer() == (uint8_t)m_tipPlayer)
	{
		std::cout << "Nu puteti ataca teritoriu propriu\n";
		return false;
	}
	else
	{
		for (int i = 0; i < m_territories.size(); i++)
		{
			int distX = std::abs(m_territories[i].GetPosition().first - position.first);
			int distY = std::abs(m_territories[i].GetPosition().second - position.second);
			if (distX + distY == 1 || (distX == distY && distX == 1))
			{
				return true;
			}
		}
	}
	std::cout << "Nu puteti ataca un teritoriu care nu va este vecin\n";
	return false;
}
 bool Player::CanUseAdvantages(const Board& board)
 {
	 for (uint8_t i=0;i<m_territories.size();++i)
	 {
		 if (board[m_territories[i].GetPosition()].GetScore() >= 200)
		 {
			 return true;
		 }
	 }
	 return false;
 }
short Player::CalculateScore()
{
	unsigned short score = 0;
	for (int i = 0; i < m_territories.size(); i++)
	{
		score = score + m_territories[i].GetScore();
	}
	return score;
}
const std::string& Player::GetPlayerColor() const
{
	switch ((uint8_t)m_tipPlayer)
	{
	case 1:
		return "Blue";
	case 2:
		return "Yellow";
	case 3:
		return "Red";
	case 4:
		return "Green";
	}
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
void Player::RemoveTerritory(const Territory& territory)
{
	for (int i = 0; i < m_territories.size(); i++)
	{
		if (m_territories[i].GetPosition() == territory.GetPosition())
		{
			m_territories.erase(m_territories.begin() + i);
			break;
		}
	}
}
const std::vector<Territory>& Player::GetTerritories() const
{
	return m_territories;
}
void Player::AddTerritory(const Territory& territory)
{
	m_territories.push_back(territory);
}
const uint8_t& Player::GetPlayerNumber() const
{
	return uint8_t(m_tipPlayer);
}
void Player::TransferTerritoriesTo(Board& board, Player& player)
{
	for (int i = 0; i < m_territories.size(); i++)
	{
		m_territories[i].SetPlayer(uint8_t(player.m_tipPlayer));
		if (m_territories[i].GetIsBase())
		{
			m_territories[i].SetIsBase(false);
		}
		player.AddTerritory(m_territories[i]);
		board[{m_territories[i].GetPosition()}].SetPlayer(player.GetPlayerNumber());
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
				int distX = std::abs(m_territories[i].GetPosition().first - pos.first);
				int distY = std::abs(m_territories[i].GetPosition().second - pos.second);
				if (distX + distY == 1 || (distX == distY && distX == 1))
				{
					ok = true;
					board[pos].SetIsOccupied(true);
					board[pos].SetPlayer(unsigned short(m_tipPlayer));
					m_territories.push_back(board[pos]);
					m_playerScore = CalculateScore();
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
			m_playerScore = CalculateScore();
		}
	}
}



