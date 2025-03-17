
#ifndef BEHAVIORAL_CHAIN_OF_RESPONSIBILITY_PASSWORD_VERIFIER_HPP
#define BEHAVIORAL_CHAIN_OF_RESPONSIBILITY_PASSWORD_VERIFIER_HPP

#include "handler.hpp"
#include <functional>

class PasswordVerifier : public Handler{
	public:
	virtual ResponseCode handle(const Request& request) override;
};

#endif // BEHAVIORAL_CHAIN_OF_RESPONSIBILITY_PASSWORD_VERIFIER_HPP