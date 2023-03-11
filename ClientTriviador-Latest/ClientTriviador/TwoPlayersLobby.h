#pragma once

#include <QMainWindow>
#include "ui_TwoPlayersLobby.h"

class TwoPlayersLobby : public QMainWindow
{
	Q_OBJECT

public:
	TwoPlayersLobby(QWidget *parent = nullptr);
	~TwoPlayersLobby();

private:
	Ui::twoPlayersLobbyClass ui;
};
