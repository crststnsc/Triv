#pragma once

#include<QMessageBox>
#include <QtWidgets/QMainWindow>
#include "ui_LoginInterface.h"
#include "SecondWindow.h"
#include <string>
#include <cpr/cpr.h>
#include <crow.h>



class LoginInterface : public QMainWindow
{
    Q_OBJECT

public:
    LoginInterface(QWidget *parent = nullptr);
    ~LoginInterface();
	/*void resizeEvent(QResizeEvent* event);
	void settingwindow(QWidget* parent);*/
private slots:
	void on_LoginButton_clicked();
    void on_RegisterButton_clicked();
private:
    Ui::LoginInterfaceClass ui;
	SecondWindow *ui2;
};
