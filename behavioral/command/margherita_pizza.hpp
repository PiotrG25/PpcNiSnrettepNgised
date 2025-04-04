
#ifndef BEHAVIORAL_COMMAND_MARGHERITA_PIZZA_HPP
#define BEHAVIORAL_COMMAND_MARGHERITA_PIZZA_HPP

#include "pizza.hpp"

class MargheritaPizza : public Pizza{
	public:
	MargheritaPizza(){
		toppings_.push_back(Pizza::Topping::Basil);
		toppings_.push_back(Pizza::Topping::OliveOil);
	}
};

#endif // BEHAVIORAL_COMMAND_MARGHERITA_PIZZA_HPP
