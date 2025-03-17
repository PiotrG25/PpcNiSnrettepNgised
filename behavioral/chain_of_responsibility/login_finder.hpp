
#ifndef BEHAVIORAL_CHAIN_OF_RESPONSIBILITY_LOGIN_FINDER_HPP
#define BEHAVIORAL_CHAIN_OF_RESPONSIBILITY_LOGIN_FINDER_HPP

#include "handler.hpp"

class LoginFinder : public Handler{
	public:
	virtual ResponseCode handle(const Request& request) override;
};

#endif // BEHAVIORAL_CHAIN_OF_RESPONSIBILITY_LOGIN_FINDER_HPP