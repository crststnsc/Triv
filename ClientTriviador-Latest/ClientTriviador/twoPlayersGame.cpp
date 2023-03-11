#include "twoPlayersGame.h"


twoPlayersGame::twoPlayersGame(QWidget* parent)
	: QMainWindow(parent)
{
	m_2players.setupUi(this);
	twoPlayersGame::setFixedSize(1600, 900);
	
	SingleAnswer* singleAnswer = new SingleAnswer();
	singleAnswer->show();
}

twoPlayersGame::~twoPlayersGame()
{}
void twoPlayersGame::attackSelect2P()
{

}
void twoPlayersGame::on_poz0_0_clicked()
{
	i = 0;
	j = 0;
	auto response = cpr::Get(
		cpr::Url{ "http://localhost:8080/poz" + std::to_string(i) + "/" + std::to_string(j) }

	);
}
void twoPlayersGame::on_poz0_1_clicked()
{
	i = 0;
	j = 1;
	auto response = cpr::Get(
		cpr::Url{ "http://localhost:8080/poz" + std::to_string(i) + "/" + std::to_string(j) }
	);
}

void twoPlayersGame::on_poz0_2_clicked()
{
	i = 0;
	j = 2;
	auto response = cpr::Get(
		cpr::Url{ "http://localhost:8080/poz" + std::to_string(i) + "/" + std::to_string(j) }
	);
}

void twoPlayersGame::on_poz1_0_clicked()
{
	i = 1;
	j = 0;
	auto response = cpr::Get(
		cpr::Url{ "http://localhost:8080/poz" + std::to_string(i) + "/" + std::to_string(j) }
	);
}
void twoPlayersGame::on_poz1_1_clicked()
{
	i = 1;
	j = 1;
	auto response = cpr::Get(
		cpr::Url{ "http://localhost:8080/poz" + std::to_string(i) + "/" + std::to_string(j) }
	);
}
void twoPlayersGame::on_poz1_2_clicked()
{
	i = 1;
	j = 2;
	auto response = cpr::Get(
		cpr::Url{ "http://localhost:8080/poz" + std::to_string(i) + "/" + std::to_string(j) }
	);
}

void twoPlayersGame::on_poz2_0_clicked()
{
	i = 2;
	j = 0;
	auto response = cpr::Get(
		cpr::Url{ "http://localhost:8080/poz" + std::to_string(i) + "/" + std::to_string(j) }
	);
}
void twoPlayersGame::on_poz2_1_clicked()
{
	i = 2;
	j = 1;
	auto response = cpr::Get(
		cpr::Url{ "http://localhost:8080/poz" + std::to_string(i) + "/" + std::to_string(j) }
	);
}
void twoPlayersGame::on_poz2_2_clicked()
{
	i = 2;
	j = 2;
	auto response = cpr::Get(
		cpr::Url{ "http://localhost:8080/poz" + std::to_string(i) + "/" + std::to_string(j) }
	);
}
