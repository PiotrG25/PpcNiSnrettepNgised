
#ifndef CREATIONAL_PIZZA_BUILDER_HPP
#define CREATIONAL_PIZZA_BUILDER_HPP

#include "pizza.hpp"
#include <memory>

class PizzaBuilder{
	public:
	PizzaBuilder();
	void MakeBase(Pizza::Size size, Pizza::Dough dough);
	virtual void MakePizza() = 0;
	std::unique_ptr<Pizza> build(Pizza::Size size, Pizza::Dough dough);
	
	protected:
	std::unique_ptr<Pizza> pizza_;
};

#endif // CREATIONAL_PIZZA_BUILDER_HPP
