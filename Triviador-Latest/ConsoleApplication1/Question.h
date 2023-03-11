#pragma once
#include <string>
#include "SingleAnswerQuestion.h"
#include <iostream>
class Question: public SingleAnswerQuestion
{
private:
	std::string m_answer1;
	std::string m_answer2;
	std::string m_answer3;
	std::string m_answer4;
public:
	Question(std::string question, std::string answer1, std::string answer2,
		std::string answer3, std::string answer4, unsigned short correctAnswer){
		m_question = question;
		m_correctAnswer = correctAnswer;
		m_answer1 = answer1;
		m_answer2 = answer2;
		m_answer3 = answer3;
		m_answer4 = answer4;
	}
	
	Question() {
		SingleAnswerQuestion::SingleAnswerQuestion();
		m_answer1 = "";
		m_answer2 = "";
		m_answer3 = "";
		m_answer4 = "";
	}

	void SetQuestion(const std::string& question);
	void SetAnswer1(const std::string& answer);
	void SetAnswer2(const std::string& answer);
	void SetAnswer3(const std::string& answer);
	void SetAnswer4(const std::string& answer);
	void SetCorrectAnswer(const unsigned short& answer);
	const std::string& GetQuestion() const;
	const std::string& GetAnswer1() const;
	const std::string& GetAnswer2() const;
	const std::string& GetAnswer3() const;
	const std::string& GetAnswer4() const;
	friend std::ostream& operator <<(std::ostream& out, const Question& q);
};

