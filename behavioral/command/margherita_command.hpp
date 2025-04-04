
#ifndef BEHAVIORAL_COMMAND_MARGHERITA_COMMAND_HPP
#define BEHAVIORAL_COMMAND_MARGHERITA_COMMAND_HPP

#include "command.hpp"
#include "margherita_pizza.hpp"
#include <iostream>

class MargheritaCommand : public Command{
	public:
	virtual std::shared_ptr<Pizza> Execute() override{
		return std::make_shared<MargheritaPizza>();
	}
};

#endif // BEHAVIORAL_COMMAND_MARGHERITA_COMMAND_HPP