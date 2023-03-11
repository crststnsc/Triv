#pragma once

#include <QMainWindow>
#include "ui_Lobby.h"
#include <cpr/cpr.h>
#include <crow.h>
#include <qmessagebox.h>
#include "twoPlayersGame.h"
#include "threePlayersGame.h"
#include "fourPlayersGame.h"
#include <mutex>

class Lobby : public QMainWindow
{
	Q_OBJECT

public:
	Lobby(QWidget *parent = nullptr);
	~Lobby();
	bool isReady = false;
	bool canStart = false;
private:
	Ui::LobbyClass ui;
	twoPlayersGame* twoPlayersGameWindow;
	threePlayersGame* threePlayersGameWindow;
	fourPlayersGame* fourPlayersGameWindow;
	void searchForPlayers();
	void searchForReady();
private slots:
	void on_ReadyButton_clicked();
};
