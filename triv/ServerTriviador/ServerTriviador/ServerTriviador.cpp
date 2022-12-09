#include <filesystem>
#include <iostream>

#include "database.h"

int main()
{
    const std::string dbName = "triviadordatabase.sqlite";
    Storage db = createDatabase(dbName);
    db.sync_schema();

    crow::SimpleApp app;

    CROW_ROUTE(app, "/")([]() {
        return "Nothing here.";
    });

    //add crow route to enable users to login
    CROW_ROUTE(app, "/login").methods(crow::HTTPMethod::POST)([&db](const crow::request& req) {
        auto x = crow::json::load(req.body);
        
        const auto& username = x["username"].s();
        const auto& password = x["password"].s();

        
	});
	
    CROW_ROUTE(app, "/addplayer/<string>")([&db](std::string name) {
        Player p;
        p.name = name;
        p.idTerritory = 0;

        db.insert(p);
        return crow::response(200);
    });

    auto& addPlayerPut = CROW_ROUTE(app, "/addplayer").methods(crow::HTTPMethod::PUT);
    addPlayerPut(Storage(db));


}


