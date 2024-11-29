
#ifndef CREATIONAL_VEGE_BUILDER_HPP
#define CREATIONAL_VEGE_BUILDER_HPP

#include "pizza_builder.hpp"

class VegeBuilder : public PizzaBuilder{
	public:
	virtual PizzaBuilder& AddSauce() override;
	virtual PizzaBuilder& AddCheese() override;
	virtual PizzaBuilder& AddToppings() override;
	virtual PizzaBuilder& SetTraits() override;
};

#endif // CREATIONAL_VEGE_BUILDER_HPP
