#pragma once
#include "Question.h"
#include "SingleAnswerQuestion.h"
#include <vector>
#include <fstream>

class QuestionsBank
{
private:
	std::vector<Question> m_questions;
	std::vector<SingleAnswerQuestion> m_singleAnswerQuestions;
	std::string m_fileName;
	void ParseQuestions(std::string fileName);
public:
	QuestionsBank(std::string fName) {
		m_fileName = fName;
		ParseQuestions(m_fileName);
	}
	QuestionsBank() {};
	void SetQuestions(const std::vector<Question>& questions);
	const std::vector<Question>& GetQuestions() const;
	const std::vector<SingleAnswerQuestion>& GetSingleAnswerQuestions() const;
	
	
};

