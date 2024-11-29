
#ifndef CREATIONAL_NAPOLI_BUILDER_HPP
#define CREATIONAL_NAPOLI_BUILDER_HPP

#include "pizza_builder.hpp"

class NapoliBuilder : public PizzaBuilder{
	public:
	virtual PizzaBuilder& AddSauce() override;
	virtual PizzaBuilder& AddCheese() override;
	virtual PizzaBuilder& AddToppings() override;
};

#endif // CREATIONAL_NAPOLI_BUILDER_HPP
