
#ifndef STRUCTURAL_PROXY_DATABASE_INTERFACE_HPP
#define STRUCTURAL_PROXY_DATABASE_INTERFACE_HPP

#include "user.hpp"
#include <vector>

class DatabaseInterface{
public:
	virtual std::vector<User> GetUsers() = 0;
	virtual std::vector<User> GetAdultUsers() = 0;
	virtual std::vector<User> GetJuvenileUsers() = 0;
	virtual void InsertUser(const User& user) = 0;
};

#endif STRUCTURAL_PROXY_DATABASE_INTERFACE_HPP
