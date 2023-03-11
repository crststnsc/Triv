#include <iostream>
#include "database.h"
#include "Game.h"

int main()
{
	const std::string dbName = "database.sqlite";
	Storage db = createDatabase(dbName);
	db.sync_schema();
	db.remove_all<GameTable>();
	db.remove_all<PlayerAnswer>();

	std::vector<std::string> lobby;
	std::vector<std::string> ready;

	bool chooseBasePhase = false;

	if (db.count<TerritoryTable>() == 0) {
		defineTerritories(db);
	}

	crow::SimpleApp app;
	Game game;

	CROW_ROUTE(app, "/")([]() {
		return "Nothing here.";
		});

	CROW_ROUTE(app, "/getuserid/<string>")([&db](std::string username) {
		for (auto& i : db.iterate<User>()) {
			if (i.username == username) {
				crow::response response;
				response.write(std::to_string(i.id));
				return response;
			}
		}
		});

	CROW_ROUTE(app, "/login/<string>")([&db](const crow::request& req, std::string username) {
		std::string password = req.url_params.get("password");
	for (auto& user : db.iterate<User>()) {
		if (user.username == username && user.password == password) {
			crow::response r;
			r.write(std::to_string(user.id));
			return r;
		}
	}
	return crow::response(400);
		});

	CROW_ROUTE(app, "/register/<string>")([&db](const crow::request& req, std::string username) {
		std::string password = req.url_params.get("password");

	for (auto& user : db.iterate<User>())
		if (user.username == username) {
			return crow::response(400);
		}

	db.insert(User{ -1, username, password });
	return crow::response(200);
		});

	CROW_ROUTE(app, "/join/<string>")([&db, &lobby](std::string username) {
		int oldLength = lobby.size();
	lobby.push_back(username);
	if (lobby.size() > oldLength) {
		return crow::response(200);
	}
	return crow::response(400);
		});

	CROW_ROUTE(app, "/ready/<string>")([&ready, &lobby](std::string username) {
		int oldLength = ready.size();
	ready.push_back(username);
	if (ready.size() > oldLength) {
		return crow::response(200);
	}
	return crow::response(400);
		});

	CROW_ROUTE(app, "/getnumericquestion")([&db]() {
		auto q = db.get<QuestionTable>(1);
	return crow::json::wvalue{
		{"id", q.id},
		{"question", q.question},
		{"correctAnswer", q.correctAnswer}
	};
		});

	CROW_ROUTE(app, "/getmultipleanswerquestion")([&db]() {
		auto q = db.get<QuestionTable>(2);
	return crow::json::wvalue{
		{"id", q.id},
		{"question", q.question},
		{"answer1", q.a1},
		{"answer2", q.a2},
		{"answer3", q.a3},
		{"answer4", q.a4},
		{"correctAnswer", q.correctAnswer}
	};
		});

	CROW_ROUTE(app, "/giveanswer/<int>")([&db](const crow::request& req, int id) {
		std::string answer = req.url_params.get("answer");
	std::string questionId = req.url_params.get("questionId");
	db.insert(PlayerAnswer{ -1, id, std::stoi(answer), std::stoi(questionId) });
	return crow::response(200);
		});

	CROW_ROUTE(app, "/giveposition/<int>")([&db](const crow::request& req, int id) {
		std::string x = req.url_params.get("x");
	std::string y = req.url_params.get("y");
	db.insert(PositionInput{ -1, id, std::stoi(x), std::stoi(y) });
	return crow::response(200);
		});

	CROW_ROUTE(app, "/getplayernames")([&lobby] {
		std::vector<crow::json::wvalue> playerNames;
	for (auto& name : lobby) {
		playerNames.push_back(crow::json::wvalue{ {"name", name} });
	}
	return crow::json::wvalue{ {"players", playerNames} };
		});

	CROW_ROUTE(app, "/getreadyplayers")([&ready] {
		std::vector<crow::json::wvalue> readyPlayers;
	for (auto& name : ready) {
		readyPlayers.push_back(crow::json::wvalue{ {"name", name} });
	}
	return crow::json::wvalue{ {"players", readyPlayers} };
		});

	CROW_ROUTE(app, "/hasgamestarted")([&lobby, &ready, &db, &game] {
		if (ready.size() == lobby.size()) {
			//game = StartGame(db, lobby);
			crow::response r;
			r.write(std::to_string(lobby.size()));
			return r;
		}
	return crow::response(400);
		});

	CROW_ROUTE(app, "/choosebase")([&] {
		if (!chooseBasePhase) {
			game.ChooseBasePhase(db);
			chooseBasePhase = true;
		}
	return "";
		});

	CROW_ROUTE(app, "/getorder")([&] {
		std::vector<crow::json::wvalue> names;
	for (auto& player : db.iterate<PlayerOrder>()) {
		names.push_back(crow::json::wvalue{ {"name", player.player_name} });
	}
	return crow::json::wvalue{ {"playerOrder", names} };
		});

	app.port(18080).multithreaded().run();
}