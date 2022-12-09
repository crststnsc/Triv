#pragma once
#include "Question.h"
#include <vector>
#include <fstream>

class QuestionsBank
{
private:
	std::vector<Question> m_questions;
	std::string m_fileName;

	void ParseQuestions(std::string fileName);
public:
	QuestionsBank(std::string fName) {
		m_fileName = fName;
		ParseQuestions(m_fileName);
	}

	void SetQuestions(std::vector<Question> questions) { m_questions = questions; }

	std::vector<Question> GetQuestions() { return m_questions; }
};

