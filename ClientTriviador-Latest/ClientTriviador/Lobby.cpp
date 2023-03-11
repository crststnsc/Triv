#include "Lobby.h"
#include "PlayerInfo.h"

void Lobby::searchForPlayers() {
	while (!isReady) {
		cpr::Response r = cpr::Get(cpr::Url{ "http://localhost:18080/getplayernames" });
		auto names = crow::json::load(r.text);
		std::vector<std::string> namesVector(4);

		int i = 0;
		for (auto& name : names["players"])
		{
			std::string nameString = name["name"].s();
			namesVector[i] = nameString;
			i++;
		}
		
		namesVector[0] = "1. " + namesVector[0];
		namesVector[1] = "2. " + namesVector[1];
		namesVector[2] = "3. " + namesVector[2];
		namesVector[3] = "4. " + namesVector[3];
		ui.label_2->setText(namesVector[0].c_str());
		ui.label_3->setText(namesVector[1].c_str());
		ui.label_4->setText(namesVector[2].c_str());
		ui.label_5->setText(namesVector[3].c_str());
		std::this_thread::sleep_for(std::chrono::seconds(1));
	}
}

void Lobby::searchForReady() {
	cpr::Response r = cpr::Get(cpr::Url{ "http://localhost:18080/hasgamestarted" });
	
	while (r.status_code == 400) {
		cpr::Response ready = cpr::Get(cpr::Url{ "http://localhost:18080/getreadyplayers" });
		auto names = crow::json::load(ready.text);
		std::vector<std::string> namesVector(4);

		for (auto& name : names["players"])
		{
			std::string nameString = name["name"].s();
			std::string labelString1 = ui.label_2->text().toUtf8().constData();
			std::string labelString2 = ui.label_3->text().toUtf8().constData();
			std::string labelString3 = ui.label_4->text().toUtf8().constData();
			std::string labelString4 = ui.label_5->text().toUtf8().constData();

			if (labelString1.erase(0, 3) == nameString) {
				ui.label_2->setText(("1. " + nameString + " (ready)").c_str());
			}

			if (labelString2.erase(0, 3) == nameString) {
				ui.label_3->setText(("2. " + nameString + " (ready)").c_str());
			}

			if (labelString3.erase(0, 3) == nameString) {
				ui.label_4->setText(("3. " + nameString + " (ready)").c_str());
			}

			if (labelString4.erase(0, 3) == nameString) {
				ui.label_5->setText(("4. " + nameString + " (ready)").c_str());
			}
		}
		r = cpr::Get(cpr::Url{ "http://localhost:18080/hasgamestarted" });

		std::this_thread::sleep_for(std::chrono::seconds(1));
	}
	canStart = true;
}

Lobby::Lobby(QWidget* parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

	QPalette palette = QPalette();

	palette.setColor(QPalette::Window, Qt::white);

	this->setAutoFillBackground(true);
	this->setPalette(palette);

	std::thread searchThread(&Lobby::searchForPlayers, this);
	searchThread.detach();

	std::thread readyThread(&Lobby::searchForReady, this);
	readyThread.detach();
}

Lobby::~Lobby()
{}

void Lobby::on_ReadyButton_clicked() {
	isReady = true;
	cpr::Response response = cpr::Get(cpr::Url{ "http://localhost:18080/ready/" + PlayerInfo::username});

	cpr::Response r = cpr::Get(cpr::Url{ "http://localhost:18080/hasgamestarted" });
	while (r.status_code == 400) {
		r = cpr::Get(cpr::Url{ "http://localhost:18080/hasgamestarted" });
		Sleep(200);
	}

	cpr::Response howMany = cpr::Get(cpr::Url{ "http://localhost:18080/getreadyplayers"});
	auto number = crow::json::load(howMany.text);
	int n = number["players"].size();

	hide();

	switch (n) {
	case 2:
		twoPlayersGameWindow = new twoPlayersGame();
		twoPlayersGameWindow->show();
		break;
	case 3:
		threePlayersGameWindow = new threePlayersGame();
		threePlayersGameWindow->show();
		break;
	case 4:
		fourPlayersGameWindow = new fourPlayersGame();
		fourPlayersGameWindow->show();
		break;
	default:
		break;
	}
	
	
}