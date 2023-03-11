#include "SecondWindow.h"
#include "PlayerInfo.h"

SecondWindow::SecondWindow(QWidget* m_singleAnswer,QWidget *parent)
	: QMainWindow(parent)
{
	m_menu.setupUi(this);
	this->m_singleAnswer = m_singleAnswer;

	SecondWindow::setFixedSize(1600, 900);
}

SecondWindow::~SecondWindow()
{}

void SecondWindow::setUsername(std::string username)
{
	m_username = username;
}

std::string SecondWindow::getUsername()
{
	return m_username;
}

void SecondWindow::on_Profil_Button_clicked()
{
	hide();
	profileUi = new ProfileWindow(this);
	profileUi->showMaximized();
}

void SecondWindow::on_two_players_clicked()
{
	PlayerInfo p;
	cpr::Response r = cpr::Get(cpr::Url{ "http://localhost:18080/join/" + PlayerInfo::username});
	
	if (r.status_code == 200)
	{
		hide();
		lobby = new Lobby(nullptr);
		lobby->show();
	}
	else
	{
		QMessageBox::information(this, "Error", "Error joining lobby");
	}
}

void SecondWindow::on_three_players_clicked()
{
	m_3players = new threePlayersGame(this);
	m_3players->showMaximized();
	m_singleAnswer = new SingleAnswer();
	m_singleAnswer->show();
	//	QMessageBox::information(this, "Error", "Cannot open question");
	//}
	/*auto response = cpr::Get(
		cpr::Url{ "http://localhost:8080/threePlayersGame" }
	);
	if (response.status_code == 200) { 
		m_3players = new threePlayersGame(this);
		m_3players->showMaximized();
	}
	else {
		QMessageBox::information(this, "Error", "Cannot open 3 players game");
	}*/
}

void SecondWindow::on_four_players_clicked()
{
	m_4players = new fourPlayersGame(this);
	m_4players->showMaximized();
	m_singleAnswer = new SingleAnswer();
	m_singleAnswer->show();
	/*auto response = cpr::Get(
		cpr::Url{ "http://localhost:8080/fourPlayersGame" }
	);
	if (response.status_code == 200) {
		m_4players = new fourPlayersGame(this);
		m_4players->showMaximized();
	}
	else {
		QMessageBox::information(this, "Error", "Cannot open 4 players game");
	}*/
}
