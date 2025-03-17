
#ifndef BEHAVIORAL_CHAIN_OF_RESPONSIBILITY_REQUEST_HPP
#define BEHAVIORAL_CHAIN_OF_RESPONSIBILITY_REQUEST_HPP

#include <string>

struct Request{
	Request(const std::string& login, const std::string& password){
		this->login = login;
		this->password = password;
	}
	std::string login;
	std::string password;
};

#endif // BEHAVIORAL_CHAIN_OF_RESPONSIBILITY_REQUEST_HPP