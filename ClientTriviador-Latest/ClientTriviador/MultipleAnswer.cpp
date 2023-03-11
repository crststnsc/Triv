#include "MultipleAnswer.h"

MultipleAnswer::MultipleAnswer(QTimer time,QWidget *parent)
	: QMainWindow(parent)
{
	m_multipleAnswer.setupUi(this);
	m_multipleAnswer.timer->setValue(15);
	timerFunction();
}

MultipleAnswer::~MultipleAnswer()
{}

void MultipleAnswer::setQuestion()
{
	m_multipleAnswer.question->setText("When was the first Triviador game released?");
}

void MultipleAnswer::on_answer_a_clicked()
{

}
void MultipleAnswer::on_answer_b_clicked()
{

}
void MultipleAnswer::on_answer_c_clicked()
{

}
void MultipleAnswer::on_answer_d_clicked()
{
	
}
void MultipleAnswer::timerFunction()
{
	if (m_multipleAnswer.timer->value() >= 0)
	{
		m_multipleAnswer.timer->setValue(m_multipleAnswer.timer->value() - 1);
		QTimer::singleShot(1000, this, SLOT(timerFunction()));
	}	
}


