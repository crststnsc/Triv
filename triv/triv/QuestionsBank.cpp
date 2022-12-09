#include "QuestionsBank.h"

void QuestionsBank::ParseQuestions(std::string fileName)
{
	std::ifstream input(fileName);

	if (input.is_open()) {
		std::string s;

		while (std::getline(input, s, ' ')) {
			std::string q, a1, a2, a3, a4;
			unsigned short answ = 0;

			q = s;
			std::getline(input, s, ' ');
			a1 = s;
			if (!a1.empty()){
				if (a1.back() == '!') {
					answ = 1;
					a1.pop_back();
				}
				if (a1.back() == '@') {
					a1.pop_back();
					answ = std::stoi(a1);
					m_questions.push_back(Question(q, a1, a2, a3, a4, answ));
					continue;
				}
			}
			
			std::getline(input, s, ' ');
			a2 = s;
			if (!a2.empty() && a2.back() == '!') {
				answ = 2;
				a2.pop_back();
			}
			std::getline(input, s, ' ');
			a3 = s;
			if (!a3.empty() && a3.back() == '!') {
				answ = 3;
				a3.pop_back();
			}
			std::getline(input, s, '\n');
			a4 = s;
			if (!a4.empty() && a4.back() == '!') {
				answ = 4;
				a4.pop_back();
			}
			m_questions.push_back(Question(q, a1, a2, a3, a4, answ));
		}
	}

	input.close();
}
