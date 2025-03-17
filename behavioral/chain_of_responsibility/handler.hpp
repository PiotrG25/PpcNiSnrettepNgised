
#ifndef BEHAVIORAL_CHAIN_OF_RESPONSIBILITY_HANDLER_HPP
#define BEHAVIORAL_CHAIN_OF_RESPONSIBILITY_HANDLER_HPP

#include "handler_interface.hpp"

class Handler : public HandlerInterface{
	public:
	virtual void setNext(std::unique_ptr<HandlerInterface>&& handler) override{
		next = std::move(handler);
	}
	
	protected:
	std::unique_ptr<HandlerInterface> next{nullptr};
};

#endif // BEHAVIORAL_CHAIN_OF_RESPONSIBILITY_HANDLER_HPP