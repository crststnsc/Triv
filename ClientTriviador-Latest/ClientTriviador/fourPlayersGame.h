#pragma once

#include <QMainWindow>
#include<QMessageBox>
#include "ui_fourPlayersGame.h"
#include<cpr/cpr.h>
#include<crow.h>


class fourPlayersGame : public QMainWindow
{
	Q_OBJECT

public:
	fourPlayersGame(QWidget *parent = nullptr);
	~fourPlayersGame();
	void attackSelect4P();
private slots:
	void on_poz0_0_clicked();
	void on_poz0_1_clicked();
	void on_poz0_2_clicked();
	void on_poz0_3_clicked();
	void on_poz0_4_clicked();
	void on_poz0_5_clicked();
	void on_poz1_0_clicked();
	void on_poz1_1_clicked();
	void on_poz1_2_clicked();
	void on_poz1_3_clicked();
	void on_poz1_4_clicked();
	void on_poz1_5_clicked();
	void on_poz2_0_clicked();
	void on_poz2_1_clicked();
	void on_poz2_2_clicked();
	void on_poz2_3_clicked();
	void on_poz2_4_clicked();
	void on_poz2_5_clicked();
	void on_poz3_0_clicked();
	void on_poz3_1_clicked();
	void on_poz3_2_clicked();
	void on_poz3_3_clicked();
	void on_poz3_4_clicked();
	void on_poz3_5_clicked();

private:
	int i, j;
	Ui::GameWindowClass m_4players;
};
