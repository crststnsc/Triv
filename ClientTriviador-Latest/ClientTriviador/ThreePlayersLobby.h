#pragma once

#include <QMainWindow>
#include "ui_ThreePlayersLobby.h"

class ThreePlayersLobby : public QMainWindow
{
	Q_OBJECT

public:
	ThreePlayersLobby(QWidget *parent = nullptr);
	~ThreePlayersLobby();

private:
	Ui::ThreePlayersLobbyClass ui;
};
