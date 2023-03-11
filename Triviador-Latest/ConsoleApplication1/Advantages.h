#pragma once
#include <string>
#include "Question.h"
#include <vector>
class Advantages
{
private:
	bool m_fiftyFifty;
	bool m_giveAnswers;
	bool m_suggestAnswer;
public:
	Advantages()
	{
		m_fiftyFifty = true;
		m_giveAnswers = true;
		m_suggestAnswer = true;
	}
	bool UseNumericAdvantage(SingleAnswerQuestion question);
	bool UseAdvantage(Question question);
	void FiftyFifty(Question question);
	void SuggestAnswer(SingleAnswerQuestion question);
	void GiveAnswers(SingleAnswerQuestion question);
};
