#include "Question.h"

std::ostream& operator <<(std::ostream& out, const Question& q) {
	out << q.m_question << std::endl;
	out << q.m_answer1 << std::endl;
	out << q.m_answer2 << std::endl;
	out << q.m_answer3 << std::endl;
	out << q.m_answer4 << std::endl;
	return out;
}

void Question::SetQuestion(const std::string& question)
{
	m_question = question;
}

void Question::SetAnswer3(const std::string& answer)
{
	m_answer3 = answer;
}

void Question::SetAnswer4(const std::string& answer)
{
	m_answer4 = answer;
}

void Question::SetCorrectAnswer(const unsigned short& answer)
{
	m_correctAnswer = answer;
}

const std::string& Question::GetQuestion() const
{
	return m_question;
}

const std::string& Question::GetAnswer1() const
{
	return m_answer1;
}

const std::string& Question::GetAnswer2() const
{
	return m_answer2;
}

const std::string& Question::GetAnswer3() const
{
	return m_answer3;
}

const std::string& Question::GetAnswer4() const
{
	return m_answer4;
}

void Question::SetAnswer1(const std::string& answer) 
{
	m_answer1 = answer;
}

void Question::SetAnswer2(const std::string& answer) 
{
	m_answer2 = answer;
}
