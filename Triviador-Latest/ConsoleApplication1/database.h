#pragma once
#include <string>

#include <crow.h>
#include <sqlite_orm/sqlite_orm.h>
namespace sql = sqlite_orm;

struct User {
	int id;
	std::string username;
	std::string password;
};

struct TerritoryTable {
	int id;
	int score;
};

struct GameTable {
	int id;
	int user_id;
	int user_color;
	int territory_id;
};

struct QuestionTable {
	int id;
	std::string question, a1, a2, a3, a4;
	int correctAnswer;
};

struct PlayerAnswer {
	int id;
	int player_id;
	int answer;
	int question_id;
};

struct PositionInput {
	int id;
	int player_id;
	int x;
	int y;
};

struct PlayerOrder {
	int id;
	std::string player_name;
};

inline auto createDatabase(const std::string& databaseName) {
	return sql::make_storage(
		databaseName,
		sql::make_table(
			"User",
			sql::make_column("id", &User::id, sql::autoincrement(), sql::primary_key()),
			sql::make_column("username", &User::username),
			sql::make_column("password", &User::password)
		),
		sql::make_table(
			"Territory",
			sql::make_column("id", &TerritoryTable::id, sql::autoincrement(), sql::primary_key()),
			sql::make_column("score", &TerritoryTable::score)
		),
		sql::make_table(
			"Game",
			sql::make_column("id", &GameTable::id, sql::autoincrement(), sql::primary_key()),
			sql::make_column("user_id", &GameTable::user_id),
			sql::make_column("user_color", &GameTable::user_color),
			sql::make_column("territory_id", &GameTable::territory_id),
			sql::foreign_key(&GameTable::user_id).references(&User::id),
			sql::foreign_key(&GameTable::territory_id).references(&TerritoryTable::id)
		),
		sql::make_table(
			"PlayerAnswer",
			sql::make_column("id", &PlayerAnswer::id, sql::autoincrement(), sql::primary_key()),
			sql::make_column("player_id", &PlayerAnswer::player_id),
			sql::make_column("answer", &PlayerAnswer::answer),
			sql::make_column("question_id", &PlayerAnswer::question_id),
			sql::foreign_key(&PlayerAnswer::question_id).references(&QuestionTable::id),
			sql::foreign_key(&PlayerAnswer::player_id).references(&User::id)
		),
		sql::make_table(
			"Questions",
			sql::make_column("id", &QuestionTable::id, sql::autoincrement(), sql::primary_key()),
			sql::make_column("question", &QuestionTable::question),
			sql::make_column("a1", &QuestionTable::a1),
			sql::make_column("a2", &QuestionTable::a2),
			sql::make_column("a3", &QuestionTable::a3),
			sql::make_column("a4", &QuestionTable::a4),
			sql::make_column("correctAnswer", &QuestionTable::correctAnswer)
		),
		sql::make_table(
			"PositionInput",
			sql::make_column("id", &PositionInput::id, sql::autoincrement(), sql::primary_key()),
			sql::make_column("player_id", &PositionInput::player_id),
			sql::make_column("x", &PositionInput::x),
			sql::make_column("y", &PositionInput::y),
			sql::foreign_key(&PositionInput::player_id).references(&User::id)
		),
		sql::make_table(
			"PlayerOrder",
			sql::make_column("id", &PlayerOrder::id, sql::primary_key(), sql::autoincrement()),
			sql::make_column("player_name", &PlayerOrder::player_name)
		)
	);
}

using Storage = decltype(createDatabase(""));

void defineTerritories(Storage& db);