#pragma once
#include <string>
#include <iostream>
class SingleAnswerQuestion
{
protected:
	std::string m_question;
	unsigned short m_correctAnswer;
public:
	SingleAnswerQuestion(std::string q, unsigned short a) {
		m_question = q;
		m_correctAnswer = a;
	}

	SingleAnswerQuestion() {
		m_question = "";
		m_correctAnswer = 0;
	}

	std::string GetQuestion() const;
	unsigned short GetCorrectAnswer() const;
	friend std::ostream& operator<<(std::ostream& out, const SingleAnswerQuestion& q);


};
