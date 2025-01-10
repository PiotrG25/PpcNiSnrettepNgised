
#ifndef CREATIONAL_PROTOTYPE_UNDEFINED_PIZZA_HPP
#define CREATIONAL_PROTOTYPE_UNDEFINED_PIZZA_HPP

#include "prototype_pizza.hpp"

class UndefinedPizza : public PrototypePizza{
	public:
	
	virtual std::unique_ptr<PrototypePizza> clone() const override {
		return std::make_unique<UndefinedPizza>(*this);
	}
	
	virtual Taste GetTaste() const override {
		return PrototypePizza::Taste::No;
	}
};

#endif // CREATIONAL_PROTOTYPE_UNDEFINED_PIZZA_HPP
