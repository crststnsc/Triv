#pragma once

#include<QMessageBox>
#include "ui_twoPlayersGame.h"
#include "SingleAnswer.h"
#include <cpr/cpr.h>
#include <crow.h>
#include "MultipleAnswer.h"

class twoPlayersGame : public QMainWindow
{
	Q_OBJECT

public:
	twoPlayersGame(QWidget* parent = nullptr);
	~twoPlayersGame();
	void attackSelect2P();
private slots:
	void on_poz0_0_clicked();
	void on_poz0_1_clicked();
	void on_poz0_2_clicked();
	void on_poz1_0_clicked();
	void on_poz1_1_clicked();
	void on_poz1_2_clicked();
	void on_poz2_0_clicked();
	void on_poz2_1_clicked();
	void on_poz2_2_clicked();
private:
	Ui::twoPlayersGameClass m_2players;
	int i, j;
};
