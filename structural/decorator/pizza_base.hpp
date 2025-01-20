
#ifndef STRUCTURAL_DECORATOR_PIZZA_BASE_HPP
#define STRUCTURAL_DECORATOR_PIZZA_BASE_HPP

#include "pizza.hpp"

class PizzaBase : public Pizza{
	public:
	virtual int GetPrice() override {
		return 20;
	}
};

#endif // STRUCTURAL_DECORATOR_PIZZA_BASE_HPP
