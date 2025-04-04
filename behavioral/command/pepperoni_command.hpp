
#ifndef BEHAVIORAL_COMMAND_PEPPERONI_COMMAND_HPP
#define BEHAVIORAL_COMMAND_PEPPERONI_COMMAND_HPP

#include "command.hpp"
#include "pepperoni_pizza.hpp"
#include <iostream>

class PepperoniCommand : public Command{
	public:
	virtual std::shared_ptr<Pizza> Execute() override{
		return std::make_shared<PepperoniPizza>();
	}
};

#endif // BEHAVIORAL_COMMAND_PEPPERONI_COMMAND_HPP