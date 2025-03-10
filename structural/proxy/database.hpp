
#ifndef STRUCTURAL_PROXY_DATABASE_HPP
#define STRUCTURAL_PROXY_DATABASE_HPP

#include "database_interface.hpp"
#include <sqlite3.h>

class Database : public DatabaseInterface{
public:
	Database() = default;
	Database(const std::string& db_name){
		sqlite3_open(db_name.c_str(), &db);
	}
	virtual ~Database(){
		sqlite3_close(db);
	}
	
	virtual std::vector<User> GetUsers() override {
		std::vector<User> result;
		
		const char* sql = "SELECT id, name, age FROM user;";
		sqlite3_stmt* stmt;
		sqlite3_prepare_v2(db, sql, -1, &stmt, nullptr);
		while(sqlite3_step(stmt) == SQLITE_ROW){
			User user;
			user.id = sqlite3_column_int(stmt, 0);
			user.name = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 1));
			user.age = sqlite3_column_int(stmt, 2);
			result.push_back(user);
		}

		sqlite3_finalize(stmt);
		return result;
	}
	
	virtual std::vector<User> GetAdultUsers() override {
		std::vector<User> result;
		
		const char* sql = "SELECT id, name, age FROM user WHERE age >= 18;";
		sqlite3_stmt* stmt;
		sqlite3_prepare_v2(db, sql, -1, &stmt, nullptr);
		while(sqlite3_step(stmt) == SQLITE_ROW){
			User user;
			user.id = sqlite3_column_int(stmt, 0);
			user.name = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 1));
			user.age = sqlite3_column_int(stmt, 2);
			result.push_back(user);
		}

		sqlite3_finalize(stmt);
		return result;
	}
	
	virtual std::vector<User> GetJuvenileUsers() override {
		std::vector<User> result;
		
		const char* sql = "SELECT id, name, age FROM user WHERE age < 18;";
		sqlite3_stmt* stmt;
		sqlite3_prepare_v2(db, sql, -1, &stmt, nullptr);
		while(sqlite3_step(stmt) == SQLITE_ROW){
			User user;
			user.id = sqlite3_column_int(stmt, 0);
			user.name = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 1));
			user.age = sqlite3_column_int(stmt, 2);
			result.push_back(user);
		}

		sqlite3_finalize(stmt);
		return result;
	}
	
	virtual void InsertUser(const User& user) override {
		const char* sql = "INSERT INTO user (id, name, age) VALUES (?, ?, ?);";
		sqlite3_stmt* stmt;
		sqlite3_prepare_v2(db, sql, -1, &stmt, nullptr);

		sqlite3_bind_int(stmt, 1, user.id);
		sqlite3_bind_text(stmt, 2, user.name.c_str(), user.name.size(), SQLITE_STATIC);
		sqlite3_bind_int(stmt, 3, user.age);

		sqlite3_step(stmt);
		sqlite3_finalize(stmt);
	}
	
	void CreateTableIfNotExists(){
		char *errMsg;
		const char *createTableSQL = 
			"CREATE TABLE IF NOT EXISTS user ("
			"id INTEGER PRIMARY KEY AUTOINCREMENT, "
			"name TEXT NOT NULL, "
			"age INTEGER NOT NULL);";
		sqlite3_exec(db, createTableSQL, 0, 0, &errMsg);
	}
private:
	sqlite3 *db;
};

#endif STRUCTURAL_PROXY_DATABASE_HPP
