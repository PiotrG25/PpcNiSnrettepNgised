
#ifndef CREATIONAL_MARGHERITA_BUILDER_HPP
#define CREATIONAL_MARGHERITA_BUILDER_HPP

#include "pizza_builder.hpp"

class MargheritaBuilder : public PizzaBuilder{
	public:
	void MakePizza() override;
};

#endif // CREATIONAL_MARGHERITA_BUILDER_HPP
