
#ifndef BEHAVIORAL_CHAIN_OF_RESPONSIBILITY_HANDLER_INTERFACE_HPP
#define BEHAVIORAL_CHAIN_OF_RESPONSIBILITY_HANDLER_INTERFACE_HPP

#include "request.hpp"
#include "response_code.hpp"
#include <memory>

class HandlerInterface{
	public:
	virtual void setNext(std::unique_ptr<HandlerInterface>&& handler) = 0;
	virtual ResponseCode handle(const Request& request) = 0;
};

#endif // BEHAVIORAL_CHAIN_OF_RESPONSIBILITY_HANDLER_INTERFACE_HPP