
#ifndef CREATIONAL_PIZZA_BUILDER_HPP
#define CREATIONAL_PIZZA_BUILDER_HPP

#include "pizza.hpp"
#include <memory>

class PizzaBuilder{
	public:
	PizzaBuilder();
	
	PizzaBuilder& MakeBase(Pizza::Size size, Pizza::Dough dough);
	virtual PizzaBuilder& AddSauce() = 0;
	virtual PizzaBuilder& AddCheese() = 0;
	virtual PizzaBuilder& AddToppings() = 0;
	virtual PizzaBuilder& SetTraits();
	std::unique_ptr<Pizza> build();
	
	protected:
	std::unique_ptr<Pizza> pizza_;
};

#endif // CREATIONAL_PIZZA_BUILDER_HPP
