#pragma once

#include <QtWidgets/QMainWindow>
#include <QMessageBox>
#include "ui_SecondWindow.h"
#include "fourPlayersGame.h"
#include "ProfileWindow.h"
#include "threePlayersGame.h"
#include "twoPlayersGame.h"
#include <QTimer>
#include <cpr/cpr.h>
#include <crow.h>
#include "Lobby.h"

class SecondWindow : public QMainWindow
{
	Q_OBJECT

public:
	SecondWindow(QWidget* m_singleAnswer,QWidget *parent = nullptr);
	~SecondWindow();
	void setUsername(std::string username);
	std::string getUsername();
private slots:
	void on_Profil_Button_clicked();
	void on_two_players_clicked();
	void on_three_players_clicked();
	void on_four_players_clicked();

private:
	Ui::SecondWindowClass m_menu;
	fourPlayersGame* m_4players;
	threePlayersGame* m_3players;
	twoPlayersGame* m_2players;
	ProfileWindow* profileUi;
	QWidget* m_singleAnswer;
	Lobby* lobby;
	std::string m_username;
};
