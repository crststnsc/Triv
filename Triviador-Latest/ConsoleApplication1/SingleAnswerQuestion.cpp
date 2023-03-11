#include "SingleAnswerQuestion.h"

std::string SingleAnswerQuestion::GetQuestion() const
{
	return m_question;
}

unsigned short SingleAnswerQuestion::GetCorrectAnswer() const
{
	return m_correctAnswer;
}
std::ostream& operator<<(std::ostream& out, const SingleAnswerQuestion& q)
{
	out << q.m_question << std::endl;
	return out;
}
