#pragma once

#include <QMainWindow>
#include "ui_SingleAnswer.h"
#include <QTimer>
#include "crow.h"
#include "cpr/cpr.h"

class SingleAnswer : public QMainWindow
{
	Q_OBJECT

public:
	SingleAnswer(QWidget* parent = nullptr);
	~SingleAnswer();
	void setQuestion();
private slots:
	void timerFunction();
	void on_submitButton_clicked();
private:
	Ui::SingleAnswerClass m_singleAnswer;
	int questionId;
};
