
#ifndef CREATIONAL_DIAVOLA_BUILDER_HPP
#define CREATIONAL_DIAVOLA_BUILDER_HPP

#include "pizza_builder.hpp"

class DiavolaBuilder : public PizzaBuilder{
	public:
	void MakePizza() override;
};

#endif // CREATIONAL_DIAVOLA_BUILDER_HPP
