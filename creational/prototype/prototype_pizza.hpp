
#ifndef CREATIONAL_PROTOTYPE_PROTOTYPE_PIZZA_HPP
#define CREATIONAL_PROTOTYPE_PROTOTYPE_PIZZA_HPP

#include <memory>

class PrototypePizza{
	public:
	enum class Taste{Good, Bad, No};
	
	virtual std::unique_ptr<PrototypePizza> clone() const = 0;
	virtual Taste GetTaste() const = 0;
};

#endif // CREATIONAL_PROTOTYPE_PROTOTYPE_PIZZA_HPP
