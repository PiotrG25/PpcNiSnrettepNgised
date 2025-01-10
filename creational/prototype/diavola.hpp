
#ifndef CREATIONAL_PROTOTYPE_DIAVOLA_HPP
#define CREATIONAL_PROTOTYPE_DIAVOLA_HPP

#include "prototype_pizza.hpp"

class Diavola : public PrototypePizza{
	public:
	
	virtual std::unique_ptr<PrototypePizza> clone() const override{
		return std::make_unique<Diavola>(*this);
	}
	
	virtual Taste GetTaste() const override {
		return PrototypePizza::Taste::Good;
	}
};

#endif // CREATIONAL_PROTOTYPE_DIAVOLA_HPP
