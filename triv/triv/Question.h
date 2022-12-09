#pragma once
#include "SingleAnswerQuestion.h"

class Question: public SingleAnswerQuestion
{
private:
	std::string m_answer1;
	std::string m_answer2;
	std::string m_answer3;
	std::string m_answer4;
public:
	Question(std::string question, std::string answer1, std::string answer2,
		std::string answer3, std::string answer4, unsigned short correctAnswer):
		SingleAnswerQuestion(question, correctAnswer) 
	{
		m_answer1 = answer1;
		m_answer2 = answer2;
		m_answer3 = answer3;
		m_answer4 = answer4;
	}
	
	Question():SingleAnswerQuestion() {
		m_answer1 = "";
		m_answer2 = "";
		m_answer3 = "";
		m_answer4 = "";
	}

	void SetQuestion(std::string question) { m_question = question; }
	void SetAnswer1(std::string answer) { m_answer1 = answer; }
	void SetAnswer2(std::string answer) { m_answer2 = answer; }
	void SetAnswer3(std::string answer) { m_answer3 = answer; }
	void SetAnswer4(std::string answer) { m_answer4 = answer; }
	void SetCorrectAnswer(unsigned short answer) { m_correctAnswer = answer; }

	std::string GetAnswer1() { return m_answer1; }
	std::string GetAnswer2() { return m_answer2; }
	std::string GetAnswer3() { return m_answer3; }
	std::string GetAnswer4() { return m_answer4; }

	friend std::ostream& operator <<(std::ostream& out, const Question& q) {
		out << q.m_question << std::endl;
		out << q.m_answer1 << std::endl;
		out << q.m_answer2 << std::endl;
		out << q.m_answer3 << std::endl;
		out << q.m_answer4;
		return out;
	}
};

