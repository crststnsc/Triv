#include "SingleAnswer.h"
#include "PlayerInfo.h"

int PlayerInfo::id;
std::string PlayerInfo::username;

SingleAnswer::SingleAnswer(QWidget* parent)
	: QMainWindow(parent)
{
	m_singleAnswer.setupUi(this);
	m_singleAnswer.timer->setValue(15);
	timerFunction();
	setQuestion();
}

SingleAnswer::~SingleAnswer()
{}

void SingleAnswer::setQuestion()
{
	cpr::Response r = cpr::Get(cpr::Url{ "http://localhost:18080/getnumericquestion" });
	auto question = crow::json::load(r.text);
	std::string questionString = question["question"].s();
	
	/*questionId = question["id"].i();
	std::string qid = std::to_string(questionId);
	m_singleAnswer.label->setText(qid.c_str());*/

	m_singleAnswer.question->setText(questionString.c_str());
}

void SingleAnswer::on_submitButton_clicked()
{
	std::string answer = m_singleAnswer.lineEdit->text().toUtf8().constData();

	cpr::Response response = cpr::Get(cpr::Url{ "http://localhost:18080/giveanswer/" + std::to_string(PlayerInfo::id)},
		cpr::Payload{ {"answer", answer}, {"questionId", std::to_string(1)}});
}

void SingleAnswer::timerFunction()
{
	if (m_singleAnswer.timer->value() >= 0)
	{
		m_singleAnswer.timer->setValue(m_singleAnswer.timer->value() - 1);
		QTimer::singleShot(1000, this, SLOT(timerFunction()));
	}
	if (m_singleAnswer.timer->value() == 0)
	{
		hide();
	}
}



