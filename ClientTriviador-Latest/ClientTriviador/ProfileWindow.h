#pragma once

#include <QMainWindow>
#include "ui_ProfileWindow.h"
#include<QMessageBox>
#include<cpr/cpr.h>
#include<crow.h>
#include<string.h>



class ProfileWindow : public QMainWindow
{
	Q_OBJECT

public:
	ProfileWindow(QWidget *menu, QWidget *parent = nullptr);
	~ProfileWindow();
	void history();
private slots:
	void on_backToMenu_clicked();
private:
	Ui::ProfileWindowClass profileUi;
	QWidget* menu;
	 
};