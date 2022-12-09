#include "Advantages.h"
#include "Question.h"
#include "Player.h"

void Advantages::CallAdvantage()
{
	Advantages advantage;
	std::string input;
	std::cin >> input;
	if (input == "Fifty Fifty") {
		advantage.FiftyFifty();
	}
	else if (input == "SuggestAnswer") {
		std::cout << "no function";
	}
	else if (input == "GiveAnswers") {
		advantage.GiveAnswers();
	}
}

void Advantages::FiftyFifty()
{
	Question question;
	std::vector<std::string> answers;
	std::vector<std::string> incorrectAnswers;
	std::string correctAnswer = "";

	std::string answer1 = question.GetAnswer1();

	answers.push_back(answer1);

	if (answer1 != std::to_string(question.GetCorrectAnswer())) 
		incorrectAnswers.push_back(answer1);
	else 
		correctAnswer = answer1;
	
	std::string answer2 = question.GetAnswer2();
    answers.push_back(answer2);
	
	if (answer2 != std::to_string(question.GetCorrectAnswer())) 
		incorrectAnswers.push_back(answer2);
	else 
		correctAnswer = answer2;
	
	std::string answer3 = question.GetAnswer3();
	
	answers.push_back(answer3);
	
	if (answer3 != std::to_string(question.GetCorrectAnswer())) 
		incorrectAnswers.push_back(answer3);
	else 
		correctAnswer = answer3;
	
	std::string answer4 = question.GetAnswer4();
	answers.push_back(answer4);
	
	if (answer4 != std::to_string(question.GetCorrectAnswer())) 
		incorrectAnswers.push_back(answer4);
	else 
		correctAnswer = answer4;

	std::string otherAnswer = incorrectAnswers[rand() % incorrectAnswers.size()];
	for (auto& a : answers) {
		if (a == correctAnswer || a == otherAnswer) {
			std::cout << a << "\n";
		}
		else std::cout << "\n";
	}

}

//void Advantages::SuggestAnswer()
//{
//	//aici nu prea stiu cum sa fac sincer, de discutat
//	Player player;
//	Question question;
//	unsigned short answer = question.GetCorrectAnswer() - 15 + (rand() % question.GetCorrectAnswer() + 15);
//	question.SetAnswer1(std::to_string(answer));
//	if (answer == question.GetCorrectAnswer()) {
//		player.UpdateScore(player.GetPlayerScore()+100);
//	}
//}

void Advantages::GiveAnswers()
{
	SingleAnswerQuestion question;
	for (int i = 0; i < 4; i++) {
		srand(time(NULL));
		std::cout << question.GetCorrectAnswer() - 20 + (rand() % question.GetCorrectAnswer() + 20) << "    ";
	}
	std::cout << "\nChoose Answer: ";
	unsigned short answer;
	std::cin >> answer;
}
