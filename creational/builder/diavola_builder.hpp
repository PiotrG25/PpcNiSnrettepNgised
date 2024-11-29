
#ifndef CREATIONAL_DIAVOLA_BUILDER_HPP
#define CREATIONAL_DIAVOLA_BUILDER_HPP

#include "pizza_builder.hpp"

class DiavolaBuilder : public PizzaBuilder{
	public:
	virtual PizzaBuilder& AddSauce() override;
	virtual PizzaBuilder& AddCheese() override;
	virtual PizzaBuilder& AddToppings() override;
};

#endif // CREATIONAL_DIAVOLA_BUILDER_HPP
