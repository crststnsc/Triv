#pragma once

#include<QMessageBox>
#include "ui_threePlayersGame.h"
#include<cpr/cpr.h>
#include<crow.h>

class threePlayersGame : public QMainWindow
{
	Q_OBJECT

public:
	threePlayersGame(QWidget *parent = nullptr);
	~threePlayersGame();
	void attackSelect3P();
private slots:
	void on_poz0_0_clicked();
	void on_poz0_1_clicked();
	void on_poz0_2_clicked();
	void on_poz0_3_clicked();
	void on_poz0_4_clicked();
	void on_poz1_0_clicked();
	void on_poz1_1_clicked();
	void on_poz1_2_clicked();
	void on_poz1_3_clicked();
	void on_poz1_4_clicked();
	void on_poz2_0_clicked();
	void on_poz2_1_clicked();
	void on_poz2_2_clicked();
	void on_poz2_3_clicked();
	void on_poz2_4_clicked();
private:
	int i, j;
	Ui::threePlayersGameClass m_3players;
};
