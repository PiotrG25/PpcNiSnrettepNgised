
#ifndef BEHAVIORAL_COMMAND_PEPPERONI_PIZZA_HPP
#define BEHAVIORAL_COMMAND_PEPPERONI_PIZZA_HPP

#include "pizza.hpp"

class PepperoniPizza : public Pizza{
	public:
	PepperoniPizza(){
		toppings_.push_back(Pizza::Topping::SpicySalami);
		toppings_.push_back(Pizza::Topping::RedChiliFlakes);
		toppings_.push_back(Pizza::Topping::BlackOlives);
	}
};

#endif // BEHAVIORAL_COMMAND_PEPPERONI_PIZZA_HPP
