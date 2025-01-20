
#ifndef STRUCTURAL_DECORATOR_CUSTOM_PIZZA_HPP
#define STRUCTURAL_DECORATOR_CUSTOM_PIZZA_HPP

#include "pizza.hpp"
#include <memory>

class CustomPizza : public Pizza{
	public:
	CustomPizza(std::unique_ptr<Pizza>&& pizza) : sub_pizza_(std::move(pizza)) {}
	
	protected:
	std::unique_ptr<Pizza> sub_pizza_;
};

#endif // STRUCTURAL_DECORATOR_CUSTOM_PIZZA_HPP
