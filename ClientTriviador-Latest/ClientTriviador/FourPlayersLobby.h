#pragma once

#include <QMainWindow>
#include "ui_FourPlayersLobby.h"

class FourPlayersLobby : public QMainWindow
{
	Q_OBJECT

public:
	FourPlayersLobby(QWidget *parent = nullptr);
	~FourPlayersLobby();

private:
	Ui::FourPlayersLobbyClass ui;
};
