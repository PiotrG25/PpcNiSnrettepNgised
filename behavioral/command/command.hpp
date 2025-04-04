
#ifndef BEHAVIORAL_COMMAND_COMMAND_HPP
#define BEHAVIORAL_COMMAND_COMMAND_HPP

#include <memory>
#include "pizza.hpp"
#include <iostream>

class Command{
	public:
	virtual std::shared_ptr<Pizza> Execute() = 0;
};

#endif // BEHAVIORAL_COMMAND_COMMAND_HPP