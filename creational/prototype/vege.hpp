
#ifndef CREATIONAL_PROTOTYPE_VEGE_HPP
#define CREATIONAL_PROTOTYPE_VEGE_HPP

#include "prototype_pizza.hpp"

class Vege : public PrototypePizza{
	public:
	
	virtual std::unique_ptr<PrototypePizza> clone() const override {
		return std::make_unique<Vege>(*this);
	}
	
	virtual Taste GetTaste() const override {
		return PrototypePizza::Taste::Bad;
	}
};

#endif // CREATIONAL_PROTOTYPE_VEGE_HPP
