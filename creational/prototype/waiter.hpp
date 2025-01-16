
#ifndef CREATIONAL_PROTOTYPE_WAITER_HPP
#define CREATIONAL_PROTOTYPE_WAITER_HPP

#include "prototype_pizza.hpp"
#include <list>

class Waiter{
	public:
	std::shared_ptr<PrototypePizza> OrderDiavola();	
	std::shared_ptr<PrototypePizza> OrderVege();
	std::shared_ptr<PrototypePizza> OrderSameAsThePreviousPerson();
	
	private:
	std::list<std::shared_ptr<PrototypePizza>> orders_{};
};

#endif // CREATIONAL_PROTOTYPE_WAITER_HPP
