
#include "user_database.hpp"
#include <unordered_map>

namespace{
	std::unordered_map<std::string, std::string> users = {
		{"login1", "$2a$04$Xb.0eOllNzYjTH7LShMQ.eCr/5to65Q.r6yWqctF1KZbCjd.Sfno6"},
		{"login2", "$2a$04$IIOTlculReyM2o4qWqMzgOofoXUq6.Yo/3H1bc//d4wI7PbMBz2Y6"}
	};
} // namespace

bool UserDatabase::IsUser(const std::string& login){
	auto it = users.find(login);
	return it != users.end();
}

std::string UserDatabase::GetPasswordHash(const std::string& login){
	auto it = users.find(login);
	return it->second;
}
