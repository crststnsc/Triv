#pragma once
#include <string>

#include <crow.h>
#include <sqlite_orm/sqlite_orm.h>
namespace sql = sqlite_orm;

//user e pentru login 
//trebuie un tabel game care tine playerii jocului
//playerii sunt useri legati cu id
//trebuie un tabel cu intrebari


struct User {
	int id;
	std::string username;
	std::string password;
};

struct Territory {
	int id;
	int score;
};

struct Player {
	int id;
	std::string name;
	int idTerritory;
};

inline auto createDatabase(const std::string& databaseName) {
	return sql::make_storage(
		databaseName,
		sql::make_table(
			"Player",
			sql::make_column("id", &Player::id, sql::autoincrement(), sql::primary_key()),
			sql::make_column("name", &Player::name),
			sql::make_column("idTerritory", &Player::idTerritory)
		),
		sql::make_table(
			"Territory",
			sql::make_column("id", &Territory::id, sql::autoincrement(), sql::primary_key()),
			sql::make_column("score", &Territory::score)
		),
		sql::make_table(
			"User",
			sql::make_column("id", &User::id, sql::autoincrement(), sql::primary_key()),
			sql::make_column("username", &User::username),
			sql::make_column("password", &User::password)
			)
	);
}

using Storage = decltype(createDatabase(""));

void populateDatabase(Storage& database);