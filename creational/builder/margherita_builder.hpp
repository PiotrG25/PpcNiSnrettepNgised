
#ifndef CREATIONAL_MARGHERITA_BUILDER_HPP
#define CREATIONAL_MARGHERITA_BUILDER_HPP

#include "pizza_builder.hpp"

class MargheritaBuilder : public PizzaBuilder{
	public:
	virtual PizzaBuilder& AddSauce() override;
	virtual PizzaBuilder& AddCheese() override;
	virtual PizzaBuilder& AddToppings() override;
};

#endif // CREATIONAL_MARGHERITA_BUILDER_HPP
