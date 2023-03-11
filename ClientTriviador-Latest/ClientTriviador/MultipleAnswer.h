#pragma once

#include <QMainWindow>
#include "ui_MultipleAnswer.h"
#include <QTimer>
#include <QMessageBox>
#include "SingleAnswer.h"

class MultipleAnswer : public QMainWindow
{
	Q_OBJECT

public:
	MultipleAnswer(QTimer time, QWidget* parent = nullptr);
	~MultipleAnswer();
	void setQuestion();
private slots:
	void timerFunction();
	void on_answer_a_clicked();
	void on_answer_b_clicked();
	void on_answer_c_clicked();
	void on_answer_d_clicked();

private:
	Ui::MultipleAnswerClass m_multipleAnswer;
};
