#include "Advantages.h"


bool Advantages::UseNumericAdvantage(SingleAnswerQuestion question)
{
		if (m_suggestAnswer == true)
		{
			std::cout << "You can use the Suggest Answer advantage!" << std::endl;
		}
		if (m_giveAnswers == true)
		{
			std::cout << "You can use the Give Answers advantage!" << std::endl;
		}
		if (m_suggestAnswer == false && m_giveAnswers == false)
		{
			std::cout << "You don`t have any advantages left for this type of question!" << std::endl;
			return false;
		}
		std::string advantageName;
		std::cout << "Type the advantage you want to use:" << std::endl;
		std::cin.ignore();
		std::getline(std::cin, advantageName);
		if (advantageName == "Suggest Answer" && m_suggestAnswer == true)
		{
			SuggestAnswer(question);
			return true;
		}
		else if (advantageName == "Give Answers" && m_giveAnswers == true)
		{
			GiveAnswers(question);
			return true;
		}
		else
		{
			std::cout << "The advantage you tried to use is not valid!" << std::endl;
			return false;
		}
}

bool Advantages::UseAdvantage(Question question)
{
	std::string advantageName;
		if (m_fiftyFifty == true)
		{
			std::cout << "You can use the Fifty Fifty advantage" << std::endl;
		}
		else
		{
			std::cout << "You don`t have any advantages left for this type of question"<<std::endl;
			return false;
		}
		std::cout << "Type the advantage you want to use" << std::endl;
		std::cin.ignore();
		std::getline(std::cin, advantageName);
		if (advantageName == "Fifty Fifty")
		{
			FiftyFifty(question);
			return true;
		}
		else
		{
			std::cout << "The advantage you tried to use is not valid!" << std::endl;
			return false;
		}	
}

void Advantages::FiftyFifty(Question question)
{
	m_fiftyFifty = false;
	std::vector<std::string> answers{ question.GetAnswer1(), question.GetAnswer2(), question.GetAnswer3(), question.GetAnswer4() };
	uint8_t randomIndex1 = rand() % 4;
	if (randomIndex1 + 1 == question.GetCorrectAnswer())
	{
		uint8_t randomIndex2 = randomIndex1;
		while (randomIndex2 == randomIndex1)
		{
			randomIndex2 = rand() % 4;
		}
		std::cout << answers[randomIndex1] << ' ' << answers[randomIndex2] << std::endl;
	}
	else
	{

	}
	{
		std::cout << answers[randomIndex1] << ' ' << answers[question.GetCorrectAnswer()-1] << std::endl;
	}
	int a, b;
	
}


void Advantages::SuggestAnswer(SingleAnswerQuestion question)
{
	m_suggestAnswer = false;
	if (question.GetCorrectAnswer() < 5)
	{
		std::cout << "The suggested answer is: " << rand() % (question.GetCorrectAnswer() + 1) + rand() % 2 << std::endl;
	}
	else
	{
		std::cout << "The suggested answer is " << int(0.8 * question.GetCorrectAnswer()) + rand() % (int(1.4 * question.GetCorrectAnswer()) - question.GetCorrectAnswer() + 1) << std::endl;
	}


}

void Advantages::GiveAnswers(SingleAnswerQuestion question)
{
	m_giveAnswers = false;
	if (question.GetCorrectAnswer() < 3)
	{
		std::cout << "The answer is one of these numbers: 0, 1, 2, 3" << std::endl;
	}
	else {
		std::vector <unsigned int> answers;
		answers.push_back(question.GetCorrectAnswer());
		unsigned int randomAnswer;
		while (answers.size() < 4)
		{
			randomAnswer = int(0.5 * question.GetCorrectAnswer()) + rand() % question.GetCorrectAnswer();
			if (std::find(answers.begin(), answers.end(), randomAnswer) == answers.end())
			{
				answers.push_back(randomAnswer);
			}
		}
		std::cout << "The answer is one of these numbers: " << answers[0] << ", " << answers[1] << ", " << answers[2] << ", " << answers[3] << std::endl;
	}
}