
#ifndef BEHAVIORAL_CHAIN_OF_RESPONSIBILITY_USER_DATABASE_HPP
#define BEHAVIORAL_CHAIN_OF_RESPONSIBILITY_USER_DATABASE_HPP

#include <string>

class UserDatabase{
	public:
	static bool IsUser(const std::string& login);
	static std::string GetPasswordHash(const std::string& login);
};

#endif // BEHAVIORAL_CHAIN_OF_RESPONSIBILITY_USER_DATABASE_HPP